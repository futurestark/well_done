//after structurized project close VSCode, OpenAgain,  Shift+Ctrl+P command pallete
//it will ask use cmake build - Yes, tab to OUTPUT, select ExampleTests.cpp and press molotok build -> will begin cmake build process
// https://www.youtube.com/watch?v=Lp1ifh9TuFI&list=PLzjmU_6e7Lj2DtwOh_pcwr9sNAPjPtLnX&index=652&t=0s

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../firstHomeAdvanced.hpp"

//using ::testing::Test; 
//------------------ usual two tests -----------------------
// !!!! to run rest -> shift+ctrl+P -> Cmake Run tests
/*

   
TEST(ExampleTests, DemonstrateGTestMacros){
    
    //EXPECT_TRUE(false);

    //ASSERT_TRUE(true); //ASSERT is more strict version of EXPECT (bolee zhostakaya esli test ASSERT ne proshli dalshe ne idem) 
                        // posle ASSERT_TRUE - EXPECT_TRUE uzhe vipolnyatsa ne budet, srazu break i logtest v terminal
    //EXPECT_TRUE(false);
    EXPECT_EQ(true, true);  // compare two condition, here true is equal to true :)
    
    const bool result = f();
    EXPECT_EQ(true, result) << "Side Effect " << sideEffect << std::endl;

    for (int i = 0; i < 16; ++i)
     EXPECT_EQ(true, result) << "i = " << i << std::endl;
    */

TEST(ExampleTests, combineVectors){ 
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

    //EXPECT_THAT(resultVector, ::testing::UnorderedElementsAreArray(testVector)); 
    ASSERT_THAT(resultVector, ::testing::ElementsAre(5, 6, 7, 8, 9, 12, 13, 14, 15, 16));
}

TEST(ExampleTests, reverseFrowardList){ 
   
	std::forward_list<int> myforwardlist = { 1, 2, 3, 4, 5, 6, 7, 8 }, resultList;
    std::forward_list<int> & linkForwardList = myforwardlist;
	// myforwardlist.push_front(8);  need push front elements in cycle like this

	resultList = reverseFrowardList(linkForwardList);

	std::cout << std::endl;
	std::cout << "	reversed forward list is : " << std::endl;
	for (int i : resultList)
	{
		std::cout << i << " ";
	}

    //EXPECT_THAT(resultVector, ::testing::UnorderedElementsAreArray(testVector)); 
    ASSERT_THAT(resultList, ::testing::ElementsAre(8, 7, 6, 5, 4, 3, 2, 1));
}

TEST(ExampleTests,createNumber){ 
   
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

    ASSERT_THAT(valuesList, ::testing::ElementsAre("1", "2", "5", "1", "5", "6", "5", "3", "5", "1", "5"));   //here first number must be 5 fpr pass test]
}

TEST(ExampleTests, Square){
    int x = 5;
    int expectedSquare = x * x;
    EXPECT_EQ(
        expectedSquare,
        Square(x)
    );
}

//---------------------- end usual two tests -----------------
