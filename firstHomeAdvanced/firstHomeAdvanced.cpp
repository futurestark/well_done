//#include <iostream>
//#include <vector>
//#include <list>
//#include <forward_list>
//#include <string>
//#include <cmath>
//#include <algorithm>
//#include <iterator>     //to use std::merge 

#include "firstHomeAdvanced.hpp"
int MAC (int x, int y, int & sum){
    sum += x * y;
    return sum;
}

int Square (int x){
    return x * x;
}
//forward declarations
// std::vector<int> combineVectors(const std::vector<int>::iterator firstVecBeg, const std::vector<int>::iterator firstVecEnd, const std::vector<int>::iterator secondVecBeg, const std::vector<int>::iterator secondVecEnd);
// std::forward_list<int> reverseFrowardList(std::forward_list<int> sourceForwardList);
// void printList(std::list<std::string> const& list);
// std::list<std::string> createNumber(int value, int powOfValue);

/* 
int main()
{
	// task 1 ------------------ vectors concationation ----------------------------
	std::vector<int> firstVector{ 5, 6, 7, 8, 9 };
	std::vector<int> secondVector{ 12, 13, 14, 15, 16 };

	std::vector<int> resultVector{ 0 };

	std::vector<int>::iterator itFirstVecBeg = firstVector.begin();
	std::vector<int>::iterator itFirstVecEnd = firstVector.end();
	std::vector<int>::iterator itSecondVecBeg = secondVector.begin();
	std::vector<int>::iterator itSecondVecEnd = secondVector.end();

	//resultVector.resize(firstVector.size() + secondVector.size());
	//resultVector.reserve(firstVector.size() + secondVector.size());
	resultVector = combineVectors(itFirstVecBeg, itFirstVecEnd, itSecondVecBeg, itSecondVecEnd);

	std::cout << "resultVectorSize " << resultVector.size() << std::endl;

	for (auto i : resultVector) { // access by value, type of i is int
		std::cout << i << ' ';
		std::cout << '\n';
	}

	// task 2  -------------------- list -------------------------------------------
		
	int value = 5, powOfValue = 6;
	std::cout << std::endl;
	//std::cout << "TASK 2 - creation number using list " << std::endl;
	//std::cout << std::endl;
	//std::cout << "	enter value to be pow : " << std::endl;
	//std::cin >> value;
	//std::cout << "	enter max pow for value: " << std::endl;
	//std::cin >> powOfValue;

	std::list<std::string> valuesList;

	valuesList = createNumber(value, powOfValue);

	std::cout << std::endl;
	std::cout << std::endl;

	//printList(valuesList);

	std::cout << std::endl;
		


	// task 3 -------------- forward list empty, create new & push front ------------
	std::forward_list<int> myforwardlist = { 1, 2, 3, 4, 5, 6, 7, 8 }, reversedForwardList;
	// myforwardlist.push_front(8);  need push front elements in cycle like this

	reversedForwardList = reverseFrowardList(myforwardlist);

	std::cout << std::endl;
	std::cout << "	reversed forward list is : " << std::endl;
	for (int i : reversedForwardList)
	{
		std::cout << i << " ";
	}
	

	return 0;
}
*/

std::vector<int> combineVectors(const std::vector<int>::iterator firstVecBeg, const std::vector<int>::iterator firstVecEnd, const std::vector<int>::iterator secondVecBeg, const std::vector<int>::iterator secondVecEnd)
{
	std::vector<int> combinedVector;
	//combinedVector.reserve(firstVecBeg.size() + secondVecBeg.size());

	//-------------------------------------- variant by inserting ---------------------------------------
	//combinedVector.insert(combinedVector.end(), firstVecBeg, firstVecEnd);
	//combinedVector.insert(combinedVector.end(), secondVecBeg, secondVecEnd);

	//-------------------------------------- variant by copying -----------------------------------------
	//std::copy(firstVecBeg, firstVecEnd, std::back_inserter(combinedVector));
	//std::copy(secondVecBeg, secondVecEnd, std::back_inserter(combinedVector));

	//-------------------------------------- variant by merge algorithm  --------------------------------
	
	std::merge(firstVecBeg, firstVecEnd,
		secondVecBeg, secondVecEnd,
		std::back_inserter(combinedVector));   // a esli vmesto std::back_inserter(combinedVector));  peredat prosto combinedVector.begin()  to runtime fail  why??####
												// v prototype merge 4 alocatora i posledniy out dest parametr, no prosto combinedVector on but ne mozhet ############

	//--------------------------------- variant assign one vector in another is not concationation !! ---
				//	combinedVector.assign(10, 1); // çàïîëíåíèå âåêòîðà èç 10 ýëåìåíòîâ ÷èñëîì 1
	//vect2.assign(vect1.begin(), vect1.end());    // shablon zagotovka dlya perepisi
	//combinedVector.assign(firstVecBeg, firstVecEnd);
	//combinedVector.assign(secondVecBeg, secondVecEnd);

	std::cout << "combinedVectorSize " << combinedVector.size() << std::endl;

	return combinedVector;
}

/* 
void printList(std::list<std::string> const& list) {

	std::cout << "	result number is :" << std::endl;
	std::for_each(list.begin(), list.end(),
		[](const auto& e) {
			std::cout << e;
		});
}
*/

