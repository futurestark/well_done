#include <cstdio>

int main(int argc, char const *argv[]) {
  printf("is even %d\n", 4 % 2);
  printf("is even %d\n", 5 % 2);
  printf("is even %d\n", 10 % 2);

  printf("Last digit number 2345 is %d\n", 2345 % 10);
  printf("Last two digit number 2345 is %d\n", 2345 % 100);
  return 0;
}
