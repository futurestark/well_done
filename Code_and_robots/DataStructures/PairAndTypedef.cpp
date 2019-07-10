/*****************************************************************************
 * This example demonstrates the methods of application and work with the pair, make_pair and typedef
 *
 * Этот пример демонстрирует способы применения и работу с pair, make_pair и typedef
 *
 * Code&Robots site:       http://codrob.ru/
 * YouTube Channel:        https://www.youtube.com/channel/UCTGS5FRyz564wwiyNs8J54A
 * Social networks:        https://vk.com/codrob
 *                         https://www.facebook.com/groups/295824740787675/
 *
 * This example code is in public domain and licensed under MIT license
*****************************************************************************/

#include <iostream>
#include <utility>

using namespace std;

int main()
{
/* Simple example
 * Простой пример */

	/* Pair - The structure that holds 2 variables
	 * Pair - Структура, хранящая 2 переменные */
	pair<int, char> table (1, 'H');

	cout << table.first << endl;			//1
	cout << table.second << endl;			//H

	/* Creating cuts
	 * Создание сокращения */
	typedef pair<int, char> PairDef;

	//Analog:	pair<int, char> table2 (2, "J");
				PairDef table2 (2, 'J');

	cout << table2.first << endl;			//2
	cout << table2.second << endl;			//J

/* Changing the values of pair-variable
 * Изменение значений pair-переменной */

	/* You can using typedef
	 * Можно с использованием typedef */
	table2 = PairDef (10, 90);

	/* But better through make_pair
	 * Но лучше через make_pair */
	table2 = make_pair (10, 90);

	cout << table2.first << endl;			//10
	cout << table2.second << endl;			//Z

/* It is convenient to draw comparisons
 * Удобно производить сравнение */

	/* For single variables
	 * Для одиночных переменных */
	int x1, x2, y1, y2;

        if(x1 == x2 && y1 == y2) {} //Bad

	//For Pair
	typedef std::pair<int , int> cell;
	cell cell_1;
	cell cell_2;

        if(cell_1 == cell_2) {} //Good

/* Density
 * Компактность */

	/* Create a structure can be uncomfortable
	 * Создавать структуру может быть неудобно */
	struct product
	{
		int id;
		char* name;
		product();
		operator == (product);
		operator != (product);
	};

	/* Easier
	 * Проще */
        pair<int, char*> product;

/* You can use the pair when it is not expected to add to the 3rd variable (two-dimensional vector, name / surname, height / weight)
 Otherwise, if you need to add a third variable would have to spend a large refactoring code and create a structure
 * Можно использовать pair когда не предвидится добавление 3-й переменной (двухмерный вектор, имя / фамилия, рост / вес)
 Иначе, если нужно будет добавить 3-ю переменную придется проводить большой рефакторинг кода и создавать структуру */
}
