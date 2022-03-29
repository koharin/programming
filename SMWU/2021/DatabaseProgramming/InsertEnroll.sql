CREATE OR REPLACE PROCEDURE InsertEnroll (
   sStudentId IN VARCHAR2,
   sCourseId IN VARCHAR2,
   nCourseIdNo IN NUMBER,
   result OUT VARCHAR2
)

IS

too_many_sumCourseUnit   EXCEPTION; -- 에러 처리1
too_many_courses   ExCEPTION; -- 에러 처리2
too_many_students   EXCEPTION; -- 에러 처리3
duplicate_time      EXCEPTION; -- 에러 처리4

nSumCourseUnit      NUMBER;
nCourseUnit      NUMBER;
nCnt         NUMBER;
e_teach TEACH%ROWTYPE; -- teach 테이블의 레코드

CURSOR C_LIST(sCourseId COURSE.c_id%TYPE, nCourseIdNo COURSE.c_id_no%TYPE) IS
   SELECT c_unit
   FROM course
   WHERE c_id = sCourseId AND c_id_no = nCourseIdNo;
-- course id와 course id no가 같은 레고드의 c_unit 조회

BEGIN
   result := '';

   DBMS_OUTPUT.PUT_LINE('#');
   DBMS_OUTPUT.PUT_LINE(sStudentId||'님이 과목번호'||sCourseId||', 분반'||TO_CHAR(
nCourseIdNo)||'의 수강 등록을 요청하였습니다.');


   e_teach.t_year := Date2EnrollYear(SYSDATE);
   e_teach.t_semester := Date2EnrollSemester(SYSDATE);

   /* 에러처리1: 최대 학점 초과 여부 */
   SELECT SUM(c.c_unit)
   INTO nSumCourseUnit
   FROM course c, enroll e
   WHERE e.s_id = sStudentId AND e.e_year = e_teach.t_year AND
      e.e_semester = e_teach.t_semester AND e.c_id = c.c_id AND e.c_id_no = c.c_id_no;
-- 현재 학생이 신청한 과목들의 학점 받아옴

   OPEN C_LIST(sCourseId, nCourseIdNo);
   FETCH C_LIST INTO nCourseUnit;
-- 프로시저가 입력 받은 course id, course id no로 파라미터 있는 커서 실행하여
-- 해당 과목의 course unit 값 받아옴

   IF (nSumCourseUnit + nCourseUnit > 18) THEN
      RAISE too_many_sumCourseUnit;
   END IF;
-- 신청한 과목의 학점과 학생이 기존에 신청한 과목들의 학점의 합을 확인하여 최대 학점을 초과했으면 에러

   CLOSE C_LIST;

   /* 에러처리2: 동일한 과목 신청 여부 */
   SELECT COUNT(*)
   INTO nCnt
   FROM enroll
   WHERE s_id = sStudentId AND c_id = sCourseId;
-- 그 학생이 신청한 과목이 이미 enroll 테이블에 존재하는 지 확인

   IF (nCnt > 0) THEN
      RAISE too_many_courses;
   END IF;
-- 만약 이미 테이블에 존재한다면 동일 과목 신청했으므로 에러

   /* 에러처리3: 수강신청 인원 초과 여부 */
   SELECT t_max
   INTO e_teach.t_max
   FROM teach
   WHERE t_year = e_teach.t_year AND t_semester = e_teach.t_semester
   AND c_id = sCourseId AND c_id_no = nCourseIdNo;
-- 신청한 과목의 최대 학생 수 확인

   SELECT COUNT(*)
   INTO nCnt
   FROM enroll
   WHERE e_year = e_teach.t_year AND e_semester = e_teach.t_semester
      AND c_id = sCourseId AND c_id_no = nCourseIdNo;
-- 그 과목을 현재 신청한 학생의 수 확인

   IF (nCnt >= e_teach.t_max) THEN
      RAISE too_many_students;
   END IF;
-- 최대 학생수보다 현재 신청한 학생 수가 같거나 많다면 새로 신청한 학생은 신청할 수 없으므로 에러

   /* 에러처리4: 신청한 과목들 시간 중복 여부 */
   SELECT COUNT(*)
   INTO nCnt
   FROM (
      SELECT t_time
      FROM teach
      WHERE t_year = e_teach.t_year AND t_semester = e_teach.t_semester
         AND c_id = sCourseId AND c_id_no = nCourseIdNo
-- 새로 신청한 과목의 시간 확인

      INTERSECT
-- 교집합

      SELECT t.t_time
      FROM teach t, enroll e
      WHERE e.s_id = sStudentId AND  e.e_year = e_teach.t_year
         AND e.e_semester = e_teach.t_semester AND t.t_year = e_teach.t_year
         AND t.t_semester = e_teach.t_semester AND e.c_id = t.c_id
         AND e.c_id_no = t.c_id_no
-- 대상 학생이 신청한 과목들의 시간 확인
   );

   IF (nCnt > 0) THEN
      RAISE duplicate_time;
   END IF;
-- 만약 동일한 시간의 과목이 있다면 에러

   /* 수강신청 등록 */
   INSERT INTO enroll(S_ID, C_ID, C_ID_NO, E_YEAR, E_SEMESTER)
   VALUES (sStudentId, sCourseID, nCourseIdNo, e_teach.t_year, e_teach.t_semester);

   -- COMMIT;

   RESULT := '수강신청 등록이 완료되었습니다';

EXCEPTION
   WHEN too_many_sumCourseUnit THEN
      result := '최대학점을 초과하였습니다';
   WHEN too_many_courses THEN
      result := '이미 등록된 과목을 신청하였습니다';
   WHEN too_many_students THEN
      result := '수강신청 인원이 초과되어 등록이 불가능합니다';
   WHEN duplicate_time THEN
      result := '이미 등록된 과목 중 중복되는 시간이 존재합니다';
   WHEN OTHERS THEN
      ROLLBACK;
      result := SQLCODE;
END;
/
