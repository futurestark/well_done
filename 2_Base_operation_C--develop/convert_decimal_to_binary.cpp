#include <cstdio>
#include <bitset>

int main(int argc, char const *argv[]) {
  unsigned number = 28;
  printf("Binary representation %d is =======> ", number);
  // выводит в обратном порядке
  while (number != 0) {
    printf("%d ", number % 2);
    number /= 2;
  }
  printf("\n");

  std::bitset<8> b(28);
  printf("Check using bitset class %s\n", b.to_string().c_str());
  return 0;
}
