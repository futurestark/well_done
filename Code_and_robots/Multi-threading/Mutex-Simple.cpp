/*****************************************************************************
* This example demonstrates how to create and work with multiple threads of program and use muxex
*
* Этот пример демонстрирует создание и работу с несколькими потоками в программе с использованием мьютексов
*
* Code&Robots site:       http://codrob.ru/
* YouTube Channel:        https://www.youtube.com/c/code_robots
* Social networks:        https://vk.com/codrob
*                         https://www.facebook.com/groups/295824740787675/
*
* This example code is in public domain and licensed under MIT license
*****************************************************************************/

#include <iostream>
#include <unistd.h>

#include <vector>

#include <mutex>
#include <thread>

using namespace std;

void foo (int& num, mutex& mtx)
{
	while (1)
	{
		mtx.lock();
		num += 2;
		cout << "Foo: " << num << endl;
		mtx.unlock();

		//If you comment out the one thread will run several times in a row
		usleep(50000);
	}
}

void bar (int& num, mutex& mtx)
{
	while (1)
	{
		//If you remove the lock synchronization will be lost

		mtx.lock();
		num -= 2;
		cout << "Bar: " << num << endl;
		mtx.unlock();

		usleep(50000);
	}
}

int main ()
{
	int num = 10;
	mutex mtx;

	thread t1 (foo, ref(num), ref(mtx));
	thread t2 (bar, ref(num), ref(mtx));

	t1.join();
	t2.join();
}

