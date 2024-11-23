#ifndef QUESTION_H
#define QUESTION_H

#include <string>
using namespace std;

class Question {
protected:
    string prompt;

public:
    Question(const string& prompt) : prompt(prompt) {}

    virtual ~Question() {}

    virtual void displayQuestion() const = 0;

    virtual bool checkAnswer(const string& answer) const = 0;
};

#endif
