/*****************************************************************************
 *
 * This example demonstrates two ways to transfer any number of arguments to a function
 *
 * Code&Robots site:       http://codrob.ru/
 * YouTube Channel:        https://www.youtube.com/channel/UCTGS5FRyz564wwiyNs8J54A
 * Social networks:        https://vk.com/codrob
 *                         https://www.facebook.com/groups/295824740787675/
 *
 * This example code is in public domain and licensed under MIT license
*****************************************************************************/

#include <iostream>
#include <stdarg.h>

using namespace std;

//Simplest
/*void func (int num, int first, ...)
{
	int *ptr = &first;
	while (num--)
	{
		cout << *ptr++ << endl;
	}
}*/

//Recommended
void func (int num, ...)
{
	va_list args;
	va_start(args, num);

	while (num--)
	{
		cout << va_arg(args, int) << endl;
	}
	va_end(args);
}

int main()
{
	func (3, 8, 7, 105);
}