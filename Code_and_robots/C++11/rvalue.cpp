/*****************************************************************************
 * This example demonstrates use rvalue link
 *
 * Этот пример демонстрирует использование rvalue ссылок
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

int x = 10;

int& getLlavue ()
{
	return x;
}

int getRlavue (int x)
{
	return x;
}

template <typename T>
void print (T&& x)
{
	cout << "Rv: " << x << endl;
}

string getStr ()
{
	string str = "BigData";
	string& lnk = str;
	return lnk;
}

int main ()
{
	{
		int a = 0;

		//45 - rvalue
		//a = lvalue

		a = a;
		a = 45;
		//45 = a;

		getLlavue() = getRlavue(25);
		cout << x << endl;
		//getRlavue(x) = getLlavue(25); //Error

		print<int> (45);
		//print (a); //Error

		print <string> (getStr());
	}

	//Вариант обмена без перемещений, создание лишних копий
	{
		int a = 10, b = 20;

		int tmp = a;					//сейчас мы имеем две копии объекта a
		a = b;							//теперь у нас есть две копии объекта b
		b = tmp;						//теперь у нас две копии объекта tmp (т.е. a)
	}

	//Идеальная передача (перемещения, perfect forwarding)
	//Не происходит вызов конструктора копирования
	{
		int a = 10, b;

		int tmp = std::move(a);			//В a больше ничего не лежит, а ПЕРЕМЕЩЕНО в tmp
		a = std::move(b);				//В b теперь пусто, в а лежит значение которое было в b
		b = std::move(tmp);				//В tmp теперь пусто, в b лежит значение из tmp, оно же из а
	}
}
