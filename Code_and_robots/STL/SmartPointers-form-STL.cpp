/*****************************************************************************
* This example demonstrates use smart pointers from STL C++11
*
* Этот пример демонстрирует применение умных указателей из STL C++11
*
* Code&Robots site:       http://codrob.ru/
* YouTube Channel:        https://www.youtube.com/c/code_robots
* Social networks:        https://vk.com/codrob
*                         https://www.facebook.com/groups/295824740787675/
*
* This example code is in public domain and licensed under MIT license
*****************************************************************************/

#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

using namespace std;

struct Foo
{
	Foo() { cout << "Foo" << endl; }
	void show() { cout << "Hi" << endl; }
	~Foo() { cout << "~Foo" << endl; }
};

class DeleteFoo
{
public:
	void operator()(Foo* p) const
	{
		cout << "Call delete for Foo object" << endl;
		delete p;
	}
};

//C++11

int main()
{

//UNIQUE_PTR
	{
		//p1 is Foo
		unique_ptr<Foo> p1(new Foo);
		if (p1) p1->show();

		{
			//p2 is p1 (Foo), p1 - empty
			std::unique_ptr<Foo> p2(move(p1));
			if (!p1) cout << "p1 is empty" << endl;

			//Revert
			p1 = move(p2);
			if (!p2) cout << "p2 is empty" << endl;

			//No copy constructor
			//p1(p2);
		}

		if (p1) p1->show();
	}

//SHARED_PTR
	cout << endl << "shared_ptr: " << endl << endl;

	{
		//Сonstructor with no managed object
		shared_ptr<Foo> sh1;

		//Сonstructor with object
		//auto sh2 = std::make_shared<Foo>();
		shared_ptr<Foo> sh2(new Foo);
		
		//Copy pointer
		shared_ptr<Foo> sh3(sh2);

		//Count link on one object
		cout << sh2.use_count() << endl;
		cout << sh3.use_count() << endl;

		//Call methods from one object
		sh2->show();
		sh3->show();

		//Сonstructor with object and deleter
		shared_ptr<Foo> sh4(new Foo, DeleteFoo());
		//shared_ptr<Foo> sh4(new Foo, default_delete<Foo>());
	}

//DEFAULT_DELETE - functional object

	{
		//Unique_ptr<int> uses default_delete<int>
		unique_ptr<int> ptr1(new int(5));

		//Unique_ptr<int[]> uses default_delete<int[]>
		unique_ptr<int[]> ptr2(new int[10]);

		//The destructor calls delete[]
		shared_ptr<int> shared_good(new int[10], default_delete<int[]>());

		//Default_delete can be used anywhere a delete functor is needed
		vector<int*> v;
		for (int n = 0; n < 100; ++n)
			v.push_back(new int(n));
		for_each(v.begin(), v.end(), default_delete<int>());
	}

//WEAK_PTR
	cout << endl << "weak_ptr: " << endl << endl;

	{
		//Counter == 1, we created the object
		//And we have a strong pointer to it
		shared_ptr<Foo> a1(new Foo());

		//Counter == 2
		//We have two strong pointer to the same object
		shared_ptr<Foo> a2 = a1;

		//Counter == 2
		//We have two strong pointer to the same object
		//And one weak
		weak_ptr<Foo> w = a2;

		//Counter == 1, a strong pointer to the now empty
		//But the Foo object is alive and is accessible via a strong pointer a1
		//Because at the moment there is a strong pointer
		//Object (a1), then we can get out of a weak pointer strong
		a2.reset();

		//Counter == 2,
		//We got quite workable strong pointer of the weak
		a2 = w.lock();

		//Counter == 0, there is no strong indicator
		//The object is automatically dead when calling a1.reset ()
		a2.reset();
		a1.reset();

		//And the attempt to get strong from the weak pointer return an empty shared_ptr
		shared_ptr<Foo> a0 = w.lock();

		//This condition will be satisfied
		//a0.get() == 0;
	}

	system("pause");
}