/*****************************************************************************
* This example demonmtrates create and use smart pointers
*
* Этот пример демонстрирует создание и применение умных указателей
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

template <typename T>
class MP
{
private:
	T* t;
public:
	MP() : t(new T)
	{
		cout << "MP() " << this << " = " << t << endl;
	}

	MP(const MP<T>& mp) : t(new T(*mp.t))
	{
		cout << "MP() " << this << " = " << t << endl;
	}

	MP<T>& operator= (const MP<T>& mp)
	{
		if (&mp != this)
		{
			delete t;
			t = new T(*mp.t);
		}
		return *this;
	}

	T* operator-> () { return t; }
	T& operator* () { return *t; }

	~MP()
	{
		cout << "~MP() " << this << " = " << t << endl;
		delete t;
	}
};

class Foo {
	friend class MP<Foo>;
	char* str;
protected:
	Foo()
	{
		cout << "Foo() " << this << endl;
	}

	~Foo()
	{
		cout << "~Foo() " << this << endl;
	}
public:
	void init(char* _str)
	{
		str = _str;
	}
	void show() { cout << str << endl; }
};

int main()
{
	while (true)
	{
		MP<Foo> sp;
		sp->init("sp");
		sp->show();

		MP<Foo> sp2(sp);

		MP<Foo> sp3 = sp2;
		sp3->show();

		sp = sp3;

	}
	system("pause");
}