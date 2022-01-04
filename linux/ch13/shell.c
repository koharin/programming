//Lab13_002_컴퓨터과학_1812648_정지우
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
#define MAXARG 7

int main(){
	char buf[256], *args[MAXARG], *save, *token;
	int argn, child, status, pid;
	static const char delim[] = " \t\n"; // 공백, 탭, 개행으로 이루어진

	while(1){ // 무한반복
		printf("[shell] ");
		gets(buf);
		argn=0;
		
		//문자열에서 delim을 기준으로 단어를 잘라냄
		//strtok_r과 while문 사용. argn을 증가시키며 args 배열에 잘라낸 명령줄 인수를 넣는다.
		token = strtok_r(buf, delim, &save);
		while(token){
			args[argn++] = token;
			token = strtok_r(NULL, delim, &save);
		}
		//인수가 더 없음을 의미하는 문자 추가
		args[argn] = (char*)0;
		
		if(argn == 0) continue; // 명령어가 없으면 루프 계속
		if(!strcmp(args[0], "quit")) break; //프롬프트로 입력받은 단어가 "quit"이면 while문을 벗어남
		if(!strcmp(args[argn-1],"&")){ // args 배열 마지막 원소가 &이면 후면처리	
			args[argn-1] = (char*)0;
			if((pid=fork()) == -1) perror("fork failed");
			if(pid == 0){ execvp(args[0], args); } 
		}
		else{ //아니면 전면처리
			
			if((pid=fork()) == -1) perror("fork failed");
			if(pid != 0){ child = waitpid(pid, &status, 0); }	
			else{ execvp(args[0], args); }
		}
		
	}
	exit(0);
}
