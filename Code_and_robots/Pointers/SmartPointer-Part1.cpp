/*****************************************************************************
 * This example shows how to independently create a simple smart pointer
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

template <typename Type>
class SmartPointer {
	Type *m_obj;
public:
	SmartPointer(Type *obj)
		: m_obj(obj)
	{}

	~SmartPointer()
	{
		delete m_obj;
	}

	Type* operator->() { return m_obj; }
	Type& operator* () { return *m_obj; }
};

class AnyClass
{
public:
	int *arr = new int[100];
	void init ()
	{
		for (int i = 0; i < 100; i++)
			arr[i] = i;
	}

	~AnyClass ()
	{
		delete[] arr;
	}
};

int main()
{
	while (1)
	{
		SmartPointer<AnyClass> sp(new AnyClass());
		sp->init();

		/* There will be a memory leak
		 * Код ниже приведет к утечкам памяти */
		
		/*AnyClass *ac = new AnyClass;
		ac->init();*/
	}
}
