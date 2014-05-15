
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include "parser.h"

char operators[] = { '+', '-', '/', '*', '^' };

int isOperator(char c)
{
  for (int i = 0; i < sizeof(operators) / sizeof(char); i++) {
    if (c == operators[i])
      return 1;
  }

  return 0;
}

int applyOperator(double left, double right, char operator, double* res)
{
  if (!isOperator(operator)) {
    return -1;
  }

  switch (operator) {
    case '+':
      *res = left + right;
      break;
    case '-':
      *res = left - right;
      break;
    case '/':
      *res = left / right;
      break;
    case '*':
      *res = left * right;
      break;
    case '^':
      *res = pow(left, right);
      break;
  }

  return 0;
}

int parse(char* in, int len, double* result)
{
  int pos2 = 0; // second offset index
  int number = 0; // 0 for first number, 1 for second number
  char first[10] = {0}, second[10] = {0};
  char operator;

  for (int i = 0; i < len; i++) {
    if (isOperator(in[i])) {
      operator = in[i];
      pos2 = i + 1; // second number starts here
      number++; 
      continue;
    }
    if (number == 0) {
      first[i] = in[i];
    } else if (number == 1) {
      second[i - pos2] = in[i];
    }
  }

  // Check if each number is valid
  for (int i = 0; i < 10; i++) {
    if ((isalpha(first[i]) || isalpha(second[i]))
        && first[i] != 'e' && second[i] != 'e')
    {
      return -1;
    }
  }

  applyOperator(atof(first), atof(second), operator, result);

  return 0;
}
