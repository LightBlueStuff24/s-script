#include "include/sscript.h"
#include <stdio.h>
#include <ctype.h>


int main(int argc, char* argv[]) {
  
  if(argc < 2) {
    printf("please input a file");
  }
  ss_compile_file(argv[1]);
  return 0;
}