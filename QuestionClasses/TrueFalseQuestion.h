#ifndef TRUE_FALSE_QUESTION_H
#define TRUE_FALSE_QUESTION_H

#include "Question.h"

class TrueFalseQuestion : public Question {
private:
    bool correctAnswer;

public:
    TrueFalseQuestion(const string& prompt, bool correctAnswer);

    void displayQuestion() const override;

    bool checkAnswer(const string& answer) const override;
};

#endif
