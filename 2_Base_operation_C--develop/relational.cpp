#include <iostream>
#include <iomanip>

int main(int argc, char const *argv[]) {
    bool value = 10 > 5;
    std::cout << std::boolalpha;
    std::cout << value << std::endl;

    value = 10 < 5;
    std::cout << value << std::endl;

    value = 10 == 10;
    std::cout << value << std::endl;

    value = 10 == 10;
    std::cout << value << std::endl;

    value = 10 >= 9;
    std::cout << value << std::endl;

    value = 10 <= 20;
    std::cout << value << std::endl;

    value = 10 != 20;
    std::cout << value << std::endl;

    int value2 = -130;

    // это частая такая ошибка в программировании, вместо оператора == ставят оператор =, результатом всегда будет истина
    // компилятор выдаст варнинг, но для начинающих он немного не понят
    value = value2 = 15;
    std::cout << value << std::endl;

    // это способ решения проблемы, внезапного присвоения переменной значения, rvalue неможет стоять в левой части оператора =
    // value = 15 = value2;
    
    int value3 = 30;

    // но такую ошибку сложно уже отловить, способы ее решения могут быть следующие
    value = value3 = value2;
    std::cout << value << std::endl;
    // делать явное преобразование к константе
    // value = (const int)value3 = value2;
    // начиная с С++11
    // value = (int &&)value3 = value2;
    
    return 0;
}
