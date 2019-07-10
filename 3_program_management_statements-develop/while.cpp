#include <iostream>

void Print() {
  std::cout << "Please enter number:" << std::endl;
  size_t count;
  std::cin >> count;
  if (count > 1) {
   size_t mid = count / 2;
   int start = mid;
   size_t end = mid;
   while (start >= 0) {
     for (int i = 0; i < start; ++i) {
        std::cout << ' ';
     }
     for (int i = start; i <= end; ++i) {
        std::cout << '*';
     }
     for (int i = end; i < count; ++i) {
        std::cout << ' ';
     }
     --start;
     ++end;
     std::cout << '\n';
   }
  }
}


void memset_our() {
  size_t value = 23;
  while(value >>= 1) {
    std::cout << "One iteration shift right" << std::endl;
  }
  std::cout << "value is " << value << std::endl;
}

int main(int argc, char const *argv[]) {
/*  // обьявим бесконечный цикл
  while (true) {
    std::cout << "Please enter number or zero to exit" << std::endl;
    int value;
    std::cin >> value;
    if (value > 0) {
      while (value > 10) {
          value /= 10;
      }
      std::cout << "Last digit is " << value << std::endl; 
    } else {
      break;
    }
  }
*/
  /*Print();

  const char *str = "Hello World";
  size_t count_white_space = 0;
  size_t count_l_symbol = 0;
  while(*str) {
    char c;
    switch(c = *str++) {
      case ' ':
        ++count_white_space;
        break;
      case 'l':
        ++count_l_symbol;
        break;        
    }
  }
  std::cout << "whitespace " << count_white_space << " count l " << count_l_symbol << std::endl; 

  std::cout << "Enter value" << std::endl;
  size_t value;
  while (std::cin >> value) {
    std::cout << "Enter " << value << std::endl; 
  }
*/
  memset_our();
  return 0;
}
