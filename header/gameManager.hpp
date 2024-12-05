#ifndef game_manager_H
#define game_manager_H

#include <string>
#include <vector>
#include "./triviaGame.hpp"

class gameManager : triviaGame {
    public:
    
    void saveQuiz (triviaGame quizToSave);
    void loadQuiz (const std::string& quizName);
};

#endif