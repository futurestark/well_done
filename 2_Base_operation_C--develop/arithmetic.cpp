#include <cstdio>
#include <cstdint>
#include <limits>
#include <iostream>

void work_with_operator_plus() {
  // объявляем переменную
  uint16_t value;
  // сложение двух rvalue
  value = 30 + 50;
  printf("value = %d\n", value);

  /*
   совмещение объявления и инициализации с использование оператора +
   тут используеться микс, т.е. в качестве операндов может быть как lvalue + rvalue
   или наоборот rvalue + lvalue
  */
  uint16_t value2 = value + 90;
  printf("value2 = %d\n", value2);

  // используеться как lvalue + lvalue
  uint16_t value3 = value +  value2;
  printf("value3 = %d\n", value3);

  // пример где в качестве операнда может быть значение результата присвоения
  uint16_t value4 = 200 + (value = value3);
  printf("value3 = %d\n", value4);

  // будет ошибка компиляции, попытка rvalue(временной переменной) присвоить значение 
  // (value + 300) = value4;

  /*
   ошибка, так как оператор +, в бинарном виде должен иметь два операнда, т.е. суть в том что компилятор ожидает полное выражение
  */
  // uint16_t value5 = value4 + ;

  // Есть унарный + но смысла я в нем невижу, к сожалению, его идея это добавить знак + к значению, как в матиматике
  // явно указываем что число у нас положительное, применяеться к rvalue
  uint16_t value5 = +10;
  printf("value5 = %d\n", value5);
  
  // явно указываем что число у нас положительное, применяеться к lvalue
  value4 = +value5;
  printf("value4 = %d\n", value4);

  // ошибка, такая как и с бинарный оператором +
  // +value5 = value4;

  // два литерала double
  double value6 = 1.25 + 3.25;
  printf("value6 = %f\n", value6);

  // также можно использовать суфиксы
  value6 = 1.f + 1.30;
  printf("value6 = %f\n", value6);

  // результат будет  вещественное число double > int
  value6 = 1000 + 1.40;
  printf("value6 = %f\n", value6);

  // 170 + 220 = 390, т.е вместо 390, увидем 134, это пример переполнения
  uint8_t value7 = value2 + 220;
  printf("value7 = %d\n", value7);

  // но этого можно избежать используя вывод типов, получим 390
  auto value8 = value2 + 220;
  printf("value8 = %d\n", value8);

  // ну или используя унифицированную инициализацию, получим предупреждения компиляции сужающие преобразование
  uint8_t value9 {value2 + 220};
  printf("value9 = %d\n", value9);

  // но в этом случае мы получим ошибку компиляции narrowing conversion
  // value9 = {255 + 255};
}

void work_with_operator_minus() {
  // разница в том что результатом выражения надо делать знаковую переменную, т.к. результат может быть отрицательное число

  int32_t value1 = 100 - 70;
  printf("value1 = %d\n", value1);

  int32_t value2 = value1 - 70;
  printf("value2 = %d\n", value2);
  uint32_t value3 = 100;
  // иногда логически не коректен т.к. размер безнакового больше чем знакового и мы можем получить переполнения
  int32_t value4 = value3 + value2;
  printf("value4 = %d\n", value4);
  // получим переполнение
  value4 = std::numeric_limits<uint32_t>::max() - 100;
  printf("value4 = %d\n", value4);

  // получим ошибку компиляции
  /*value4 = {std::numeric_limits<uint32_t>::max() - 100};
  printf("value4 = %d\n", value4);*/

  // но если написать так то все скомпилируеться ок, магия
  value4 = {std::numeric_limits<uint32_t>::max() + 100};
  printf("value4 = %d\n", value4);

  /*
    тут мы инвертируем знак, в отличие от унарного +, он имеет смысл
    в смене знака надо быть тоже осторожным, если мы поменяем с бещнакового на знаковое получим переполнение
  */
  int32_t value5 = -value2;
  printf("value5 = %d\n", value5);
  printf("value5 = %d\n", -value5);
}

void work_with_divide() {
  // получим целое число без дробной части
  double value1 = 10 / 20;
  std::cout << "value1 = " << value1 << std::endl;
  // получим число с дробной частью
  // или можно использовать явное преобразование к типу
  value1 = 10.f / 20; // value1 = (double)10 / 20;
  std::cout << "value1 = " <<  value1 << std::endl;
  
  int8_t value2 = 100;
  // полученем целое число
  value1 = value2 / 90;
  std::cout << "value1 = " <<  value1 << std::endl;
  value1 = value2 / (double)90; // double(value2) / 90;
  std::cout << "value1 = " << value1 << std::endl;

  // может кинуть исключительную ситуацию
  //int value3 = value2 / 0;
  // получим бесконечность inf
  double value3 = static_cast<double>(value2) / 0;
  std::cout << "value3 = " << value3 << std::endl;

  // это есть не число
  value3 = 0.f / 0;
  std::cout << "value3 = " << value3 << std::endl;
}

void work_with_multiplication() {
  // при умножении можно больше получить возможности переполнения
  int32_t value1 = 100 * 2;
  printf("value1 = %d\n", value1);

  int32_t value2 = value1 * 30;
  printf("value2 = %d\n", value2);

  // получим переполнение, компилятор предупредит, т.к. время компиляции выражение
  uint8_t value3 = 20 * 140;
  printf("value3 = %d\n", value3);

  // тут компилятор не предупредит
  value3 = value1 * 140;
  printf("value3 = %d\n", value3);
  
  // а в этом компилятор пердупредит
  value3 = {value1 * 140};
  printf("value3 = %d\n", value3);
}

void mixed_expression() {
  // тут понятно, как и в матиматике сначало умножение а потом результат складываться с числом 20
  uint32_t value1 = 20 + 30 * 50;
  printf("value1 = %d\n", value1);
  // все зависит от того как компилятор будет выполнять выражение слева направо или справа на лево
  double value2 = 20.f  / 30 + 25 * 10;
  printf("value2 = %f\n", value2);

  /*
   тут будет неопределенная последовательность вычесления
   т.е. что выполнятися сначало value2 * value2 или value2 / value1 или value1 / value1
   если посмотреть асемблерный код под х86-64 gcc 8.2, то порядок будет
   слева на право
  */
  double value3 = value2 * value2 / value1 / value1;
  printf("value3 = %f\n", value3);
  /*
   чтобы не было такой путаницы применяют оператор (), т.е им мы укащываем что должно быть первым выполняться
   сначало поделим value1 на value1, потом помножим value2 на value2 и потом результат двох выражений поделим между собой
  */
  value3 = (value2 * value2) / (value1 / value1);
  printf("value3 = %f\n", value3);

  uint32_t value_tmp = 100;
  // результат будет отрицательным числом
  auto value4 = value1 * 30 * -value_tmp;
  printf("value4 = %d\n", value4);
}

void catch_narrowing_run_time() {
  uint32_t value;
  std::cin >> value;
  int32_t value1 {value};

  value1 = {value - 100};
  printf("value1 = %d\n", value1);
  // тоже самое как и для целых 
  long double value2;
  std::cin >> value2;
  double value4 {value2};

  value4 = {value2 - 300.20};
  printf("value4 = %f\n", value4);
}

int main(int argc, char const *argv[]) {
  work_with_operator_plus();
  work_with_operator_minus();
  work_with_divide();
  mixed_expression();
  return 0;

}
