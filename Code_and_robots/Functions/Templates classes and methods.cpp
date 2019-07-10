/*****************************************************************************
 * This example demonstrates the implementation and application of the template functions and classes
 *
 * Этот пример демонстрирует реализацию и применение шаблонных функций и классов
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

/* Simple template function swaps the values of 2 variables of any type for which conversion is possible
 * Простейшая шаблонная функция, меняет местами значения 2-х переменных любых типов, для которых возможно преобразование */

/* Announcement function prototype
 * Объявление прототипа функции */
template <typename Tfunc1, typename Tfunc2>
void swap (Tfunc1& first, Tfunc2& second);

/* Implementation of template function
 * Реализация шаблонной функции */
template <typename Tfunc1, typename Tfunc2>
void swap (Tfunc1& first, Tfunc2& second)
{
	Tfunc1 temp = first;
	first = (Tfunc1)second;
	second = (Tfunc2)temp;
}

/* The simplest example of a template class
 * Простейший пример шаблонного класса */
template <typename Type1, typename Type2>
class ExamplePair
{
	Type1 first;
	Type2 second;
public:
	ExamplePair (Type1 first, Type2 second)
		: first(first),
		  second(second)
	{}

	/* Gaining access to the link variables
	 * Получение доступа к переменным по ссылке */
	Type1& First();
	Type2& Second();

	/* Setting values
	 * Установка значений */
	Type1 First(Type1 setFirst);
	Type2 Second(Type2 setSecond);
};

/* Declaring class methods beyond
 * Объявление методов класса за его пределами */
template <typename Type1, typename Type2>
Type1& ExamplePair<Type1, Type2>::First()
{
	return first;
}

template <typename Type1, typename Type2>
Type1 ExamplePair<Type1, Type2>::First(Type1 setFirst)
{
	first = setFirst;
	return first;
}

template <typename Type1, typename Type2>
Type2& ExamplePair<Type1, Type2>::Second()
{
	return second;
}

template <typename Type1, typename Type2>
Type2 ExamplePair<Type1, Type2>::Second(Type2 setSecond)
{
	second = setSecond;
	return second;
}

int main()
{
	int a1 = 10;
	float a2 = 3.1415;

	/* Recommended post:
	 * Рекомендуемая запись:
	swap<int, char> (a1, a2); */
	swap (a1, a2);


	cout << a1 << " | " << a2 << endl; //3 | 10

	ExamplePair<int, char> Exp (10, 'c');

	cout << Exp.First() << endl;			//10
	cout << Exp.Second() << endl;			//c

	cout << (Exp.First() = 30) << endl;		//30
	cout << (Exp.Second() = 't') << endl;	//t
	cout << Exp.First(90) << endl;			//90
	cout << Exp.Second('d') << endl;		//d

		cout << "\nSwaping :\n\n";

	/* Integer 90 matches the character Z
	 A character in the corresponding integer 100
	 * Целое число 90 соответствует символу Z
	 А Символ d соответствует  целому числу 100 */
	swap<int, char> (Exp.First(), Exp.Second());

	cout << Exp.First() << endl;			//100
	cout << Exp.Second() << endl;			//Z
}
