#include <iostream>
#include <iomanip>

int main(int argc, char const *argv[]) {
    std::cout << std::boolalpha;

    int a = 41;
    // проверка диапазона (20, 40] 
    bool is_access = a > 20 && a <= 40;
    std::cout << is_access << std::endl;

    is_access = a == 20 || a == 41;
    std::cout << is_access << std::endl;

    is_access = !(a == 20 || a == 41);
    std::cout << is_access << std::endl;

    // если применить к выражению закон де моргана
    is_access = !(a == 20) && !(a == 41);
    std::cout << is_access << std::endl;

    bool flag = false;

    a = 101;

    is_access = a > 100 && flag;

    std::cout << is_access << std::endl;

    is_access = !(a > 100 && flag);
    std::cout << is_access << std::endl;
    // выражение выше соответствует закону де моргана
    is_access = !(a > 100) || !flag;
    std::cout << is_access << std::endl;

    auto value = 1;
    is_access = value != 0 && a > 100;
    std::cout << is_access << std::endl;

    // в силу того что неявно в С++ целый тип может преобразовываться в bool
    is_access = value && a > 100;
    std::cout << is_access << std::endl;
    // по правилам перобразования все что не 0 это true
    value = 0;
    // такую конструкцию !value, но этим просто означает что проверяют на ноль
    is_access = !value && a > 100;
    std::cout << is_access << std::endl;
    
    // в выражения может присутсвовать смешаные логические операторы
    is_access = (a > 101 && a < 200) || !value;

    is_access = ((a > 100) && printf("a > 100\n"));
    is_access = ((a == 101) && printf("a == 101\n"));
    is_access = ((a > 101) && printf("Not printed\n"));
    is_access = (value || printf("Printed because value is equal zero\n"));
    is_access = (!value || printf("Not printed\n"));
    (void)(!value && ++value < 3 && ++value < 3 && ++value == 3 && printf("value %d\n", value)); 
    return 0;
}
