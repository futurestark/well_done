/*****************************************************************************
 * This example demonmtrates use functors and predicates in C++
 *
 * Этот пример демонстрирует применение функторов и предикатов в C++
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

//Functors

template <typename T>
class SimpleFunctor {
	T name;
public:
	SimpleFunctor (const T name) : name(name)
	{}
	void operator()()
	{
		cout << "Hello, " << name << endl;
	}
};

class OtherFunctor {
	int even;
	int odd;
public:
	OtherFunctor() : even(0), odd(0)
	{}
	void operator()(int x)
	{
		if (x%2 == 0) even += x;
		else odd += x;
	}
	int even_sum() const { return even; }
	int odd_sum() const { return odd; }
};

//Predicate

bool evenPredicate (int x)
{
	return x % 2 ? false : true;
}

int main()
{
	SimpleFunctor<char*> sf((char*)"world");	//Create of functor
	sf();										//Call functor

	OtherFunctor of;							//Create of functor
	int list[] {1, 2, 3, 4, 5, 6, 7, 8, 9};

	for (int n : list)
	{
		of(n);									//Call functor
	}

	//Call functions of functor and use predicate
	cout << "Even: " << of.even_sum() << " | " << evenPredicate(of.even_sum()) << endl;
	cout << "Odd: " << of.odd_sum() << " | " << evenPredicate(of.odd_sum()) << endl;
}
