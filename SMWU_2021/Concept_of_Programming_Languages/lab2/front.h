#ifndef FRONT_H
#define FRONT_H

/* Character classes */
#define LETTER 0
#define DIGIT 1
#define UNKNOWN 99

/* Token codes */
#define INT_LIT 10
#define IDENT 11
#define ASSIGN_OP 20
#define ADD_OP 21
#define SUB_OP 22
#define MULT_OP 23
#define DIV_OP 24
#define LEFT_PAREN 25
#define RIGHT_PAREN 26

// Add ==, !=, <, >, !, &&, || Token codes 
#define EQ_OP 30
#define NEQ_OP 31
#define SMALL_OP 32
#define BIG_OP 33 
#define NOT_OP 50
#define AND_OP 51
#define OR_OP 52



int lex();

#endif