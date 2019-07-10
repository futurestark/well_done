#include <cstdio>

int main(int argc, char const *argv[]) {
  unsigned number = 12345;
  printf("Summ of number %d ====> ", number);
  // необходима инициализация нулем
  long long summ = 0;
  while (number != 0) {
    summ += number % 10;
    // отбрасываем последнюю цифру
    number /= 10;
  }
  printf("%lld\n", summ);
  return 0;
}
