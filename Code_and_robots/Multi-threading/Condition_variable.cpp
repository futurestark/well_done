/*****************************************************************************
* This example demonstrates how to create and work with multiple threads of program and use wait
*
* Этот пример демонстрирует создание и работу с несколькими потоками в программе с использованием прерываний
*
* Code&Robots site:       http://codrob.ru/
* YouTube Channel:        https://www.youtube.com/c/code_robots
* Social networks:        https://vk.com/codrob
*                         https://www.facebook.com/groups/295824740787675/
*
* This example code is in public domain and licensed under MIT license
*****************************************************************************/

#include <iostream>
#include <fstream>
#include <unistd.h>

#include <mutex>
#include <thread>
#include <condition_variable>

using namespace std;

mutex mtx;
condition_variable cv;

bool _var = false;
bool ret () { return _var;}

void foo ()
{
	ofstream log;
	string str;
	static int numFoo = 0;

	while (true)
	{
		std::unique_lock<mutex> ulm (mtx);
		cv.wait(ulm, ret);

		log.open("log.log", ios_base::app);
			str = "Is Foo: " + to_string(++numFoo) + '\n';
			log.write(str.c_str(), str.length());
		log.close();

		usleep(500000);
	}
}

void bar ()
{
	while (true)
	{
		char input;

		cout << "Input: "; cin >> input;
		cin.clear();

		if (input == 'y')
		{
			_var = true;
			cv.notify_one();
		}

		if (input == 'n')
			_var = false;
	}
}

int main ()
{
	thread t1 (bar);
	thread t2 (foo);

	t1.detach();
	t2.join();
}
