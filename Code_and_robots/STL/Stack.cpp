/*****************************************************************************
 * This example demonstrates the use of the Stack container STL
 *
 * Этот пример демонстрирует применение контейнера Stack из STL
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
#include <stack>

using namespace std;

void display(char* str)
{
	cout << str << endl;
}

int main()
{
	stack<char*> st;
	stack<char*> st2;

	if (st.empty() || st2.size() == 0)
	{
		st.push((char*)"1 Push");
		st.emplace((char*)"2 Emplace");

		st2.push((char*)"3 Push");
		st2.emplace((char*)"4 Emplace");
	}

	st.swap(st2);

	while (!st.empty())
	{
		cout << st.top() << endl;
		st.pop();
	}

	cout << " --- DONE! --- " << endl;

	while (!st2.empty())
	{
		cout << st2.top() << endl;
		st2.pop();
	}
	cout << " --- DONE! --- " << endl;
}
