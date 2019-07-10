/*****************************************************************************
* This example demonstrates how to create and use their own iterators
*
* Этот пример демонстрирует создание и применение своих итераторов
*
* Code&Robots site:       http://codrob.ru/
* YouTube Channel:        https://www.youtube.com/c/code_robots
* Social networks:        https://vk.com/codrob
*                         https://www.facebook.com/groups/295824740787675/
*
* This example code is in public domain and licensed under MIT license
*****************************************************************************/

#include <iostream>

using namespace std;

template <typename T>
class MyArray
{
	T* arr;
	int _n;
public:
	class Iterator;
	MyArray(int n = 1) : _n(n)
	{
		arr = new T[n];
	}

	T& operator[] (const int& n)
	{
		if (n > 0 && n < _n)
			return arr[n];
		return arr[0];
	}

	Iterator begin() { return arr; }
	Iterator end() { return arr+_n; }

	friend ostream& operator<< (ostream& s, const MyArray<T>& n);

	class Iterator
	{
		T* cur;
	public:
		Iterator(T* first) : cur(first)
		{}

		T& operator+ (int n) { return *(cur + n); }
		T& operator- (int n) { return *(cur - n); }

		T& operator++ (int) { return *cur++; }
		T& operator-- (int) { return *cur--; }
		T& operator++ () { return *++cur; }
		T& operator-- () { return *--cur; }

		bool operator!= (const Iterator& it) { return cur != it.cur; }
		bool operator== (const Iterator& it) { return cur == it.cur; }
		T& operator* () { return *cur; }
	};
};

template <typename T>
ostream& operator<< (ostream& s, const MyArray<T>& n)
{
	s << arr[n];
	return s;
}

int main()
{
	MyArray<char*> arr(3);
	arr[0] = "str1";
	arr[1] = "str2";
	arr[2] = "str3";

	auto it = MyArray<char*>::Iterator(arr.begin());
	
	cout << "2: " << it + 2 << endl;

	while (it != arr.end())
	{
		cout << *it << endl;
		it++;
	}
	
	system("pause");
};