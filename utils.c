#include <string.h>
#include "utils.h"


size_t len(char* s) 
{
  if (s == NULL)
    return 0;

  char* offset = s;

  while (*s++ != '\0');
  return s - offset - 1;
}
