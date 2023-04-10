/**
 * This the example lexical analyzer code in pages 173 - 177 of the
 * textbook,
 *
 * Sebesta, R. W. (2012). Concepts of Programming Languages. 
 * Pearson, 10th edition.
 *
 */

/* front.c - a lexical analyzer system for simple arithmetic expressions */
#include <stdio.h>
#include <ctype.h>

#include "front.h"
#include "parser.h"

/* Global Variable */
int nextToken;

/* Local Variables */
static int charClass;
static char lexeme [100];
static char nextChar;
static int lexLen;
static FILE *in_fp;

/* Local Function declarations */
static void addChar();
static void getChar(); 
static void getNonBlank();

/******************************************************/
/* main driver */
int main() 
{
    /* Open the input data file and process its contents */
    if ((in_fp = fopen("front.in", "r")) == NULL) {
        printf("ERROR - cannot open front.in \n");
    } else {
        getChar();
        do {
            lex();
            expr();
        } while (nextToken != EOF);
    }
	getchar();
    return 0;
}

/*****************************************************/
/* lookup - a function to lookup operators and parentheses and return the 
 * token */
static int lookup(char ch) {
    switch (ch) {
        case '(':
            addChar();
            nextToken = LEFT_PAREN;
            break;
        case ')':
            addChar();
            nextToken = RIGHT_PAREN;
            break;
        case '+':
            addChar();
            nextToken = ADD_OP;
            break;
        case '-':
            addChar();
            nextToken = SUB_OP;
            break;
        case '*':
            addChar();
            nextToken = MULT_OP;
            break;
        case '/':
            addChar();
            nextToken = DIV_OP;
            break;
        case '<':
            addChar();
            nextToken = SMALL_OP;
            break;
        case '>':
            addChar();
            nextToken = BIG_OP;
            break;
        case '&':
            addChar();
            getChar(); addChar(); // &&의 경우 두 개의 토큰을 가지므로 getChar(), addChar()로 lexeme에 &&을 넣도록 함
            nextToken = AND_OP;
            break;
        case '=':
            addChar();
            getChar(); addChar(); // ==의 경우 두 개의 토큰을 가지므로 getChar(), addChar()로 lexeme에 ==을 넣도록 함
            nextToken = EQ_OP;
            break;
        case '|':
            addChar();
            getChar(); addChar(); // ||의 경우 두 개의 토큰을 가지므로 getChar(), addChar()로 lexeme에 ||을 넣도록 함
            nextToken = OR_OP;
            break;
        case '!':
            addChar(); getChar();
            if(nextChar == '=') { addChar(); nextToken = NEQ_OP; } // != 연산자에서 =가 !와 같이 lexeme에 들어가도록 addChar() 호출
            else nextToken = NOT_OP; // ! 연산자의 경우, 다음 토큰에 대한 연산 수행하도록 nextToken만 지정해준다.
            break;
        default:
            addChar();
            nextToken = EOF;
            break;
    }
    return nextToken;
}

/*****************************************************/
/* addChar - a function to add nextChar to lexeme */
static void addChar() {
    if (lexLen <= 98) {
        lexeme[lexLen++] = nextChar;
        lexeme[lexLen] = 0;
    } else {
        printf("Error - lexeme is too long \n");
    }
}

/*****************************************************/
/* getChar - a function to get the next character of input and determine its 
 * character class */
static void getChar() {
    if ((nextChar = getc(in_fp)) != EOF) {
        if (isalpha(nextChar))
            charClass = LETTER;
        else if (isdigit(nextChar))
            charClass = DIGIT;
        else charClass = UNKNOWN;
    } else {
        charClass = EOF;
    }
}

/*****************************************************/
/* getNonBlank - a function to call getChar until it returns a non-whitespace 
 * character */
static void getNonBlank() {
    while (isspace(nextChar)) getChar();
}

/*****************************************************/
/* lex - a simple lexical analyzer for arithmetic expressions */
int lex() {
    lexLen = 0;
    getNonBlank();

    switch (charClass) {
        /* Parse identifiers */
        case LETTER:
            addChar();
            getChar();
            while (charClass == LETTER || charClass == DIGIT) {
                addChar();
                getChar();
            }
            nextToken = IDENT;
            break;

        /* Parse integer literals */
        case DIGIT:
            addChar();
            getChar();
            while (charClass == DIGIT) {
                addChar();
                getChar();
            }
            nextToken = INT_LIT;
            break;

        /* Parentheses and operators */
        case UNKNOWN:
            if(nextChar == '!') { 
                lookup(nextChar);
                if(nextChar == '=') getChar(); // !=의 경우 lookup() 함수에서 리턴 이후 nextChar로 =을 가지는데 이것에 대한 연산은 필요 없으므로 다음 토큰을 입력받는다.
                // !인 경우 lookup() 함수에서 getChar()로 받은 nextChar에 대한 연산으로 다음으로 수행한다.
            }
            else{ 
                lookup(nextChar);
                getChar();
            }
            break;

        /* EOF */
        case EOF:
            nextToken = EOF;
            lexeme[0] = 'E';
            lexeme[1] = 'O';
            lexeme[2] = 'F';
            lexeme[3] = 0;
            break;
    } /* End of switch */

    printf("Next token is: %d, Next lexeme is %s\n", nextToken, lexeme);
    return nextToken;
} /* End of function lex */
