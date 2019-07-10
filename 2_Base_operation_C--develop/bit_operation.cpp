#include <cstdio>
#include <cstdint>
#include <limits>
#include <bitset>

/*
 сдвиг влево <<, x << y это равносильно умножению x * 2^y 
 сдвиг вправо >>, x >> y, наоборот эквивалентно делению x / 2^y, прошу заметить что деление целочисленное 
 если один из операндов битового сдвига отрицательное число то это неопределенное поведение -1 << 1
*/
void ShiftLeftRight(int value, int shift) {
   printf("%d << %d == %d === %d * (2^%d)\n", value, shift, value << shift, value, shift);
   printf("%d >> %d == %d === %d / (2^%d)\n", value, shift, value >> shift, value, shift);
}

bool isOdd(int value) {
  return !!(value & 1);
}

int main(int argc, char const *argv[]) {
   uint16_t value = 0b000'000'000'000'010'0;
   printf("value = %d\n", value);
   uint16_t value2 = 0b000'000'000'000'000'1;
   // Пример установки бита
   /*
     000'000'000'000'010'0
                           |
     000'000'000'000'000'1
     ---------------------
     000'000'000'000'010'1 == 5 --> 2^0 + 2^2
   */ 
   printf("value | value2 = %d\n", value | value2);
   
   value2 = 0b111'111'111'111'101'1;
   // пример сбросить бит
   /*
     000'000'000'000'010'0
                           &
     111'111'111'111'101'1
     ---------------------
     000'000'000'000'000'0
   */ 
   printf("value & value2 = %d\n", value & value2);

   // инверсия битов, таки способом можно получить максимальное
   /*
     ~ 000'000'000'000'010'0
     ---------------------
       111'111'111'111'101'1 = 
   */

   value = ~value;
   printf("~value = %d\n", value);

   // должны получить максимальное значение 16 битного разрадного числа 
   value = 0;
   value = ~value; 

   printf("~value = %d, max unsigned = %d\n", value, std::numeric_limits<uint16_t>::max());
   
   // должны получить максимальное знакового 16 битного числа
   
   value2 = 0b100'000'000'000'000'0;
   value = ~value2;
   printf("~value = %d, max signed = %d\n", value, std::numeric_limits<int16_t>::max());
   std::bitset<8> b(126);

   printf("bit of %d =>> %s\n", 126, b.to_string().c_str());
   printf("bit of %d =>> %s\n", 126, b.to_string('1', 'X').c_str());

   ShiftLeftRight(5, 1);
   ShiftLeftRight(9, 1);
   ShiftLeftRight(4, 2);
   ShiftLeftRight(8, 1);
   // также битовые операторы & и | применяються и с операторами отношения

   value = 0;
   (void)((!value) | printf("Print always\n"));
   (void)(value & printf("Print always\n"));
   // Разница в том что в таком случае будут выполняться/ проверяться оба операнда
   
   // Битовая арифметика применима только к целым числам 
   /*
     double value3 = 20.10;
     value3 >>= 2;
   */
   (void)(isOdd(19) && printf("Odd\n"));
   (void)(isOdd(20) && printf("Odd\n"));
   return 0;
}
