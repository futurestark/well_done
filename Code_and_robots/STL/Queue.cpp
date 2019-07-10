/*****************************************************************************
 * This example demonstrates the use of the Queue and Priority_queue containers STL
 *
 * Этот пример демонстрирует применение контейнеров Queue и Priority_queue из STL
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
#include <queue>
#include <algorithm>
#include <iterator>

using namespace std;

void display(char* str)
{
	cout << str << endl;
}

int main()
{
	queue<char*> qu;
	queue<char*> qu2;

	if (qu.empty() || qu2.size() == 0)
	{
		qu.push((char*)"1 Push");
		qu.emplace((char*)"2 Emplace");
		qu.push((char*)"3 Push");

		qu2.push((char*)"4 Push");
		qu2.emplace((char*)"5 Emplace");
		qu2.push((char*)"6 Push");
	}

	qu.swap(qu2);

	while (!qu.empty())
	{
		//cout << qu.back() << endl;
		cout << qu.front() << endl;
		qu.pop();
	}

	cout << " --- DONE! --- " << endl;

	while (!qu2.empty())
	{
		cout << qu2.front() << endl;
		qu2.pop();
	}
	cout << " --- DONE! --- " << endl;

//Priority_queue

	priority_queue<int> prq;

	prq.emplace(15);
	prq.emplace(125);
	prq.emplace(83);
	prq.emplace(76);

	while (!prq.empty())
	{
		cout << prq.top() << endl;
		prq.pop();
	}
	cout << " --- DONE! --- " << endl;
}
