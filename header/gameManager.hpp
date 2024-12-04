#include <string>
#include <vector>
#include "../header/triviaGame.hpp"

class gameManager : triviaGame {
    public:
    
    void saveQuiz (triviaGame quizToSave);
    triviaGame loadQuiz (const std::string& quizName);
};