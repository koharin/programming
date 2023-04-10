CREATE OR REPLACE FUNCTION Date2EnrollYear (dDate IN DATE)
        RETURN NUMBER
IS
        cYear NUMBER;
        cMonth NUMBER;
BEGIN
        SELECT TO_NUMBER(TO_CHAR(dDATE, 'YYYY'))
        INTO cYear
        FROM DUAL;
				-- 입력 받은 날짜의 year만 숫자로 입력 받아 cYear에 추가

        SELECT TO_NUMBER(TO_CHAR(dDATE, 'MM'))
        INTO cMonth
        FROM DUAL;
				-- 입력 받은 날짜의 month만 숫자로 입력 받아 cMonth에 추가

        IF (cMonth > 10) THEN
                cYear := cYear+1;
        END IF;
				-- 11월부터는 다음 학기로 넘어가기 때문에 year를 수정

        RETURN cYear;
END;
/

CREATE OR REPLACE FUNCTION Date2EnrollSemester (dDate In DATE)
        RETURN NUMBER
IS
        cSemester NUMBER;
        cMonth NUMBER;
BEGIN
        SELECT TO_NUMBER(TO_CHAR(dDATE, 'MM'))
        INTO cMonth
        FROM DUAL;
				-- 입력 받은 날짜의 month만 숫자로 입력 받아 cMonth에 추가

        if (cMonth < 5) THEN
                cSemester := 1;
				-- 1월부터 4월까지는 1학기
        ELSE
                cSemester := 2;
				-- 그 외에는 2학기
        END IF;

        RETURN cSemester;
END;
/
