#include <cstdio>

int main(int argc, char const *argv[])
{
  int int_value; // происходит обьявление переменной целого типа и неявная инициализация неизвестным значением
  printf("int_value is = %d\n", int_value);
  int value = 42; // происходит обьявление переменной целого типа и явная инициализация числом 42
  /*
  следующая инициализация такая же как и выше
  int value(42);
  int value = int(42);
  */
  printf("value is = %d\n", value);
  // с появление С++11 повилось так называемая универсальная инициализация
  int value_uni{42};
  /*
   или избыточные 
   int value_uni1 = {42};
   int value_uni2 = int{42};
  */
  printf("value_uni is = %d\n", value_uni);
  // инициализация нулем
  int zero = 0;
  /*
   следующая инициализация такая же как и выше
   int zero1 = int();
   но следующуе обьявление не есть ошибочное с точки зрения компилятора, но интерпритируеться им по другом
   int zero(); // обьявляеться функция
   следующее обьявление тоже ошибочное
   int zero = (); // error
   int zero = {}; // compiled ok)
   int zero2{};
  */
  printf("zero is = %d\n", zero);
  
  // можно объвлять переменные в один ряд, только в том случае если у них общий тип
  int oneline_value1, oneline_value2 = 20, oneline_value3;
  printf("oneline_value1 is = %d, oneline_value2 is = %d, oneline_value1 is = %d\n", oneline_value1, oneline_value2, oneline_value3);

  int tricks = (7, 9);
  printf("tricks is = %d\n", tricks); // напечатает 9, срабатывает правило запятой
  /*
   но если написать
   int tricks(7, 9); // ошибка компиляции
   или
   int tricks = int(7, 9);
  */
  // если мы будем использовать универсальную иницализацию то получим грамотную ошибку компиляции
  //int error_initializing = {7, 9};
  /*
  очень полезной функциональностью универсальныч инициализаций есть, уменьшение ошибки сужающего преобразования
  int reduce{1.5f}; // compilation error
  */
  int reduce = 1.5f; // compiles fine
  printf("reduce is = %d\n", reduce); // print 1
  return 0;
}
