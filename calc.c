
#include <stdio.h>

#include "calc.h"
#include "parser.h"
#include "utils.h"


int main(int argc, char *argv[])
{
  char cmd[CMD_LEN] = { 0 };

  while (1) { // main loop
    printf("> "); // prompt

    fgets(cmd, CMD_LEN, stdin);

    double result;
    
    if (parse(cmd, len(cmd), &result) == -1) {
      printf("Please enter a valid expression\n\n");
    }

    printf("%g\n", result);
  }

  return 0;
}

