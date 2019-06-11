# Операторы управляющие поведением программы
Что такое управляющие операторы? Это набор операторов которые влияют на ход выполнения проограммы, т.е. мы меняем порядок выполнения программы. До этого мы рассматривали последовательное выполнение программы, т.е. от начала блока и доконца выполняя последовательно все инструкции. Но иногда необходимо выполнить групу операторов или один оператор в зависимости от условия, или несколько раз выполнить одну и туже групу операторов. В С++ различают условные операторы и итерационные(циклы), а также оператор перехода. Разница в том как они могут быть выполнены.
Чаще условные операторы применяються с логическими операторами и операторами отношения
### Условный оператор if
Этот условный оператор выполняеться если истино его условие. Он имеет три формы:
```
// простой if
if (условие) {
  оператор;
}
// или
if (условие)
  оператор;

// в виде ветки, т.е. условные переходы, в случае истиности выполнить одно условие, в случае ложи выполнить другое условие
if (условие) {
  оператор; // в случае истиности
} else {
  оператор; // в случае успеха ложи
}

// и проверки условия в случае ложи
if (условие) {
  оператор; // в случае истиности
} else if (условие) {
  оператор;
}
```
```cpp
#include <cstdio>
#include <iostream>

void IsNumberPositive(int number) {
  printf("IsNumberPositive\n");
  if (number > 0) {
    printf("number > 0\n");
  } else if (number == 0) {
    printf("number == 0\n");
  } else {
    printf("number < 0\n");
  } 
}

bool IsOdd(size_t number) {
  return number & 1;
}


int main(int argc, char const *argv[]) {
  
  IsNumberPositive(10);
  IsNumberPositive(0);
  IsNumberPositive(-10);

  printf("Please enter number :");
  size_t value;
  std::cin >> value;

  if (IsOdd(value)) {
    printf("Number %zd is odd \n", value);
  } else {
    printf("Number %zd is even \n", value);
  }

  printf("Please enter number :");
  if ((std::cin >> value, IsOdd(value))) {
    printf("Number %zd is odd \n", value);
  } else {
    printf("Number %zd is even \n", value);
  }

  // работает только начиная с С++17
  /*if (size_t value1 = 0; std::cin >> value1) {
    if (IsOdd(value1)) {
      printf("Number %zd is odd \n", value1);
    } else {
      printf("Number %zd is even \n", value1);
    }
  }*/

  printf("Please enter number :");
  if (std::cin >> value) {
    printf("You are entered %zd\n", value);
  } else {
    printf("Error in stdin stream \n");
  }

  printf("Please enter number :");
  std::cin >> value;
  if (value > 100 && value < 200) {
    printf("value %d is in range (100..200):");
  } else {
    printf("value %d is not in range (100..200):");
  }

  printf("Please enter number :");
  std::cin >> value;
  if (value > 100 && value < 200) {
    if (value >= 50 && value <= 70) {
      printf("value %d is in range [50..70]:");
    } else {
      printf("value %d is in range (100..200):");
    }
  } else {
    printf("value %d is not in range (100..200):");
  }

  return 0;
}

```
В С++ есть еще проблема так называемого висячего else, т.е. else относиться к ближайшему if как  часть блока, например
```
{
// логическая ошибка мы ожидаем не ту выполняющую ветку else
if (a)
  if (b)
    foo ();
else
  bar ();
}

{
if (a)
 {
   if (b)
     foo();
   else
     bar();
  }
}

```

## Оператор выбора switch
В простой форме оператор switch призван заментить многословный оператор if, т.е. вместо многословных `if else if`(который может быть более запутанный), используються читаемый выбор.
```cpp
if (x == 5) {

} else if (x == 7) {

} else if (x == 8) {

} else if (x == 10 || x == 20) {

}

switch (x) {
 case 5: {
  break;
 }
 case 7:
  break;
 case 8:
  break;
 case 10: case 20:
  break;
 default:
  break;
}
```
Важным замечанием switch оператора есть то что после каждой ветки должно идти так называемое прерываение выплнения ветки, иногда это break, а иногда это return, если этого не выполнить то будет выполняться следующая ветка после выпоняемой ветки. Иногда компилятор выдает предупреждение, что мы так называемое проваливаемся (fall through).
В С++17 есть специальный атрибут [[fallthrough]] который подавляет варнинги компилятора, о том что мы намерено так сделали, т.е. провал между ветками. Ну и показывает читаемому человеку что мы намерено так поступили.
В опреаторе switch всегда выполняеться ветка case, т.е. есть проблема недостижимости инструкции

