/*****************************************************************************
 * This example illustrates a basic STL
 *
 * Этот пример демонстрирует основы STL
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
#include <algorithm>
#include <iterator>

using namespace std;

void display(char* str)
{
	cout << str << endl;
}

int main()
{
	/* Initialization STL container vector values
	 * Инициализация значениями контейнера STL: vector */
	vector<char*> arrString;

	arrString.push_back((char*)"String 1");
	arrString.push_back((char*)"String 2");
	arrString.push_back((char*)"String 3");
	arrString.push_back((char*)"String 4");
	arrString.push_back((char*)"String 5");

	/* Create iterators
	 * Создание итераторов */
	vector<char*>::iterator iterStart = arrString.begin();
	vector<char*>::iterator iterEnd = arrString.end();

	/* The use of an algorithm
	 * Применение алгоритма */
	for_each(iterStart, iterEnd, display);
}
