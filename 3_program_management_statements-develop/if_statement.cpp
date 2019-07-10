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
