#ifndef LAB0B_TASKDONED_H
#define LAB0B_TASKDONED_H

#include <map>

using namespace std;

class taskDoned {

    int countOfWords;
    map<string, int> words;

public:

    taskDoned();

    void readFile (string input);

    void sortingAndWriting (string output);

private:

};


#endif //LAB0B_TASKDONED_H
