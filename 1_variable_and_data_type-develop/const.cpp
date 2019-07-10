#include <iostream>

#define MACRO_INT 40
int main(int argc, char const *argv[])
{
    const int const_int = 10;
    // const_int = 20; // compiler error

    std::cout << const_int << std::endl;
    std::cout << MACRO_INT << std::endl;
#undef MACRO_INT // если закоментировать эту строку то получим предупреждения что переопределяем макрос
#define MACRO_INT 50
    std::cout << MACRO_INT << std::endl;
    return 0;
}
