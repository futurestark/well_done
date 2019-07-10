/*****************************************************************************
 * This example shows how to convert types using static_cast
 *
 * Этот пример демонстрирует преобразование типов с помощью static_cast
 *
 * Code&Robots site:       http://codrob.ru/
 * YouTube Channel:        https://www.youtube.com/channel/UCTGS5FRyz564wwiyNs8J54A
 * Social networks:        https://vk.com/codrob
 *                         https://www.facebook.com/groups/295824740787675/
 *
 * This example code is in public domain and licensed under MIT license
*****************************************************************************/

#include <iostream>

using namespace std;

int main()
{
	float a = 2.5;
	enum enumVar {one = 1, two = 2, three = 3};

	int enumCast = static_cast<int> (one);
	enumVar floatCast = static_cast<enumVar> (a);

	cout << enumCast << endl;		//int: 1
	cout << floatCast << endl;		//enumVar: two = 2

	char charVar = 250;				//char: -128 to 127
	cout << (int)charVar << endl;	//-6

	int intVar = static_cast<unsigned char> (charVar); //unsigned char: 0 to 255

	cout << intVar << endl;			//250
}