std::list<std::string> createNumber(int value, int powOfValue) {

	std::list<std::string> valuesList;
	std::vector<int> vectorForList;
	bool flagCycleBegin = false;
	int powResult = 0;

	if (valuesList.empty()) {

		std::cout << "elements in vector and list are : " << std::endl;
		for (int i = 1; i <= powOfValue; i++)
		{
			powResult = pow(value, i);

			std::cout << powResult << std::endl;

			vectorForList.push_back(powResult);

			std::string listStr = std::to_string(powResult);
			std::string resultStr;

			std::cout << listStr.front() << std::endl;
			std::cout << listStr.back() << std::endl;

			resultStr = listStr.front();
			valuesList.push_back(resultStr);

			if (flagCycleBegin) {
				resultStr = listStr.back();
				valuesList.push_back(resultStr);
			}

			flagCycleBegin = true;

		}

		return valuesList;
	}
}

std::forward_list<int> reverseFrowardList(std::forward_list<int> & sourceForwardList) {      //peredalat 4erez ssilku

	std::forward_list<int>  newforwardlist{};

	while (!sourceForwardList.empty()) {
		newforwardlist.push_front(sourceForwardList.front());
		sourceForwardList.pop_front();
	}
	//for (auto it = newforwardlist.begin(); it != newforwardlist.end(); ++it)
	//	std::cout << ' ' << *it;

	return  newforwardlist;
}


/*
	Ïî ïîâîäó ïåðâîãî äç, ÿ îæèäàþ îò âàñ òðè ôóíêöèè:

	1. std::vector<int> combineVectors (const vector iterator begin1 (íàçâàíèÿ ñàìè âûáèðàéòå), const vector 
	iterator end1, const vector iterator begin2, const vector iterator3 end2)

	2. size_t magicNumber(const size_t number (N), const size_t degree (X));

	3. void reverse(std::forward_list& listToReverse) (îæèäàåòñÿ, ÷òî listToReverse áóäåò ìîäèôèöèðîâàí)

//checks that vector v is {5, 10, 15}
ASSERT_THAT(v, ElementsAre(5, 10, 15));

//checks that map m only have elements 1 => 10, 2 => 20
ASSERT_THAT(m, ElementsAre(Pair(1, 10), Pair(2, 20)));

//checks that in vector v all the elements are greater than 10 and less than 20
ASSERT_THAT(v, Each(AllOf(Gt(10), Lt(20))));

//checks that vector v consist of 
//   5, number greater than 10, anything.
ASSERT_THAT(v, ElementsAre(5, Gt(10), _));
*/


/*
  -------------------------------- THIS HELP VisualStudioCode instead Eclipse with gmock include so all right ----------------------
1

Gmock configuration [Eclipse Mar - Ubuntu 14.04 LTS]

Clone master resource from google github

git clone https://github.com/google/googletest.git GoogleTest/

Install Cmake:

sudo apt-get install cmake

Build master Gtest project by Cmake:

cd GoogleTest/googlemock

sudo cmake CMakeLists.txt

sudo make

we will get log information:

   Scanning dependencies of target gmock
    [ 14%] Building CXX object CMakeFiles/gmock.dir/home/thaohm2/FPT/Softs/GoogleTest/googletest/src/gtest-all.cc.o
    [ 28%] Building CXX object CMakeFiles/gmock.dir/src/gmock-all.cc.o
    Linking CXX static library libgmock.a
    [ 28%] Built target gmock
    Scanning dependencies of target gmock_main
    [ 42%] Building CXX object CMakeFiles/gmock_main.dir/home/thaohm2/FPT/Softs/GoogleTest/googletest/src/gtest-all.cc.o
    [ 57%] Building CXX object CMakeFiles/gmock_main.dir/src/gmock-all.cc.o
    [ 71%] Building CXX object CMakeFiles/gmock_main.dir/src/gmock_main.cc.o
    Linking CXX static library libgmock_main.a
    [ 71%] Built target gmock_main
    Scanning dependencies of target gtest
    [ 85%] Building CXX object gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o
    Linking CXX static library libgtest.a
    [ 85%] Built target gtest
    Scanning dependencies of target gtest_main
    [100%] Building CXX object gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o
    Linking CXX static library libgtest_main.a
    [100%] Built target gtest_main
Four static libraries are generate:
libgmock.a  libgmock_main.a  libgtest.a  libgtest_main.a
We need to copy all *.a files to /usr/lib:

sudo cp *.a /usr/lib

sudo cp gtest/*.a /usr/lib

And copy necessary libraries of gmock and gtest to /usr/include

sudo cp -r include/gmock /usr/include/

sudo cp -r ../googletest/include/gtest/ /usr/include/
Create a new C++ project and add "gmock" and "pthread" options to Linker library Right click on Project --> Properties --> C/C++ Builder --> Setting --> Tool Settings --> GCC C++ Linker --> Libraries Add... gmock pthread
Note that gmock must be frond of pthread in order.

Include gmock and gtest to your project and carry out compiling the project:

include
include
//...

int main(int argc, char *argv[]) { ::testing::InitGoogleMock(&argc, argv); return RUN_ALL_TESTS(); }

Output:

[==========] Running 0 tests from 0 test cases.
[==========] 0 tests from 0 test cases ran. (0 ms total)
[  PASSED  ] 0 tests.
Done.

*/