```
// операция i = 15; некогда не будет выполнена
switch (cond)
{
  i = 15;
  ...
  case 5:
  ...
}

// все будет ок
switch (cond)
{
int i;
...
case 5:
i = 5;
...
}

```
```cpp

#include <iostream>

enum EnumTest{
  FIRST = 1,
  SECOND,
  THIRD,
  FOURTH
};

void PrintEnumValue(EnumTest value) {
  switch (value)
  {
    case FIRST:
      printf("FIRST\n");
      break;
    case SECOND:
      printf("SECOND\n");
      break;
    case THIRD:
      printf("THIRD\n");
      break;
    case FOURTH:
      printf("FOURTH\n");
      break;
    default:
      printf("UNDEFINED\n");
      break;
  }
}

enum Bitset{
  FIRST_SET_BIT = 1UL << 0,
  SECOND_SET_BIT = 1UL << 1,
  THIRD_SET_BIT = 1UL << 2,
  FOURTH_SET_BIT = 1UL << 3
};

void CheckSetBit(Bitset value, Bitset bit) {
  switch (value & bit)
  {
    case FIRST_SET_BIT:
      printf("Set first bit\n");
      break;
     case SECOND_SET_BIT:
      printf("Set second bit\n");
      break;
     case THIRD_SET_BIT:
      printf("Set third bit\n");
      break;
     case FOURTH_SET_BIT:
      printf("Set forth bit\n");
      break;
    default:
      printf("Unset bit\n");
      break;
  }
}

int main(int argc, char const *argv[]) {
  std::cout << "Please enter number" << std::endl;
  int value;
  std::cin >> value;
  switch (value)
  {
    case 1:
      printf("equal if (x == 1)\n");
      break;
    case 2:
      printf("equal else if (x == 2)\n");
      break;
    case 3: case 4:
      printf("equal else if (x == 3 || x == 4)\n");
      break;
    default:
      printf("equal else\n");
      break;
  }

  PrintEnumValue(EnumTest::FIRST);
  PrintEnumValue(static_cast<EnumTest>(value));

  Bitset flag = static_cast<Bitset>(Bitset::FIRST_SET_BIT | Bitset::SECOND_SET_BIT);
  CheckSetBit(flag, Bitset::SECOND_SET_BIT);
  CheckSetBit(flag, Bitset::FOURTH_SET_BIT);
  return 0;
}

```
## Операторы цикла
Циклические операторы в отличие от условных, призваны повторять операции n-е количество раз.
### Оператор цикла for
Повторяет условие пока условие не станит ложным. Использовать цикл for необходимо, если мы точно знаем сколько раз его надо выполнить

Его синтаксис следующий
```
for (начальное инициализация; условие; итерация )
```

Каждый из элементов цикла for может быть опущен, т.е может иметь вид
```
for(;;) // такой цикл называеться бесконечным
```
Смысл опреатора следующий, сначало выполняеться инициализация, потом проверяеться условие, выполнить тело цикла а затем итерацию, и т.д выполнять пока условие истино.
```cpp
#include <iostream>
#include <cstring>

int main(int argc, char const *argv[]) {
/*  for(;;) {
    std::cout << "please enter number for summ count or zero for exit" << std::endl;
    size_t count;
    std::cin >> count;
    long long summ = 0;
    if (count > 0) {
      for (size_t i = 0; i < count; ++i) {
        std::cout << "please enter number for summ value" << std::endl;
        int tmp;
        std::cin >> tmp;
        summ += tmp;
      }
      auto avarage = summ / static_cast<double>(count);
      std::cout << "Avarage of summ " << summ << " is " << avarage << std::endl;
    } else {
      break;
    }
  }
*/
  const char *str = "Hello World";
  size_t count;
  for (count = 0; *str; ++count, ++str)
    ;
  std::cout << "count char in string " << str << " is " << count << std::endl;
  std::cout << "Check with standard library function " << strlen("Hello World") << std::endl;

  
  str = "Hello World";
  size_t count_alpha = 0;
  for (size_t i = 0; str[i] != '\0';) {
    count_alpha += (str[i++] == 'l');
  }

  std::cout << "count char 'l' in string " << str << " is " << count_alpha << std::endl;

  for (size_t value = 34567, digit = 0; value; value /= 10) {
    if ((digit = (value % 10)) % 2 == 0) {
      std::cout << "digit " << digit << " is even \n";
    } else {
      std::cout << "digit " << digit << " is odd \n";
    }
  }
  std::cout << std::endl;

  return 0;
}
```
### Оператор while
Если например при работе c for мы знаем количество итераций, например при обходе массива, то при работе c оператором while, это если мы не значем точное количество операций, и итерационная переменная может быть гибкая. Еще важным отличием оператора while от for есть то что итерационная переменная всегда выполняеться в конце итерации цикла for, то такой итерации в цикле while нет.
Оператор while работает следующим образом пока условие истино выполняеться условие
```
while(условие) {
  body
}
```
```cpp
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
```
### Оператор цикла do while
Отличием оператора do while от while, то что выполниться точно один проход, т.е. условие проверяеться не в конце а в начале

