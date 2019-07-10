/*****************************************************************************
 * This example demonstrates how the error handling via try designs, catch, throw
 *
 * Этот пример демонстрирует способы обработки ошибок с помощью конструкций try, catch, throw
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

/* Create an abstract error handling class, just as an example
 * Создадим абстрактный класс обработки ошибок, просто для примера */
class Exception
{
protected:
	int num;
	char* str;
public:
	virtual void display () = 0;
};

/* A global class to handle errors
 * Некий глобальный класс для обработки ошибок */
class OtherException : public Exception
{
public:
	OtherException (int num, char* str)
	{
		this->num = num;
		this->str = str;
	}

	void display ()
	{
		cout << "OtherException! - #" << num << ", " << str << endl;
	}
};

class Math
{
	/* Error handling class only in the class Math
	 * Класс обработки ошибок только в классе Math*/
	class ExceptionMath : public Exception
	{
	public:
		ExceptionMath (int num, char* str)
		{
			this->num = num;
			this->str = str;
		}

		void display ()
		{
			cout << "Exception! - #" << num << ", " << str << endl;
		}
	};
public:
	float Division (float v1, float v2);
	int Multiplication (int v1, int v2);
};

float Math::Division(float v1, float v2)
{
	try
	{
		/* It creates an object of class ExceptionMath, which is transferred to the catch block
		 * Создается объект класса ExceptionMath, который передается в блок catch */
		if (v2 == 0)
			throw ExceptionMath(0, (char*)"Division by zero");

		/* It creates an object of class OtherException, which is transferred to the catch block
		 * Создается объект класса OtherException, который передается в блок catch */
		if (v2 == 666 || v1 == 666)
			throw OtherException(333, (char*)"Are you sure you want to division the number of the devil?");
		return v1 / v2;
	}
	/* The unit below takes only exception type ExceptionMath
	 * Блок ниже принимает исключения только типа ExceptionMath */
	catch (ExceptionMath exp)
	{
		exp.display();
		return (float)NULL;
	}
	/* The unit below takes only exception type OtherException
	 * Блок ниже принимает исключения только типа OtherException */
	catch (OtherException exp)
	{
		exp.display();
		return (float)NULL;
	}
}

int Math::Multiplication(int v1, int v2)
{
	try
	{
		if (v2 == 1 || v1 == 1)
			throw ExceptionMath(1, (char*)"What fool would be multiplied by one?");
		if (v2 == 666 || v1 == 666)
			throw OtherException(333, (char*)"Are you sure you want to multiply the number of the devil?");
		return v1 * v2;
	}
	catch (ExceptionMath exp)
	{
		exp.display();
		return (int)NULL;
	}
	catch (OtherException exp)
	{
		exp.display();
		return (float)NULL;
	}
}

int main()
{
	Math m;

	cout << m.Multiplication(10, 15) << endl;	//150
	cout << m.Division(10, 15) << endl;			//0.6(6)

	cout << m.Multiplication(10, 1) << endl;	//Exception! - #1, What fool would be multiplied by one?
	cout << m.Multiplication(1, 55) << endl;	//Exception! - #1, What fool would be multiplied by one?
	cout << m.Division(10, 0) << endl;			//Exception! - #0, Division by zero

	cout << m.Multiplication(10, 666) << endl;	//OtherException! - #333, Are you sure you want to multiply the number of the devil?
	cout << m.Division(5519, 666) << endl;		//OtherException! - #333, Are you sure you want to division the number of the devil?
}
