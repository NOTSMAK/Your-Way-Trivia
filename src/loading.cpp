#include <string>
#include <vector>
#include <iostream>
#include "../header/loading.hpp"
#include <fstream>
#include <cctype>

using namespace std;

void savedQuiz::loadQuiz(const string& quizName) {
    title = quizName;
    ifstream quizInput;
    quizInput.open(quizName + ".txt");
    if (quizInput.fail()) {
        cout << "Quiz does not exist.";
        return;
    }
    string fileOutString = "";
    type = 0;
    while (!quizInput.eof()) {
        getline(quizInput, fileOutString);
        if (fileOutString == "MCQ") {
            type = 1;
        }
        if (fileOutString == "OWA") {
            type = 2;
        }
        if (fileOutString == "TOF") {
            type = 3;
        }
        if (type == 1) {
            getline(quizInput, fileOutString);
            question.push_back(fileOutString);
            vector<string> possibleOptions;
            for (int i = 0; i < 4; i++) {
                getline(quizInput, fileOutString);
                possibleOptions.push_back(fileOutString);
            }
            options.push_back(possibleOptions);
            getline(quizInput, fileOutString);
            answer.push_back(fileOutString);
        }
        else if (type == 2 || type == 3) {
            getline(quizInput, fileOutString);
            question.push_back(fileOutString);
            getline(quizInput, fileOutString);
            answer.push_back(fileOutString);
        }
    }
    quizInput.close();
}
