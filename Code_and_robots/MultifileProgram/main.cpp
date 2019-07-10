/*****************************************************************************
 *
 *
 * Этот пример демонстрирует как разрабатываются многофайловые программы
 *
 * Code&Robots site:       http://codrob.ru/
 * YouTube Channel:        https://www.youtube.com/channel/UCTGS5FRyz564wwiyNs8J54A
 * Social networks:        https://vk.com/codrob
 *                         https://www.facebook.com/groups/295824740787675/
 *
 * This example code is in public domain and licensed under MIT license
*****************************************************************************/

#include <iostream>
#include "example.h"

using namespace std;

int main()
{
	myExample::Example<int> exp (15, 32);

	cout << exp.First() << endl;
	cout << exp.Second() << endl;
	cout << (exp.First() = 100) << endl;
	cout << (exp.Second() = 200) << endl;
}
