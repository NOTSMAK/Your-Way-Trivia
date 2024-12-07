#ifndef game_manager_H
#define game_manager_H

#include <string>
#include <vector>
#include "./triviaGame.hpp"

class gameManager : triviaGame {

    public:
    void playGame();
    void createGame();
    void saveQuiz (triviaGame quizToSave);
    triviaGame loadQuiz (const std::string& quizName);
    void displayOptions();
    void readGameFiles();
    void addToGameFiles(string gameName);
};

#endif