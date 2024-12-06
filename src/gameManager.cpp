#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cctype>
#include "../header/gameManager.hpp"

using namespace std;

void gameManager::loadQuiz(const string& quizName) {
    ifstream quizInput;
    quizInput.open(quizName + ".txt");
    triviaGame newGame;
    if (quizInput.fail()) {
        cout << "Quiz with that name does not exist.";
        return;
    }
    newGame.setTitle(quizName);
    while (!quizInput.eof()) {
        int type = 0;
        string inputType;
        string inputQuestion;
        answerOption inputOption;
        string answer;
        getline(quizInput, inputType);
        if (inputType == "MCQ") {
            type = 1;
        }
        if (inputType == "OWA") {
            type = 2;
        }
        if (inputType == "TOF") {
            type = 3;
        }
        if (type == 1) {
            bool answerCorrectness;
            getline(quizInput, inputQuestion);
            getline(quizInput, answer);
            quizInput >> answerCorrectness;
            quizInput.ignore();
            inputOption.answer = answer;
            inputOption.isCorrect = answerCorrectness;
            newGame.addQuestion(type, inputQuestion, inputOption);
            for (int i = 0; i < 3; i++) {
                getline(quizInput, answer);
                quizInput >> answerCorrectness;
                quizInput.ignore();
                answerOption additionalOption;
                additionalOption.answer = answer;
                additionalOption.isCorrect = answerCorrectness;
                newGame.addQuestionOption(additionalOption);
            }
        }
        else if (type == 2 || type == 3) {
            getline(quizInput, inputQuestion);
            getline(quizInput, answer);
            inputOption.answer = answer;
            inputOption.isCorrect = true;
            newGame.addQuestion(type, inputQuestion, inputOption);
        }
    }
    quizInput.close();
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
    for (int i = 0; i < numQuestions(); i++) {
        if (quizToSave.getType(i) == 1) {
            savingQuiz << "MCQ" << endl;
            savingQuiz << quizToSave.getQuestion(i) << endl;
            for (int j = 0; j < 4; j++) {
                savingQuiz << quizToSave.getAnswer(i, j) << endl;
                savingQuiz << quizToSave.getAnswerCorrectness(i, j) << endl;
            }
        }
        else if (quizToSave.getType(i) == 2) {
            savingQuiz << "OWA" << endl;
            savingQuiz << quizToSave.getQuestion(i) << endl;
            savingQuiz << quizToSave.getAnswer(i, 0) << endl;
        }
        else if (quizToSave.getType(i) == 3) {
            savingQuiz << "TOF" << endl;
            savingQuiz << quizToSave.getQuestion(i) << endl;
            savingQuiz << quizToSave.getAnswer(i, 0) << endl;
        }
    }
    savingQuiz.close();
}
