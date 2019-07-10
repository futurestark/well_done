/*****************************************************************************
 * This example demonmtrates the basics of iterators from STL
 *
 * Этот пример демонстрирует основы итераторов из STL
 *
 * Code&Robots site:       http://codrob.ru/
 * YouTube Channel:        https://www.youtube.com/channel/UCTGS5FRyz564wwiyNs8J54A
 * Social networks:        https://vk.com/codrob
 *                         https://www.facebook.com/groups/295824740787675/
 *
 * This example code is in public domain and licensed under MIT license
*****************************************************************************/

#include <iostream>

//STL
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
	typedef vector<int> vi;
	vi v;

	for (int i = 0; i < 15; i++)
		v.push_back(i);

	//Forward iterator
	cout << "Forward iterator: ";
	for (auto it = v.begin(); it != v.end() - 7; it++)
	{
		*it *= 10;
		cout << ", " << *it;
	} cout << endl;

	//Backward iterator
	cout << "Backward iterator: ";
	for (auto it = v.rbegin(); it != v.rend() - 7; it++)
	{
		*it *= 10;
		cout << ", " << *it;
	} cout << endl;

	//Const iterator
	cout << "Const iterator: ";
	for (auto it = v.cbegin(); it != v.cend() - 7; it++)
	{
		//*it *= 10; - Error!
		cout << ", " << *it;
	} cout << endl;

//Iterator operations

	//Advance
	{
		auto it = v.begin();
		advance(it, 10);	cout << *it << endl;
		advance(it, -5);	cout << *it << endl;
	}

	//Distance
	{
		auto it = v.begin();
		auto it2 = v.end();
		cout << "Dist: " << distance(it, it2) << endl;
	}

	//Iter_swap
	{
		auto it = v.begin();
		auto it2 = v.end()-1;
		iter_swap(it, it2);
		cout << "Iter_swap: " << *it << " | " << *it2 << endl;
	}

	//Begin
	{
		auto it = v.begin()+9;
		cout << "Begin before: " << *it << endl;
		it = begin(v);
		cout << "Begin after: " << *it << endl;
	}

	//End
	{
		auto it = v.begin()+7;
		cout << "End before: " << *it << endl;
		it = end(v);
		cout << "End after: " << *it << endl;
	}

	//Prev
	{
		auto it = v.end();
		auto ni = prev(it, 3);
		cout << "Prev: " << *ni << endl;
	}

	//Next
	{
		auto it = v.begin();
		auto ni = next(it, 6);
		cout << "Next: " << *ni << endl;
	}

//Iterator generators

	//Back_inserter or Front_inserter
	{
		vector<int> foo,bar;
		for (int i=1; i<=5; i++)
		{
			foo.push_back(i); bar.push_back(i*10);
		}
		copy (bar.begin(), bar.end(), back_inserter(foo));

		cout << "Back_inserter: ";
		for (int n : foo)										//In C++11
			  cout << n << ", ";
		cout << endl;
	}

	//Inserter
	{
		vector<int> v {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

		fill_n(inserter(v, v.begin()), 3, -1);

		cout << "Inserter: ";
		for (int n : v)
			  cout << n << ", ";
		cout << endl;
	}

	//Make_move_iterator
	{
		vector<string> s{"one", "two", "three"};

		vector<string> v1(s.begin(), s.end());												//Copy
		vector<string> v2(make_move_iterator(s.begin()), make_move_iterator(s.end()));		//Move only for objects

		cout << "v1 now holds: ";
		for(auto str : v1)
				cout << str << ", ";

		cout << endl << "v2 now holds: ";
		for(auto str : v2)
				cout << str << ", ";

		cout << endl << "Original vector now holds: ";
		for(auto str : s)
				cout << str << ", ";
		cout << endl;
	}
}
