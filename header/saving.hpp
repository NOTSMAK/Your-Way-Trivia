#include <string>
#include <vector>

struct savedQuiz {
    std::string title;
    int type;
    std::vector<std::string> question;
    std::vector<std::vector<std::string>> options;  
    std::vector<std::string> answer;
    void saveQuiz(const std::string& quizName);
};