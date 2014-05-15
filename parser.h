#ifndef PARSER_H
#define PARSER_H


/*
 * int isOperator(char c);
 *
 * returns 1 if c is operator
 * returns 0 if c not operator
 */
int isOperator(char c);

/*
 * returns 0 on success
 * returns -1 if operator is not an operator
 */
int applyOperator(double left, double right, char operator, double* res);


int parse(char* in, int len, double* result);

#endif
