/*****************************************************************************
 * This example demonstrates the difference between stack and heap memory organization
 *
 * Этот пример демонстрирует разницу между стеком и кучей в организации памяти
 *
 * Code&Robots site:       http://codrob.ru/
 * YouTube Channel:        https://www.youtube.com/channel/UCTGS5FRyz564wwiyNs8J54A
 * Social networks:        https://vk.com/codrob
 *                         https://www.facebook.com/groups/295824740787675/
 *
 * This example code is in public domain and licensed under MIT license
*****************************************************************************/

#include <iostream>
using namespace std;

class Example
{
public:
	int* SetStack ()
	{
		int StackA = 10;
		cout << "In SetStack: " << StackA << " | " << &StackA << endl;
		return &StackA;
	}

	int* SetHeap ()
	{
		int *HeapA = new int (20);
		cout << "In SetHeap: " << *HeapA << " | " << HeapA << endl;
		return HeapA;
	}
};

int main()
{
	Example exp;

	int *StackVar = NULL, *HeapVar = NULL;

	StackVar = exp.SetStack();
	HeapVar = exp.SetHeap();

	//Segmentation fault
	//cout << *StackVar << " | " << StackVar << endl;
	cout << *HeapVar << " | " << HeapVar << endl;
}
