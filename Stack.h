#pragma once
class Stack {

public:

	//Stack(unsigned size) : stack_deepth(size) {};
	Stack() = default;

	void init_stack(Stack * stk);
	void push(Stack * stk, float f);
	float pop(Stack * stk);
	float stkTop(Stack * stk);
	int gettop(Stack * stk);
	int isempty(Stack * stk)const;
	void stkPrint(Stack* stk)const;
	int GetMaxStackSize()const;


private:
	constexpr static unsigned stack_deepth = 7;
	double st_elements[stack_deepth];
	int top;
};
