/*****************************************************************************
 * This example demonstrates the correction multiple inheritance
 *
 * Этот пример демонстрирует решение проблемы ромбовидного наследования
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

class Base {
	public:
	int i;
};

//class cl1 : virtual public Base {
class cl1 : public Base {
	public:
	int j;
};

//class cl2 : virtual public Base {
class cl2 : public Base {
	public:
	int k;
};


class cl3 : public cl1, public cl2 {
	public:
	int m;
};

int main()
{
	cl3 d;

	d.i = 10;
	//d.cl1::i = 10;

	d.j = 20;
	d.k = 30;
	d.m = 40;

	cout << d.i << " ";
	//cout << d.cl1::i << " ";

	cout << d.j << " " << d.k << " ";
	cout << d.m << endl;

	cl2 a;

	a.i = 100;

	cout << a.i << endl;
return 0;
}
