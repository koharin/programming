CREATE OR REPLACE TRIGGER BeforeUpdateStudent BEFORE
UPDATE ON students
FOR EACH ROW
DECLARE
-- 사용자 정의 exception 선언
underflow_length EXCEPTION;
invalid_value EXCEPTION;
nLength NUMBER; -- 패스워드 길이
i NUMBER; -- 루프 변수
BEGIN
nLength:=LENGTH(:new.s_pwd);
IF nLength<4 THEN
RAISE underflow_length;
END IF;
-- 패스워드 한 문자마다 공백과 비교
for i in 1..nLength Loop
IF substr(:new.s_pwd,i,1)=' ' then
RAISE invalid_value;
end if;
end loop;
EXCEPTION
WHEN underflow_length THEN
RAISE_APPLICATION_ERROR(-20002,'글자수부족');
WHEN invalid_value THEN
RAISE_APPLICATION_ERROR(-20003,'띄어쓰기포함');
END;
/
