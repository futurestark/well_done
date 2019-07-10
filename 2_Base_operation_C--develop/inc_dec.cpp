#include <cstdio>

int main(int argc, char const *argv[]) {
  size_t value = 0;
  printf("x = %zu\n", value);
  ++value;
  // напечатает 1
  printf("x = %zu\n", value);
  // напечатает 2
  printf("x = %zu\n", ++value);
  // напечатает 2
  printf("x = %zu\n", value);
  // напечатает 4
  printf("x = %zu\n", ++++value);
  // напечатает 4
  printf("x = %zu\n", value++);
  // напечатает 5
  printf("x = %zu\n", value);
  // напечатает 4
  printf("x = %zu\n", --value);
  // напечатает 4
  printf("x = %zu\n", value--);

  // напечатает 3
  printf("x = %zu\n", value);

  // тут маса вариантов
  ++value = value++;

  // будет 3
  printf("x = %zu\n", value);
  /*
    value++, возращает 3, и увеличивает value на 1
    value == 4, уверличивает value на 1 и присваивает ему 3
    такое поведение компилятором есть неопределенное, и не стоит так писать
  */

  // напечатает 14, operation on ‘value’ may be undefined
  auto value2 = (++value * 2) + (value++ + 2);

  printf("x = %zu\n", value2);

  // будет ошибка компиляции
  // value2++ = value;
  // с С++17 это являеться устаревшим
  bool flag = true;
  ++flag;
  printf("x = %d\n", flag);
  // а такое запрещено
  // printf("x = %d\n", --flag);
  return 0;
}
