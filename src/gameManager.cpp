#include <string>
#include <vector>
#include <iostream>
#include "../header/gameManager.hpp"
#include <fstream>
#include <cctype>

using namespace std;

triviaGame gameManager::loadQuiz(const string& quizName) {
    ifstream quizInput;
    quizInput.open(quizName + ".txt");
    if (quizInput.fail()) {
        cout << "Quiz does not exist.";
        return;
    }
    triviaGame newGame;
    newGame.setTitle(quizName);
    string fileOutString = "";
    int type = 0;
    while (!quizInput.eof()) {
        getline(quizInput, fileOutString);
        if (fileOutString == "MCQ") {
            newGame.addType(1);
            type = 1;
        }
        if (fileOutString == "OWA") {
            newGame.addType(2);
            type = 2;
        }
        if (fileOutString == "TOF") {
            newGame.addType(3);
            type = 3;
        }
        if (type == 1) {
            getline(quizInput, fileOutString);
            newGame.addQuestion(fileOutString);
            vector<string> possibleOptions;
            for (int i = 0; i < 4; i++) {
                getline(quizInput, fileOutString);
                possibleOptions.push_back(fileOutString);
            }
            newGame.addOptions(possibleOptions);
            getline(quizInput, fileOutString);
            newGame.addAnswer(fileOutString);
        }
        else if (type == 2 || type == 3) {
            getline(quizInput, fileOutString);
            newGame.addQuestion(fileOutString);
            getline(quizInput, fileOutString);
            vector<string> emptyVector;
            emptyVector.push_back("");
            newGame.addOptions( emptyVector );
            getline(quizInput, fileOutString);
            newGame.addAnswer(fileOutString);
        }
    }
    quizInput.close();

    return newGame;
}

void gameManager::saveQuiz(triviaGame quizToSave) {
    ifstream quizInput;
    quizInput.open(quizToSave.getTitle() + ".txt");
    if (quizInput.is_open()) {
        cout << "Quiz with that name already exists.";
        return;
    }
    quizInput.close();
    ofstream savingQuiz;
    savingQuiz.open(quizToSave.getTitle() + ".txt");
    for (int i = 0; i < numberOfQuestions(); i++) {
        if (quizToSave.getType(i) == 1) {
            savingQuiz << "MCQ" << endl;
            savingQuiz << quizToSave.getQuestion(i) << endl;
            for (int j = 0; j < 4; j++) {
                savingQuiz << quizToSave.getOptions(i).at(j) << endl;
            }
            savingQuiz << quizToSave.getAnswer(i) << endl;
        }
        else if (quizToSave.getType(i) == 2) {
            savingQuiz << "OWA" << endl;
            savingQuiz << quizToSave.getQuestion(i) << endl;
            savingQuiz << "none";
            savingQuiz << quizToSave.getAnswer(i) << endl;
        }
        else if (quizToSave.getType(i) == 3) {
            savingQuiz << "TOF" << endl;
            savingQuiz << quizToSave.getQuestion(i) << endl;
            savingQuiz << "none" << endl;
            savingQuiz << quizToSave.getAnswer(i) << endl;
        }
    }
    savingQuiz.close();
}
