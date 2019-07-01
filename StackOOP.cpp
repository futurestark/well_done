#include <iostream>
#include "Stack.h"

int main()
{
	
	//Stack * stk = new Stack(128);   //int* ptr = new int; example create obj in dynamic memory
	Stack * in_stk_obj = new Stack;
	int i, n;
	float elem;
	//stk = (struct stack*)malloc(sizeof(Stack::stack));
	in_stk_obj->init_stack(in_stk_obj);

	std::cout << "enter total count of elements that stack can contain : " << std::endl;
	std::cin >> n;

	for (i = 0; i < n; i++) {
		std::cout << "put all elements one by one to stack max size that you enter" << std::endl;
		std::cin >> elem;
		in_stk_obj->push(in_stk_obj, elem);
	}
	std::cout << "in stack is elements: " << in_stk_obj->gettop(in_stk_obj) << std::endl;
	in_stk_obj->stkPrint(in_stk_obj);
	std::cout << "top element is: " << in_stk_obj->stkTop(in_stk_obj) << std::endl;
	do {
		std::cout << "izvlekaem element from stack: " << in_stk_obj->pop(in_stk_obj) << std::endl;
		std::cout << "v steke ostalos elementov: " << in_stk_obj->gettop(in_stk_obj) << std::endl;
	} while (in_stk_obj->isempty(in_stk_obj) == 0);
	getchar(); getchar();


    std::cout << "Object of stack deleted!\n";
	delete in_stk_obj;
}

