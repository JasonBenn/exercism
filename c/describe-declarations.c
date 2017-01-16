#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100
#define BUFSIZE 100

enum { NAME, PARENS, BRACKETS };

void dcl(void);
void dirdcl(void);
int gettoken(void);
int tokentype; // type of last token
char token[MAXTOKEN]; // last token string
char name [MAXTOKEN]; // identifier name
char datatype[MAXTOKEN]; // data type = char, int, etc
char out[1000]; // output string


// dcl: parse a declarator
void dcl(void) {
    int ns;

    for (ns = 0; gettoken() == '*'; ) // Count *'s
        ns++;
    dirdcl();
    while(ns-- > 0)
        strcat(out, " pointer to");
}

// dirdcl: parse a direct declarator
void dirdcl(void) {
    int type;

    if (tokentype == '(') {  // (dcl)
        dcl();
        if (tokentype != ')')
            printf("error: missing )\n");
    } else if (tokentype == NAME)  // variable name
        strcpy(name, token);
    else
        printf("error: expected name or (dcl)\n");
    while ((type=gettoken()) == PARENS || type == BRACKETS)
        if (type == PARENS)
            strcat(out, " function returning");
        else {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
}

char buf[BUFSIZE]; // buffer for ungetch
int bufp = 0; // next free position in buf

// Get a (possibly pushed-back) char
int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

// Push char back onto input
void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

/*
 * The function gettoken skips blanks and tabs, then finds the next toekn in the input; a "token" is a name, a pair
 * of parens, a pair of brackets perhaps including a number, or any other single char.
 */
int gettoken(void) {
    int c, getch(void);
    void ungetch(int);
    char *p = token;

    while ((c = getch()) == ' ' || c == '\t')
        ;
    if (c == '(') {
        if ((c = getch()) == ')') {
            strcpy(token, "()");
            return tokentype = PARENS;
        } else {
            ungetch(c);
            return tokentype = '(';
        }
    } else if (c == '[') {
        for (*p++ = c; (*p++ = getch()) != ']'; )
            ;
        *p = '\0';
        return tokentype = BRACKETS;
    } else if (isalpha(c)) {
        for (*p++ = c; isalnum(*p++ = getch()); )
            ;
        *p = '\0';
        printf("found alpha chars. token: %s", token);
        ungetch(c);
        return tokentype = NAME;
    } else {
        return tokentype = c;
    }
}

int main(void) {
    while (gettoken() != EOF) { // 1st token on line
        strcpy(datatype, token); // is the datatype
        out[0] = '\0';
        dcl();
        if (tokentype != '\n')
            printf("syntax error\n");
        printf("%s: %s %s\n", name, out, datatype);
    }
    return 0;
}
