/*****************************************************************************
 * This example demonmtrates use lambda expressions
 *
 * Этот пример демонстрирует применение лямбда выражений
 *
 * Code&Robots site:       http://codrob.ru/
 * YouTube Channel:        https://www.youtube.com/channel/UCTGS5FRyz564wwiyNs8J54A
 * Social networks:        https://vk.com/codrob
 *                         https://www.facebook.com/groups/295824740787675/
 *
 * This example code is in public domain and licensed under MIT license
*****************************************************************************/

#include <iostream>
#include <functional>

#include <algorithm>

using namespace std;



int main()
{
//Simple lambda expression

	auto hello = []()													//Assign the lambda expression
	//function<string()> hello = []()
	{
		static int num = 0;
		cout << "hello: " << num << " " << endl;
		++num;

		return "return";
	};

	hello;								//Empty
	cout << hello << endl;				//1
	hello();							//hello: 0
	cout << hello() << endl << endl;	//hello: 0 return

	auto sum1 = [](int x, int y) { return x + y; };						//Assign other the lambda expression
	cout << sum1(2, 3) << endl;

	function<int(int, int)> sum2 = [](int x, int y) { return x + y; };	//Assign the same lambda expression to a function object
	cout << sum2(3, 4) << endl;

//Passing arguments in the expression

	int i = 3;
	int j = 5;

	function<int (void)> paite = [i, &j] { return i + j; };
	//auto paite = [i, &j] { return i + j; };

	i = 22;
	j = 44;

	cout << "paite(): " << paite() << endl;

//Create lambda expression with arguments

	int aod = [] (int x, int y) { return x + y; }(5, 4);
	cout << "aod: " << aod << endl;

//Lambda expression like arguments of function

	{
		int arr[] {1, 2, 3, 4, 5};

		cout << "In for_each: ";
		for_each(arr, arr+5, [](int x) {cout << x << ", ";} );
		cout << endl;
	}

//The following lambda expression contains a nested lambda

		int timestwoplusthree = [](int x) { return [](int y) { return y * 2; }(x) + 3; }(5);
		cout << timestwoplusthree << endl;		//13

//Lambda higher-order functions

	auto addtwointegers = [](int x)
	{
		// Return lambda expression
		return [=](int y) { return x + y; };
	};

	auto higherorder = [](const function<int(int)>& f, int z)
	{
		return f(z) * 2;
	};

	auto answer = higherorder(addtwointegers(7), 8);

	cout << answer << endl;
}
