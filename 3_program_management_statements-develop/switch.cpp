
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
   switch (EnumTest::SECOND)
    {
      int i = 30;
      case 2:
       printf("i = %d\n", i);
       break;
      default:
       break;
    }

  return 0;
}
