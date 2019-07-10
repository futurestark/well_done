#include <cstdint>
#include <cstdio>

int main() {
    // инициализация во время компиляции
    constexpr int cvalue = 10;
    uint8_t value = 20;
    // инициализировать константу во время выполнения
    const int rconst = value;
    constexpr float pi = 1.22;
    // ошибка компиляции
    // constexpr int econst = value;
    printf("compile time const %d\n", cvalue);
    printf("run time const %d\n", rconst);
    printf("%.2f\n", pi);
    return 0;
}