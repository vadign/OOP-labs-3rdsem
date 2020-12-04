#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file

#include "catch2.hpp"
#include <iostream>
#include "LinkedList.h"

TEST_CASE("Create List, push&pop") {
    LinkedList testList = LinkedList();

    testList.push_back(5);
    testList.push_back(6);
    testList.pop_back();
    testList.pop_front();

    REQUIRE(testList.empty() == 1);

    testList.push_back(2);
    testList.push_back(3);
    testList.push_front(1);

    char rightList[3] = {1, 2, 3};
    char pos = 0;


    for (LinkedList::iterator i = testList.begin(); i != testList.end(); i++){
        REQUIRE((*i) == rightList[pos]);
        pos++;
    }
}

TEST_CASE("Clean up") {

    LinkedList testList = LinkedList();

    testList.push_front(5);
    testList.push_front(6);
    testList.push_front(6);
    testList.push_front(7);
    testList.push_front(8);

    testList.remove(6);

    REQUIRE(testList.size() == 3); // {8 7 5}

    LinkedList::iterator testIterator = testList.begin();
    testIterator++;
    testIterator = testList.erase(testIterator);

    char rightList[2] = {8, 5};
    char pos = 0;
    for (LinkedList::iterator i = testList.begin(); i != testList.end(); i++){
        REQUIRE((*i) == rightList[pos]);
        pos++;
    }

    testList.clear();
    REQUIRE(testList.empty());
}

TEST_CASE("Insert"){
    LinkedList testList = LinkedList();

    testList.push_front(1);
    testList.push_back(2);

    LinkedList::iterator i = testList.begin();

    testList.insert(i,0);

    char rightList[3] = {0, 1, 2};
    char pos = 0;
    for (LinkedList::iterator i = testList.begin(); i != testList.end(); i++){
        REQUIRE((*i) == rightList[pos]);
        pos++;
    }

}

TEST_CASE (" = & == "){
    LinkedList firstList = LinkedList();
    LinkedList secondList = LinkedList();

    firstList.push_front(1);
    firstList.push_back(2);
    firstList.push_back(3);

    secondList.push_front(1);
    secondList.push_back(2);
    secondList.push_back(3);

    REQUIRE(firstList == secondList);

    firstList.push_front(0);
    REQUIRE(firstList != secondList);

    secondList = firstList;
    REQUIRE(firstList == secondList);
}