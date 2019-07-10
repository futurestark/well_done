#include <iostream>
#include <iomanip> // for std::boolalpha
#include <type_traits> // std::is_same

int main(int argc, char const *argv[])
{
  auto i = 10; // i type -> int
  auto f = 10.5; // f type -> double
  auto ch = 'h'; // ch type -> char
  auto var_uint(5u); // var_uint type -> unsigned int
  std::cout << std::boolalpha;

  std::cout << std::is_same<decltype(i), int>::value << '\n'; // print true
  std::cout << std::is_same<decltype(f), double>::value << '\n'; // print true
  std::cout << std::is_same<decltype(f), float>::value << '\n'; // print false
  std::cout << std::is_same<decltype(ch), char>::value << '\n'; // print true
  std::cout << std::is_same<decltype(var_uint), unsigned int>::value << '\n'; // print true

  // auto unknown; // ошибка комиляции неизвестен тип
  decltype(i) new_int; // ok, new int is the same type how in i variables, but variables is uninitialized
  std::cout << std::is_same<decltype(new_int), int>::value << '\n'; // print true
  auto val_unif{20};
  std::cout << std::is_same<decltype(val_unif), int>::value << '\n'; // print true
  return 0;
}
