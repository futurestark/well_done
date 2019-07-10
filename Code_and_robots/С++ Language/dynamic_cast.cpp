/*****************************************************************************
 * This example shows how to convert types using dynamic_cast
 *
 * Этот пример демонстрирует преобразование типов с помощью dynamic_cast
 *
 * Code&Robots site:       http://codrob.ru/
 * YouTube Channel:        https://www.youtube.com/channel/UCTGS5FRyz564wwiyNs8J54A
 * Social networks:        https://vk.com/codrob
 *                         https://www.facebook.com/groups/295824740787675/
 *
 * This example code is in public domain and licensed under MIT license
*****************************************************************************/

#include <iostream>
#include <typeinfo>

using namespace std;

int main()
{
	/* It only works with references or pointers
	 * Работает только со ссылками или указателями */

	/* The pointer moves up the class hierarchy
	 * Восходящее приведение типа, указатель перемещается вверх по иерархии классов */
	class Base {
		virtual void foo() {}
	};
	class C : public Base {};
	class D : public C {};
	class Other {
		virtual void foo() {}
	};

	D* pd = new D;

	C* pc = dynamic_cast<C*>(pd);
	cout << typeid(pc).name() << endl;		//Type: C

	Base* pb = dynamic_cast<Base*>(pd);
	cout << typeid(pb).name() << endl;		//Type: Base

	/* It is impossible to carry out the conversion down the hierarchy of classes if the base class does not contain a virtual
	 * Нельзя проводить преобразование вниз по иерархии классов если базовый класс не содержит virtual */
	C* pbd = dynamic_cast<C*>(pb);			
	cout << typeid(pbd).name() << endl;		//Type: C

	/* Checking class at runtime
	 * Проверка класса во время выполнения программы */

	Other *otherPtr = new Other;

	if (dynamic_cast<Base*> (otherPtr))
		cout << "Base" << endl;
	else if (dynamic_cast<Other*> (otherPtr))
		cout << "Other" << endl;
}