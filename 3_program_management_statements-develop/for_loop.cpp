#include <iostream>
#include <cstring>

int main(int argc, char const *argv[]) {
/*  for(;;) {
    std::cout << "please enter number for summ count or zero for exit" << std::endl;
    size_t count;
    std::cin >> count;
    long long summ = 0;
    if (count > 0) {
      for (size_t i = 0; i < count; ++i) {
        std::cout << "please enter number for summ value" << std::endl;
        int tmp;
        std::cin >> tmp;
        summ += tmp;
      }
      auto avarage = summ / static_cast<double>(count);
      std::cout << "Avarage of summ " << summ << " is " << avarage << std::endl;
    } else {
      break;
    }
  }
*/
  const char *str = "Hello World";
  size_t count;
  for (count = 0; *str; ++count, ++str)
    ;
  std::cout << "count char in string " << str << " is " << count << std::endl;
  std::cout << "Check with standard library function " << strlen("Hello World") << std::endl;

  
  str = "Hello World";
  size_t count_alpha = 0;
  for (size_t i = 0; str[i] != '\0';) {
    count_alpha += (str[i++] == 'l');
  }

  std::cout << "count char 'l' in string " << str << " is " << count_alpha << std::endl;

  for (size_t value = 34567, digit = 0; value; value /= 10) {
    if ((digit = (value % 10)) % 2 == 0) {
      std::cout << "digit " << digit << " is even \n";
    } else {
      std::cout << "digit " << digit << " is odd \n";
    }
  }
  std::cout << std::endl;

  return 0;
}
