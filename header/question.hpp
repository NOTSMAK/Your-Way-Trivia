#ifndef question_H
#define question_H

#include <string>
#include <vector>

using namespace std;

struct answerOption {
    std::string answer;
    bool isCorrect;
};

class Question {
    public:

    int type;
    std::string question;
    std::vector<answerOption> options;

    Question(int type, std::string question, answerOption option) : type(type), question(question) {
        options.push_back(option);
    }
    const string& getAnswer(int answerIndex) { options.at(answerIndex).answer; }
    const bool& getAnswerCorrectness(int answerIndex) { options.at(answerIndex).isCorrect; }
};

#endif