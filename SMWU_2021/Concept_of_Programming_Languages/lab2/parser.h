#ifndef PARSER_H
#define PARSER_H

void expr();
void term();
void factor();

// aexp(), rexp() 함수 선언 코드 추가
void aexp();
void rexp();

extern int nextToken;
#endif