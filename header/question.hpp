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
    Question() : type(0), question("") {}
    Question(int qType, std::string newQuestion, answerOption option) : type(qType), question(newQuestion) {
        options.push_back(option);
    }
    const string& getAnswer(int answerIndex) { return options.at(answerIndex).answer; }
    const bool& getAnswerCorrectness(int answerIndex) { return options.at(answerIndex).isCorrect; }
};

#endif