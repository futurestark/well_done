#include <iostream>
#include "Stack.h"

void Stack::init_stack(Stack * stk) {
	stk->top = 0;
}

void Stack::push( Stack * stk, float f) {   //add to stack
	if (stk->top < stack_deepth) {
		stk->st_elements[stk->top] = f;
		stk->top++;
	}
	else
		std::cout << "stack is full, elements count is : " << stk->top << std::endl;
}

float Stack::pop(Stack* stk) {   //remove from stack
	float elem;
	if ((stk->top) > 0) {
		stk->top--;
		elem = stk->st_elements[stk->top];
		return(elem);
	}
	else {
		std::cout << "stack is empty!" << std::endl;
		return(0);
	}
}

float Stack::stkTop(Stack* stk) {  //izvlechenie vershini steka
	if ((stk->top) > 0) {
		return(stk->st_elements[stk->top - 1]);
	}
	else {
		std::cout << "stack is empty!" << std::endl;
		return(0);
	}
}

int Stack::gettop(Stack* stk) {  //get top stack element
	return(stk->top);
}

int Stack::isempty(Stack* stk)const {  //is stack empty or no
	if ((stk->top) == 0)    return(1);
	else return(0);
}

void Stack::stkPrint(Stack* stk)const {  //print all stack elements
	int i;
	i = stk->top;
	if (isempty(stk) == 1) return;
	do {
		i--;
		std::cout << stk->st_elements[i] << std::endl;
	} while (i > 0);
}

int Stack::GetMaxStackSize()const {
	return stack_deepth;
}
//----------------------------