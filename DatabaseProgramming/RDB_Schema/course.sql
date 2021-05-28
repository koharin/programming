CREATE TABLE COURSE(
        c_id VARCHAR2(10),
        c_name VARCHAR2(40) NOT NULL,
        c_id_no NUMBER(1),
        c_unit NUMBER(1) NOT NULL,
        t_name VARCHAR2(10) NOT NULL,
				c_place VARCHAR2(20) NOT NULL,
        foreign key (c_id, c_id_no) REFERENCES teach (c_id, c_id_no)
);

INSERT INTO COURSE VALUES ('M100', '데이터베이스프로그래밍', 1, 3, '심준호', '명신관401');
INSERT INTO COURSE VALUES ('M100', '데이터베이스프로그래밍', 2, 3, '심준호', '명신관401');
INSERT INTO COURSE VALUES ('P100', '시스템종합설계', 1, 3, '박숙영', '명신관402');
INSERT INTO COURSE VALUES ('C200', '인공지능', 1, 3, '채희준', '명신관403');
INSERT INTO COURSE VALUES ('M300', '데이터마이닝분석',1,3,'이기용', '프라임관301');
INSERT INTO COURSE VALUES ('C100', '운영체제', 1, 3, '김주균', '명신관404');
INSERT INTO COURSE VALUES ('M400', '소프트웨어의이해', 1, 3,'문봉희', '명신관405');
INSERT INTO COURSE VALUES ('M400', '소프트웨어의이해', 2, 3,'이광수', '명신관406');
INSERT INTO COURSE VALUES ('M400', '소프트웨어의이해', 3, 3, '정영주', '명신관301');
INSERT INTO COURSE VALUES ('M500', '컴퓨터그래픽스', 1, 3, '유석종', '명신관302');
INSERT INTO COURSE VALUES ('C300', '컴퓨터구조', 1, 3, '문봉희', '명신관303');
INSERT INTO COURSE VALUES ('C300', '컴퓨터구조', 2, 3, '문봉희', '명신관303');
INSERT INTO COURSE VALUES ('M600', '컴파일러', 1, 3, '박영훈', '명신관305');
INSERT INTO COURSE VALUES ('C400', '컴퓨터특강', 1, 3, '김윤진', '명신관306');
INSERT INTO COURSE VALUES ('M700', '윈도우프로그래밍', 1, 3, '이광수', '명신관407');
INSERT INTO COURSE VALUES ('M700', '윈도우프로그래밍', 2, 3, '이광수', '명신관407');
