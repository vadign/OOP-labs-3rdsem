#include <iostream>
#include "checks.h"

#include "NIP.h"

int main(const int argc, char **argv) {

    taskDoned task;
    string input = argv[1];
    string output = argv[2];

    task.readFile(input);
    task.sortingAndWriting(output);

    return 0;
}