```
do {

}while(условие);

```

```cpp
#include <iostream>

/*
bool WgUtilsApplier::SetWgDevice() const {
  int ret = 0;
  wg_device device{};

  memcpy(device.name, wg_dev_name_.c_str(), wg_dev_name_.length());
  device.listen_port = GetWgListeningPort();
  device.flags = static_cast<wg_device_flags>(WGDEVICE_HAS_PRIVATE_KEY |
                                              WGDEVICE_HAS_LISTEN_PORT);

  if (wg_key_is_zero(private_key_)) {
    OLU_DLT_LOG_ERROR(__FUNCTION__, "Error: wg key is zero for ",
                      wg_dev_name_.c_str());
  } else {
    memcpy(device.private_key, private_key_, sizeof(private_key_));
    if ((ret = wg_set_device(&device)) < 0) {
      OLU_DLT_LOG_ERROR(__FUNCTION__, "Error: Unable to set device for ",
                        wg_dev_name_.c_str(), " : ", strerror(ret));
      ret = 0;
    } else {
      ret = 1;
    }
  }
  return !!ret;
*/

/*
bool WgUtilsApplier::SetWgDevice(const std::string& own_public_key) const {
  bool result = false;
  wg_device device{};

  memcpy(device.name, wg_dev_name_.c_str(), wg_dev_name_.length());
  device.listen_port = GetWgListeningPort();
  device.flags = static_cast<wg_device_flags>(WGDEVICE_HAS_PRIVATE_KEY |
                                              WGDEVICE_HAS_LISTEN_PORT);

  do {
    if (wg_key_is_zero(private_key_)) {
      OLU_DLT_LOG_ERROR(__FUNCTION__, "Error: wg key is zero for ",
                        wg_dev_name_.c_str());
      break;
    }

    memcpy(device.private_key, private_key_, sizeof(private_key_));

    // Set public key to device
    if (!own_public_key.empty()) {
      wg_key public_key;

      int ret = wg_key_from_base64(public_key, own_public_key.c_str());
      if (ret < 0) {
        OLU_DLT_LOG_ERROR(__FUNCTION__, "Error: Unable to convert the public key ",
                          own_public_key, ": ", strerror(ret));
        break;
      }

      if (wg_key_is_zero(public_key)) {
        OLU_DLT_LOG_ERROR(__FUNCTION__, "Error: public wg key is zero for ",
                          wg_dev_name_.c_str());
        break;
      }

      memcpy(device.public_key, public_key, sizeof(public_key));
      device.flags = static_cast<wg_device_flags>(device.flags | WGDEVICE_HAS_PUBLIC_KEY);
    }

    int ret = wg_set_device(&device);
    if (ret < 0) {
      OLU_DLT_LOG_ERROR(__FUNCTION__, "Error: Unable to set device for ",
                        wg_dev_name_.c_str(), " : ", strerror(ret));
      break;
    }

    result = true;
  } while (false);

  return result;
}
*/

int main(int argc, char const *argv[]) {
  char ch;
  do {
    size_t value;
    std::cout << "Please enter number " << std::endl;
    std::cin >> value;
    std::cout << "You are enter " << value << std::endl;
    //если раскомитеть эту строку, то компилятор выдаст ошибку, что переменная опредена в не области видимости
/*    char ch = 'Y'; 
  } while (ch == 'Y');
*/
   std::cout << "Exit? Y : N" << std::endl;
   std::cin >> ch;
  } while (ch != 'Y');

  http://www.diag.com/news/DoWhileFalse.html


  return 0;
}
```
### Тернарный опреатор
Это просто сокращенная форма if else. Иммеет вид
```
переменная = условие ? опреатор в случае истиности : оператор в случае лжи;

if (условие) {

} else {

}
```
```cpp
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
```
возвращаемое значение в тернарном операторе должно быть одного типа или иметь неявное преобразование.



