#include <cstdio>
#include <cstdint>

int main(int argc, char const *argv[])
{
    uint64_t value = 0;
    printf("value = %ld\n", value);
    // составной оператор это сокращенная форма value = value + 3;
    value += 3;
    printf("value = %ld\n", value);
    value += 5;
    printf("value = %ld\n", value);
    value += 2;
    printf("value = %ld\n", value);

    // имеет вид value = value * (1 + 2); результат будет на экране 30
    value *= 1 + 2;
    printf("value = %ld\n", value);

    value /= 3;
    printf("value = %ld\n", value);

    value -= 5;
    printf("value = %ld\n", value);
    return 0;
}
