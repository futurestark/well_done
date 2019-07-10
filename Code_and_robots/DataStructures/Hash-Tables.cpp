/*****************************************************************************
* This example demonstrates how to create and work hash-tables
*
* Этот пример демонстрирует создание и работу с хеш-таблицами
*
* Code&Robots site:       http://codrob.ru/
* YouTube Channel:        https://www.youtube.com/c/code_robots
* Social networks:        https://vk.com/codrob
*                         https://www.facebook.com/groups/295824740787675/
*
* This example code is in public domain and licensed under MIT license
*****************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

template <typename T>
class HashTable
{
	int count_bucket;
	int count_el;

	vector<T>* table;
	int hash_dev(T);
	int hash_mul(T);

public:
	HashTable (int count_bucket) : count_bucket(count_bucket), count_el(0)
	{
		table = new vector<T>[count_bucket];
	}

	bool check(T);
	int set(T);
	const vector<T>& get_bucket(int);
	bool empty();
	void clear();
	int c_bucket();
	int c_el();
};

template <typename T>
int HashTable<T>::hash_dev(T num)
{
	return num % count_bucket;
}

template <typename T>
int HashTable<T>::hash_mul(T num)
{
	double a = 0.618033;
	return count_bucket * fmod(num * a, 1);
}

template <typename T>
bool HashTable<T>::check(T el)
{
	//int hash = hash_dev(el);
	int hash = hash_mul(el);
	auto it = find(table[hash].begin(), table[hash].end(), el);

	if (it != table[hash].end())
		return true;
	return false;
}

template <typename T>
int HashTable<T>::set(T el)
{
	//int hash = hash_dev(el);
	int hash = hash_mul(el);
	auto it = find(table[hash].begin(), table[hash].end(), el);

	if (it == table[hash].end())
	{
		table[hash].push_back(el);
		count_el++;
	}

	return hash;
}

template <typename T>
const vector<T>& HashTable<T>::get_bucket(int b)
{
	return table[b];
}

template <typename T>
bool HashTable<T>::empty()
{
	return !count_el;
}

template <typename T>
void HashTable<T>::clear()
{
	for_each(table, table + count_bucket, [](vector<T>& n){ n.clear(); });
	count_el = 0;
}
template <typename T>
int HashTable<T>::c_bucket()
{
	return count_bucket;
}

template <typename T>
int HashTable<T>::c_el()
{
	return count_el;
}

int main()
{
	HashTable<int> hash(5);

	cout << "Empty? " << std::boolalpha << hash.empty() << endl << endl;

	for (int i = 0; i < 58; i += 3)
		cout << i << " in bucket: " << hash.set(i) << endl;

	//hash.clear();

	for (int i = 0; i < 5; i++)
	{
		cout << "Is bucket " << i << ": ";
			for_each(hash.get_bucket(i).begin(), hash.get_bucket(i).end(), [](int n){ cout << "\t" << n << ", "; });
		cout << endl;
	}

	cout << endl << "Exist number 5? - " << hash.check(5) << endl;
	cout << "Where number 9? - " << hash.check(9) << endl;
	cout << "Count of bucket: " << hash.c_bucket() << endl;
	cout << "Count of elements: " << hash.c_el() << endl;
	cout << "Empty? " << std::boolalpha << hash.empty() << endl;
}
