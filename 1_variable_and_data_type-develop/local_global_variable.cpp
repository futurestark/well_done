#include <stdio.h>

// глобальная переменная
int global_variable = 200;
// глобльная переменная с тем же именем как и локальная
int a = 300;

// статическая переменая
static int  variable = 10;
namespace {
  // такой же смысл как переменая variable
  int variable_unnamed = 20;
}

int main(int argc, char const *argv[])
{
  int a = 10;
  {
    int a = 20;
    printf("a = %d\n", a);
    printf("variable in unnamed scope = %d\n", variable);
    printf("global variable in unnamed scope = %d\n", global_variable);
    variable = 50;
    printf("get access to global variable = %d\n", ::a);
  }
  // получим ошибку компиляции redeclaration of ‘int a’
  // int a = 40;
  printf("a = %d\n", a);
  printf("variable in main scope = %d\n", variable);
  printf("variable form unnamed namespace = %d\n", variable_unnamed);
  printf("global variable in main scope = %d\n", global_variable);
  return 0;
}
