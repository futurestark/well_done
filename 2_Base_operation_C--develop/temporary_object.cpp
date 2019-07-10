#include <cstdio>

int main(int argc, char const *argv[]) {

    // сохраняем временную переменную возращаемую функцией printf
    int count_read_symbol = printf("Hello world");
    // способ подавить ворнинги компилятора, если мы не обрабатываем возращаемое значение
    (void) printf("count %d", count_read_symbol);

    float float_value = 1.45;
    // преобразование типов также приводит к созданию временного объекта
    int int_value = static_cast<int>(float_value);

    (void) printf("int_value %d\n", int_value);

    printf("int_value %p\n", &int_value);
    // результатом оператора присвоение не есть временный объект
    printf("assigned address %p\n", &(int_value = 20));
    return 0;
}
