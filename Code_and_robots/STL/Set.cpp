/*****************************************************************************
 * This example demonstrates the use of the Set, Multiset, Unordered_set and Unordered_multiset containers STL
 *
 * Этот пример демонстрирует применение контейнеров Set, Multiset, Unordered_set и Unordered_multiset из STL
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
#include <set>
#include <unordered_set>

#include <algorithm>
#include <iterator>

using namespace std;

void show(int i)
{
	cout << i << ", ";
}

int main()
{
// SET
	set<int> st;

	if (st.empty())
		for (int i = 0; i < 5; i++)
			st.insert(i);

	for (int i = 0; i < 6; i++)
		st.emplace(i);											// Insert only 5

	cout << "Ms: " << st.max_size() << endl;					// The maximum possible size
	cout << "S: " << st.size() << endl;							// The actual size

	for_each(st.begin(), st.end(), show);cout << endl;
	for_each(st.rbegin(), st.rend(), show);cout << endl;

	//auto it = advance(st.begin(), 3);							// Forbidden

	st.emplace_hint(st.begin(), 50);							// Insert in back - Autosort
	//st.emplace_hint(st.end(), 50);							// Insert in back - Autosort
	cout << "Emplace_hint: ";
	for_each(st.begin(), st.end(), show);cout << endl;

	auto itFind = st.find(4);
	cout << "Find: ";
	cout << *itFind << endl;

//MultiSet

	multiset<int> mst; cout << endl;

	if (mst.empty())
		for (int i = 0; i < 5; i++)
			mst.insert(i);

	for (int i = 0; i < 6; i++)
		mst.emplace(i);											// Insert all

	cout << "Multiset: ";
	for_each(mst.begin(), mst.end(), show);cout << endl;

	auto eqr = mst.equal_range(3);
	cout << "Equal_range: ";
	for_each(eqr.first, eqr.second, show);cout << endl;

//Unordered_set

	unordered_set<int> ust; cout << endl;

	if (ust.empty())
		for (int i = 0; i < 5; i++)
			ust.insert(i);

	for (int i = 0; i < 6; i++)
		ust.emplace(i);

	cout << "Unordered_set: ";
	for_each(ust.begin(), ust.end(), show);cout << endl;

//Unordered_multiset

	unordered_multiset<int> umst; cout << endl;

	if (umst.empty())
		for (int i = 0; i < 5; i++)
			umst.insert(i);

	for (int i = 0; i < 6; i++)
		umst.emplace(i);

	cout << "Unordered_multiset: ";
	for_each(umst.begin(), umst.end(), show);cout << endl;

	cout << "Bucket_count: " << umst.bucket_count() << endl;
	cout << "Bucket_size: " << umst.bucket_size(3) << endl;				// Count elements in one bucket
	cout << "Num bucket for elem. 5: " << umst.bucket(5) << endl;

	unordered_multiset<char*> ums; cout << endl;
	auto fn = ums.hash_function();										// Get hash-function

	cout << "that: " << fn ((char*)"that") << endl;
	cout << "than: " << fn ((char*)"than") << endl;

	//umst.load_factor();												Return load factor (public member function)
	//umst.max_load_factor();											Get or set maximum load factor (public member function)
	//umst.rehash();													Set number of buckets (public member function )
	//umst.reserve();													Request a capacity change (public member function)
}
