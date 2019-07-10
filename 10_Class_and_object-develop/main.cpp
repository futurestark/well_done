#include <iostream>
#include "stack.hpp"

int main(int argc, char const *argv[]) {
  Stack st{10};
  std::cout << st.GetMaxStackSize() << std::endl; 
  st.push(101);
  std::cout << st.top().value << std::endl;
  Stack st_more{st};

  std::cout << st_more.GetMaxStackSize() << std::endl; 
  if (st_more.top().status) {
   std::cout << st_more.top().value << std::endl;
  } else {
    std::cout << "Stack is empty" << std::endl;
  }
  
  st_more = st_more;

  return 0;
}
