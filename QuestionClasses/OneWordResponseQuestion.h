#ifndef ONE_WORD_RESPONSE_QUESTION_H
#define ONE_WORD_RESPONSE_QUESTION_H

#include "Question.h"

class OneWordResponseQuestion : public Question {
private:
    string correctAnswer;

public:
    OneWordResponseQuestion(const string& prompt, const string& correctAnswer);

    void displayQuestion() const override;

    bool checkAnswer(const string& answer) const override;
};

#endif
