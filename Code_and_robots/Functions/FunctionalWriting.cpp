/*****************************************************************************
 * This example shows how to implement functional writing in C++
 *
 * Этот пример демонстрирует как можно реализовать функциональную запись в C++
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
	int var;
public:
	int method () {return var = 1;}
	friend int funcMethod (Example exp) {return ++exp.var;}
};

int main()
{
	/* Normal writing of the PLO
	 * Обычная запись из ООП */
	Example exp;
	int var1;

	var1 = exp.method();
	cout << var1 << endl;

	/* Functional writing
	 * Функциональная запись */
	var1 = funcMethod(exp);
	cout << var1 << endl;
}
