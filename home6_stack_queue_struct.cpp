#include <iostream>
#include <cmath>
#include <stdio.h>  // to uppercase
#include <assert.h> // for asserts in uppercase
#include <ctime> // Home_5 this header to generate srand func by time elements of array to be sort
#include <time.h>  // for compare time to execute sort functions
#include <chrono>  //the same compare time
#include <cstring>  //for strlen to count str_size from cin for paste to function

//--------------------------------------- HOME_6 STACK --------------------------
#define NMAX 100
struct stack {
	float elem[NMAX];
	int top;
};

void init_stack(struct stack* stk);
void push(struct stack* stk, float f);
float pop(struct stack* stk);
float stkTop(struct stack* stk);
int gettop(struct stack* stk);
int isempty(struct stack* stk);
void stkPrint(struct stack* stk);
//------------------------- QUEUE ----------------------------------------------
#define QMAX 100
struct queue {
	int qu[QMAX];
	int rear, frnt;
};

void init_queue(struct queue* q);
void insert(struct queue* q, int x);
int isempty(struct queue* q);
void print(struct queue* q);
int removex(struct queue* q);
//-------------------------------------------------------------------------------

int main(const int const argc, const char* const argv[])    //this correct arg types must be
{
	//------------------------------- stack ----------------------------------------
	
	struct stack* stk;
	int i, n;
	float elem;
	stk = (struct stack*)malloc(sizeof(struct stack));
	init_stack(stk);
	std::cout << "enter total count of elements that stack can contain : " << std::endl;
	std::cin >> n;

	for (i = 0; i < n; i++) {
		std::cout << "put this elemnt to stack" << std::endl;
		std::cin >> elem;
		push(stk, elem);
	}
	std::cout << "in stack is elements: " << gettop(stk) << std::endl;
	stkPrint(stk);
	std::cout << "top element is: " << stkTop(stk) << std::endl;
	do {
		std::cout << "izvlekaem element from stack: " << pop(stk) << std::endl;
		std::cout << "v steke ostalos elementov: " << gettop(stk) << std::endl;
	} while (isempty(stk) == 0);
	getchar(); getchar();
	
	//------------------------------------------------------------------------------

	//------------------------- queue ----------------------------------------------
	struct queue* q;
	int a;

	q = (queue*)malloc(sizeof(queue));
	init_queue(q);
	print(q);
	for (int i = 0; i < 8; i++) {
		std::cout << "enter element in queue : " << std::endl;
		std::cin >> a;
		insert(q, a);
	}
	print(q);
	while (q->frnt <= q->rear) {
		a = removex(q);
		std::cout << "element removed " << a << std::endl;
		print(q);
	}
	getchar(); getchar();

	//------------------------------------------------------------------------------
	return 0;
}

//---------------------------------------- STACK FUNC --------------------------
void init_stack(struct stack* stk) {
	stk->top = 0;
}

void push(struct stack* stk, float f) {   //add to stack
	if (stk->top < NMAX) {
		stk->elem[stk->top] = f;
		stk->top++;
	}
	else
		std::cout << "stack is full, elements count is : " << stk->top << std::endl;
}

float pop(struct stack* stk) {   //remove from stack
	float elem;
	if ((stk->top) > 0) {
		stk->top--;
		elem = stk->elem[stk->top];
		return(elem);
	}
	else {
		std::cout << "stack is empty!" << std::endl;
		return(0);
	}
}

float stkTop(struct stack* stk) {  //izvlechenie vershini steka
	if ((stk->top) > 0) {
		return(stk->elem[stk->top - 1]);
	}
	else {
		std::cout << "stack is empty!" << std::endl;
		return(0);
	}
}

int gettop(struct stack* stk) {  //get top stack element
	return(stk->top);
}

int isempty(struct stack* stk) {  //is stack empty or no
	if ((stk->top) == 0)    return(1);
	else return(0);
}

void stkPrint(struct stack* stk) {  //print all stack elements
	int i;
	i = stk->top;
	if (isempty(stk) == 1) return;
	do {
		i--;
		std::cout << stk->elem[i] << std::endl;
	} while (i > 0);
}
//------------------------------------------------------------------------------

//------------------------- QUEUE ----------------------------------------------
void init_queue(struct queue* q) {
	q->frnt = 1;
	q->rear = 0;
	return;
}

void insert(struct queue* q, int x) {  //add to queue
	if (q->rear < QMAX - 1) {
		q->rear++;
		q->qu[q->rear] = x;
	}
	else
		std::cout << "Queue is full!" << std::endl;
	return;
}

int isempty(struct queue* q) {     // check if queue is empty
	if (q->rear < q->frnt)    return(1);
	else  return(0);
}

void print(struct queue* q) {   // print all elements
	int h;
	if (isempty(q) == 1) {
		std::cout << "Queue is empty" << std::endl;
		return;
	}
	for (h = q->frnt; h <= q->rear; h++)
		std::cout << "element is " << q->qu[h] << std::endl;
	return;
}

/*
int remove(struct queue* q) {     // remove element from queue
	int x;
	if (isempty(q) == 1) {
		std::cout << "Queue is empty" << std::endl;
		return(0);
	}
	x = q->qu[q->frnt];
	q->frnt++;
	return(x);
}Недостатком в предложенной реализации очереди является то, что очередь смещается в сторону старших адресов массива, что может вызвать скорое переполнение.
Для устранения этого недостатка предложена другая реализация функции удаления элемента из очереди:*/

int removex(struct queue* q) {   //remove element from queue
	int x, h;
	if (isempty(q) == 1) {
		std::cout << "Queue is empty" << std::endl;
		return(0);
	}
	x = q->qu[q->frnt];
	for (h = q->frnt; h < q->rear; h++) {
		q->qu[h] = q->qu[h + 1];
	}
	q->rear--;
	return(x);
}
//------------------------------------------------------------------------------