#include <stdio.h>
#include <iostream>
#include <limits>

int main(int argc, char const *argv[])
{
  int int_ = 100;
  // неявное преобразование int -> long int, разширяющее преобразование, т.к. размер long позволяет гранить размер int
  long long_ = int_;
  // также неявное преобразование, но с другими типами double <- int, разширяющее преобразование, т.к. размер long позволяет гранить размер int
  double double_ = int_;
  printf("int_ = %d\n", int_);
  printf("long_ = %ld\n", long_);
  printf("double_ = %f\n", double_);

  // сужащее преобразование double -> int, так как размер int меньше чем double, то характерна потеря точности
  // получим ВОЗМОЖНО предупреждения компилятора
  double_ = 20.15;
  int_ = double_;
  printf("int_ = %d\n", int_);
  int_ = 65;
  // сужащее преобразование int -> char
  char ch_ = int_;
  // напечатает латинский символ A(неявное преобразование)
  printf("int_ = %c\n", int_);
  // напечает число 65
  std::cout << int_ << std::endl;
  // напечатает латинский символ A
  std::cout << ch_ << std::endl;
  
  // позволяет неявно преобразововать числа в логические
  // часто встречающийся механизм преодбразования челочисленных значений в логические
  bool flag = !!int_;
  std::cout << std::boolalpha;
  // напечатает true
  std::cout << flag << std::endl;

  int_ = 0;
  // можно также
  flag = int_;
  // напечатает false
  std::cout << flag << std::endl;
  flag = double_;

  // напечатает true
  std::cout << flag << std::endl;

  // получим ворнинг то что большое целое будет обрезано до безнаково 1 байтового
  unsigned char c2 = 800;

  // компилтор не выдаст ворнинга, т.к. мы скзали компилятору что знаем что делаем
  c2 = (unsigned char)512; // или можно записать так char(512u)
  // напечатает 0
  printf("c2 = %d\n", c2);

  // получим ворнинг переполнение при неявном преобразовании типов
  unsigned char c3 = 100000.6000;

  // пример неявного суживающегося преобразования
  unsigned int unsigned_int_ = std::numeric_limits<unsigned int>::max();
  int signed_int = unsigned_int_;
  std::cout << signed_int << std::endl;

  // выражение будет преобразовано нявно в int, в данном контексте будет потеря точности 
  double double_expresion_ = 1 / 7;
  // напечатает 0
  std::cout << double_expresion_ << std::endl;
  // теперь выражение будет расширено/приведено до вещественого типа
  double_expresion_ = double(1) / 7;
  // напечатает 0.142....
  std::cout << double_expresion_ << std::endl;

  int static_style_cast = 1000;
  double double_cast_ = static_cast<double>(static_style_cast);
  std::cout << double_cast_ << std::endl;

  int cvalue = 400;
  const int& crvalue = cvalue;
  // напечатает 400
  // crvalue = 500 // ошибка компиляции
  std::cout << crvalue << std::endl;
  const_cast<int&>(crvalue) = 900;
  // напечатает 900
  std::cout << crvalue << std::endl;
  return 0;
}
