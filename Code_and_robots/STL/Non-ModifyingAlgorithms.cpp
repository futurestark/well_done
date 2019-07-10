/*****************************************************************************
 * This example demonmtrates use non-modifying algorithms
 *
 * Этот пример демонстрирует применение не модифицирующих алгоритмов
 *
 * Code&Robots site:       http://codrob.ru/
 * YouTube Channel:        https://www.youtube.com/channel/UCTGS5FRyz564wwiyNs8J54A
 * Social networks:        https://vk.com/codrob
 *                         https://www.facebook.com/groups/295824740787675/
 *
 * This example code is in public domain and licensed under MIT license
*****************************************************************************/

#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> v;
	for (int i = 1; i < 15; i++) v.push_back(i);

//All_of - Returns true if pred returns true for all the elements in the range
//C++11

	if (all_of(v.begin(), v.end(), [](int x) { return x%2;} ))
		cout << "All the elements are even numbers." << endl;
	else cout << "Don't all the elements are even numbers." << endl;

//Any_of - Returns true if pred returns true for any of the elements in the range
//C++11

	if (any_of(v.begin(), v.end(), [](int x) { return x%2;} ))
		cout << "Any of the elements is even num." << endl;
	else cout << "Any of - Don't one." << endl;

//None_of - Returns true if pred returns false for all the elements in the range
//C++11

	if (none_of(v.begin(), v.end(), [](int x) { return x%20;} ))
		cout << "None_of - false all elements" << endl;
	else cout << "None_of - false don't all elements" << endl;

//For_each - Applies function to each of the elements in the range

	for_each(v.begin(), v.end(), [](int x) {cout << x << ", ";} );
	cout << endl;

//Find - Returns an iterator to the first element in the range

	{
		auto it = find(v.begin(), v.end(), 12);
		cout << "Find: " << *it << endl;
	}

//Find_if - Returns an iterator to the first element in the range for which pred returns true

	{
		auto it = find_if(v.begin(), v.end(), [](int x) {return x>9;} );
		cout << "Find_if: " << *it << endl;
	}

//Find_if_not - Returns an iterator to the first element in the range for which pred returns false
//C++11

	{
		auto it = find_if_not(v.begin(), v.end(), [](int x) {return x<7;} );
		cout << "Find_if_not: " << *it << endl;
	}

//Find_end - Searches the range for the last occurrence of the sequence defined by, and returns an iterator to its first element, or last1 if no occurrences are found.

	{
		int v1[] {1, 2, 3, 4, 4, 7, 8, 4, 4, 9, 10};
		int v2[] {4, 4};

		auto it = find_end(v1, v1+11, v2, v2+2, [](int a, int b) {return a==b;} );
		cout << "Find_end: " << *it << " | pos: " << distance(v1, it) << endl;
	}

//Find_first_of - Returns an iterator to the first element in the range that matches any of the elements. If no such element is found, the function returns last1.

	{
		int v1[] {1, 2, 3, 4, 4, 7, 8, 4, 4, 9, 10};
		int v2[] {4, 4};

		auto it = find_first_of(v1, v1+11, v2, v2+2, [](int a, int b) {return a==b;} );
		cout << "Find_first_of: " << *it << " | pos: " << distance(v1, it) << endl;
	}

//Adjacent_find - Searches the range for the first occurrence of two consecutive elements that match, and returns an iterator to the first of these two elements, or last if no such pair is found.

	{
		int v1[] {1, 2, 3, 4, 4, 7, 8, 4, 4, 9, 10};

		auto it = adjacent_find(v1, v1+11);
		cout << "Adjacent_find: " << *it << " | pos: " << distance(v1, it) << endl;
	}

//Count - Returns the number of elements in the range that compare equal to val.

	{
		int v[] {1, 2, 3, 3, 3, 3, 3};

		cout << "Count: " << count(v, v+7, 3) << endl;
	}

//Count_if - Returns the number of elements in the range for which pred is true.

	{
		int v[] {1, 2, 3, 3, 3, 3, 3};

		cout << "CountCount_if " << count_if(v, v+7, [] (int x) {return x<3;} ) << endl;
	}

//Mismatch - Compares the elements in the range 1 with those in the range beginning at 2, and returns the first element of both sequences that does not match.

	{
		int v1[] {1, 2, 3, 4, 4, 7, 8, 4, 4, 9, 10};
		int v2[] {1, 2, 3, 4, 50, 6, 7, 8, 9, 10};

		auto mypair = mismatch(v1, v1+11, v2);
		cout << "Mismatch: " << *mypair.second << " | dist: " << distance(v1, mypair.first) << endl;
	}

//Equal - Compares the elements in the range 1 with those in the range beginning at 2, and returns true if all of the elements in both ranges match.

	{
		int v1[] {1, 2, 3, 4, 4, 7, 8, 4, 4, 9, 10};
		int v2[] {1, 2, 3, 4, 50, 6, 7, 8, 9, 10};

		auto var = equal(v1, v1+11, v2/*, [](int a, int b) {return a==b;}*/ );
		cout << "Equal: " << var << endl;
	}

//Is_permutation - Compares the elements in the range 1 with those in the range beginning at 2, and returns true if all of the elements in both ranges match, even in a different order.
//C++11

	{
		int v1[] = {1,2,3,4,5};
		int v2[] = {3,1,4,5,2};

		if (is_permutation (v1, v1+5, v2))
			cout << "v1 and v2 contain the same elements" << endl;
	}

//Search - Searches the range [first1,last1) for the first occurrence of the sequence defined by [first2,last2), and returns an iterator to its first element, or last1 if no occurrences are found.

	{
		std::string str1("It is my string");
		char* str2("str");

		cout << "Search: " << distance(str1.begin(), search(str1.begin(), str1.end(), str2, str2+3)) << endl;
	}

//Search_n - Searches the range [first,last) for a sequence of count elements, each comparing equal to val.

	{
		int v1[] {1, 5, 7, 4, 2, 2, 2, 3, 4, 4};

		//Searching: {2, 2, 2}
		auto it = search_n (begin(v1), end(v1), 3, 2);

		cout << "Search_n: " << *it << " | " << distance(v1, it) << endl;
	}
}
