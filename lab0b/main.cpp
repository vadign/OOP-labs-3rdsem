#include <iostream>


#include "taskDoned.h"

int main(const int argc, char **argv) {

    if (argc != 3){
        throw logic_error("Not enough arguments");
    }

    taskDoned task;
    const string &input = argv[1];
    const string &output = argv[2];

    task.readFile(input);
    task.sortingAndWriting(output);

    return 0;
}