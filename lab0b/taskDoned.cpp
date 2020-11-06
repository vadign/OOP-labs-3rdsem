#include "taskDoned.h"
#include "checks.h"
#include <fstream>
#include <list>
#include <map>

using namespace std;

bool compareFrequency(pair<string, int> &word1, pair<string, int> &word2) {

    return word1.second > word2.second;

}

taskDoned::taskDoned() {
    countOfWords = 0;
}

void taskDoned::readFile(string input) {

    ifstream fin;
    fin.open(input, fstream::in);
    if(!fin) {
        throw logic_error("Unable to open input file.");
    }

    string buffer;
    string currentWord;

    bool lastWordIsEnded = true;

    while ((getline(fin, buffer))) {   // != 0

        for (int i = 0; i < buffer.size(); i++) {  //Sizeof() doesn't return the size of the container

            if ((checks::isLetter(buffer[i])) || (checks::isNumber(buffer[i]))) {
                currentWord += buffer[i];

                if (lastWordIsEnded) {
                    countOfWords++;
                    lastWordIsEnded = false;
                }


            } else if (!lastWordIsEnded) {
                words[currentWord]++;
                currentWord = "";
                lastWordIsEnded = true;
            }
        }
    }

    fin.close();

}

void taskDoned::sortingAndWriting(string output) {
    map<string, int>::iterator i;
    pair<string, int> pairToWrite;
    list<pair<string, int>> listOfWords;

    for (i = words.begin(); i != words.end(); i++) {
        pairToWrite.first = i->first;
        pairToWrite.second = i->second;
        listOfWords.push_back(pairToWrite);
    }
    listOfWords.sort(compareFrequency);


    ofstream fout;
    fout.open(output, fstream::out);
    if(!fout) {
        throw std::logic_error("Unable to open output file.");
    }

    list<pair<string, int>>::iterator iq;

    for (iq = listOfWords.begin(); iq != listOfWords.end(); iq++) {
        int freqInPercents = (iq->second / countOfWords) * 100;

        fout << iq->first << "," << iq->second << "," << freqInPercents << endl;
    }

    fout.close();
}


