CREATE OR REPLACE PROCEDURE SelectTimeTable(
        sStudentId IN ENROLL.s_id%TYPE,
        nYear IN ENROLL.e_year%TYPE,
        nSemester IN ENROLL.e_semester%TYPE,

        c_cursor OUT SYS_REFCURSOR
)
IS
BEGIN
	-- 커서에 s_id와 지정한 학기, 년도에 대한 컬럼 조회 결과 받아온다.
	OPEN c_cursor FOR
    SELECT E.c_id, C.c_name, E.c_id_no, C.c_unit, T.t_name, T.t_time, C.c_place
    FROM TEACH T
    INNER JOIN ENROLL E
    ON T.c_id = E.c_id AND T.c_id_no = E.c_id_no
    INNER JOIN COURSE C
    ON E.c_id = C.c_id AND E.c_id_no = C.c_id_no
    WHERE s_id = sStudentId AND E.e_year = nYear AND E.e_semester = nSemester; 
EXCEPTION
        WHEN OTHERS THEN
            DBMS_OUTPUT.PUT_LINE('에러: '||SQLERRM);
END;
/
