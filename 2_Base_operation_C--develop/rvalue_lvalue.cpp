#include <cstdio>

int main(int argc, char const *argv[]) {
    // переменная а есть lvalue т.к. с ней связан адресс в памяти, литерал 30 это rvalue
    int a = 30;

    /* 
     в данном случае переменная а и b есть lvalue,
     но с переменной b считыветься значение которое являеться временным и автоматически есть rvalue
    */
    int b = a;

    // ошибка, т.к. и не логично
    // 7 = b;

    // но строковый литерал есть lvalue, т.к. он находиться в read only памяти
    printf(R"(Address literal "Hello World" is %p)", &"Hello world");
    // ошибка компиляции т.к. нельзя взять адресс целочисленого литерала lvalue required as unary ‘&’ operand
    // printf("Address literal 7 is %p", &7);

    return 0;
}
