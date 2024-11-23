#include <string>
#include <vector>
#include <iostream>
#include "../header/saving.hpp"
#include <fstream>
#include <cctype>

using namespace std;

void savedQuiz::saveQuiz(const string& quizName) {
    ifstream quizInput;
    quizInput.open(quizName + ".txt");
    if (quizInput.is_open()) {
        cout << "Quiz with that name already exists.";
        return;
    }
    quizInput.close();
    ofstream savingQuiz;
    savingQuiz.open(quizName + ".txt");
    for (int i = 0; i < question.size(); i++) {

        if (type == 1) {
            savingQuiz << "MCQ" << endl;
            savingQuiz << question.at(i) << endl;
            for (int j = 0; j < options.at(j).size(); j++) {
                savingQuiz << options.at(i).at(j);
            }
        }
        else if (type == 2) {
            savingQuiz << "OWA" << endl;
        }
        else if (type == 3) {
            savingQuiz << "TOF" << endl;
        }
    }
    savingQuiz.close();
}
