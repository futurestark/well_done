#include <iostream>

size_t IncDec(size_t value) {
  return value & 1 ? value + 1 : value - 1;
}

int main(int argc, char const *argv[])
{
    char ch;
    do {
        size_t value;
        std::cin >> value;
        std::cout << IncDec(value) << std::endl;
        std::cin >> ch;
    } while(ch != 'Y');

    size_t a = 5;
    (void) (a > 5 ? std::cout << " a > 5\n" : std::cout << "a <= 5\n");
    return 0;
}
