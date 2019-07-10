#include <iostream>
#include <iomanip>
#include <cmath>

void func();
void func();
void func();

void func() {}
int main(int argc, char const *argv[])
{
  float value {12345678910.0};
  std::cout << std::setprecision(10);
  std::cout << value << std::endl;

  double d_value {0.1};
  std::cout << std::setprecision(6);
  std::cout << d_value << std::endl;
  std::cout << std::setprecision(17);
  std::cout << d_value << std::endl;

  double div_by_zero = 5.0 / 0.0;
  std::cout << div_by_zero << std::endl;
  std::cout << (0.0 / 0.0) << std::endl;

  double float_point = 5 / 2;
  std::cout << float_point << std::endl;
  float_point = 5.0 / 2;
  std::cout << float_point << std::endl;

  float_point = 2.0 / (1 + 5) ;
  std::cout << float_point << std::endl;
  
  std::cout << INFINITY << std::endl;
  // float_point = 5 / 0;  programm will be terminate with exception (core dump)
  return 0;
}
