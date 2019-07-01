#include <iostream>
#include <cmath>
#include <stdio.h>  // to uppercase
#include <assert.h> // for asserts in uppercase
#include <ctime> // Home_5 this header to generate srand func by time elements of array to be sort
#include <time.h>  // for compare time to execute sort functions
#include <chrono>  //the same compare time
#include <cstring>  //for strlen to count str_size from cin for paste to function	
	
//--------------------------------------- HOME_5 --------------------------------
void bubbleSort(int*, int); // forward declaration, body of func is after main fucn
void quicksort(int* s_arr, int first_el, int last_el);
//-------------------------------------------------------------------------------	
	
int main(const int const argc, const char* const argv[])    //this correct arg types must be
{	
	srand(time(NULL));
	std::cout << "enter arr size for bublesort: ";
	int size_array_bubble; 
	std::cin >> size_array_bubble;

	int* sorted_array_bubble = new int[size_array_bubble]; // arr in heap
	for (int counter = 0; counter < size_array_bubble; counter++)
	{
		sorted_array_bubble[counter] = rand() % 100; // fill arr with random numbers
		std::cout  << sorted_array_bubble[counter] << "  "; // print generated arr
	}
	std::cout << "\n\n";

	//time_t start_bubble_sort = 0, end_bubble_sort = 0;  //start clock for bubble sort
	//time(&start_bubble_sort);
	auto begin = std::chrono::steady_clock::now();
	bubbleSort(sorted_array_bubble, size_array_bubble); // call bubble sort
	auto end = std::chrono::steady_clock::now();
	//time(&end_bubble_sort);
	//double bubble_sort_take_seconds = difftime(end_bubble_sort, start_bubble_sort);
	//std::cout << "execution time bubble sort is :" << bubble_sort_take_seconds << std::endl;
	auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
	std::cout << "The time: " << elapsed_ms.count() << " ms\n";

	for (int counter = 0; counter < size_array_bubble; counter++)
	{
		std::cout << sorted_array_bubble[counter] << "  "; // print sorted arr
	}
	std::cout << "\n";
	
	//---------------------------------------------------------------------------------------

	//-------------------------------------------- quick sort -------------------------------

	srand(time(NULL));
	int first_qs_arr_el = 0, last_qs_arr_el = 0;
	int size_array_quicksort;

	std::cout << "enter arr size for quicksort: " << std::endl;;   
	std::cin >> size_array_quicksort;

	std::cout << "enter index of first arr element: " << std::endl;   
	std::cin >> first_qs_arr_el;

	std::cout << "enter index of last arr element: " << std::endl;   
	std::cin >> last_qs_arr_el;

	int* sorted_array_quicksort = new int[size_array_quicksort]; // create arr in heap
	for (int counter = 0; counter < size_array_quicksort; counter++)
	{
		sorted_array_quicksort[counter] = rand() % 100; // fill arr with random numbers
		std::cout << sorted_array_quicksort[counter] << "  "; // print generated arr
	}
	std::cout << "\n\n";

	time_t start_quick_sort = 0, end_quick_sort = 0;  //start clock for bublesort
	time(&start_quick_sort);
	quicksort(sorted_array_quicksort, first_qs_arr_el, last_qs_arr_el); //firts el 0 last el 19    
	time(&end_quick_sort);

	for (int counter = 0; counter < size_array_quicksort; counter++)
	{
		std::cout << sorted_array_quicksort[counter] << "  "; // print sorted arr
	}
	std::cout << "\n";
	double quick_sort_take_seconds = difftime(end_quick_sort, start_quick_sort);
	std::cout << "execution time quick sort is :" << quick_sort_take_seconds << std::endl;
	
	return 0;
}

//------------------------------------------ SORT FUNC -----------------------------
void bubbleSort(int* arrPtr, int len_arr)
{
	int temp_arr_index = 0;
	bool flag_arr_sorted = false;

	while (!flag_arr_sorted) //пока не отсортирован сортируем
	{
		flag_arr_sorted = true;
		for (int int_counter = 0; int_counter < (len_arr - 1); int_counter++)

			if (arrPtr[int_counter] > arrPtr[int_counter + 1]) // сравниваем два соседних элемента ( > по возрастанию) ( < по убыванию)
			{
				// raplace elements
				temp_arr_index = arrPtr[int_counter];
				arrPtr[int_counter] = arrPtr[int_counter + 1];
				arrPtr[int_counter + 1] = temp_arr_index;
				flag_arr_sorted = false; // на очередной итерации была произведена перестановка элементов
			}
	}
}

void quicksort(int* s_arr, int first_el, int last_el)
{
	if (first_el < last_el)
	{
		int left = first_el, right = last_el, middle = s_arr[(left + right) / 2];
		do
		{
			while (s_arr[left] < middle) left++;
			while (s_arr[right] > middle) right--;
			if (left <= right)
			{
				int tmp = s_arr[left];
				s_arr[left] = s_arr[right];
				s_arr[right] = tmp;
				left++;
				right--;
			}
		} while (left <= right);
		quicksort(s_arr, first_el, right);
		quicksort(s_arr, left, last_el);
	}
}
//------------------------------------------------------------------------------