/*****************************************************************************
 * This example demonstrates work of virtual methods and pure virtual methods
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

class Employee
{
private:
//Creating virtual method
	/*virtual char* display ()
	{
		return "It's base class.";
	}*/
/* The base class does not need the implementation of this method, but this method must be overridden in derived classes, so it is necessary to declare a pure virtual method. This will make abstract class because You can not create an object of class whose method will never be the implementation, it is realized only in derived classes.
 * В базовом классе не нужна реализация этого метода, но этот метод обязательно должен быть переопределен в производных классах, поэтому его нужно объявить чисто виртуальным. Это сделает класс абстактным, т.к. нельзя создавать объект класса, чей метод никогда не будет иметь реализации, он реализуется только в производных классах. */
	virtual char* display () = 0;
public:
	Employee ()
	{}
	void run ()
	{
		cout << "Run: " << display() << endl;
	}
};

class Designer : public Employee
{
private:
	/* To display this inscription, the display method in the class Employee must be virtual
	 * Чтобы отобразить эту надпись, метод отображения в классе Employee должен быть виртуальным */
	char* display ()
	{
		return "Designer.";
	}
};

class Programmer : public Employee
{
private:
	/* To display this inscription, the display method in the class Employee must be virtual
	 * Чтобы отобразить эту надпись, метод отображения в классе Employee должен быть виртуальным */
	char* display ()
	{
		return "Programmer.";
	}
};

int main()
{
	/* If the display method is pure virtual in the class Employee - you can not create an object of that class
	 * Если метод display чисто виртуальный в классе Employee - нельзя создавать объект этого класса */
	//Employee empl;
	Designer des;
	Programmer prog;

	//If display does not virtual method, 3 times will be displayed: "Run: It's base class."
	//empl.run();
	des.run();
	prog.run();

	/* If display is virtual method, despite the fact that pointers are of type Employee, the display method will be called from the derived class. If display does not virtual method, even if the pointers are created by the type of object, the method will be called from class Employee
	 * Если display виртуальный метод, несмотря на то, что указатели типа Employee, метод display будет вызываться из производного класса. Если display не виртуальный метод и указатели создаются по типу объекта, метод будет вызываться из класса Employee */

	/* If the display method is pure virtual in the class Employee - you can not create an object of that class
	 * Если метод display чисто виртуальный в классе Employee - нельзя создавать объект этого класса */

	/*Employee *ptrEmployee = &empl;
	Employee *ptrDesigner = &des;
	Employee *ptrProgrammer = &prog;

	ptrEmployee->run();
	ptrDesigner->run();
	ptrProgrammer->run();*/
}
