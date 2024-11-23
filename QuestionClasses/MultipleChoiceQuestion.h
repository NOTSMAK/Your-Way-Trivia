#ifndef MULTIPLE_CHOICE_QUESTION_H
#define MULTIPLE_CHOICE_QUESTION_H

#include "Question.h"
#include <vector>
#include <stdexcept>

class MultipleChoiceQuestion : public Question {
private:
    vector<string> choices;
    int correctChoice;

public:
    MultipleChoiceQuestion(const string& prompt, const vector<string>& choices, int correctChoice);

    void displayQuestion() const override;

    bool checkAnswer(const string& answer) const override;
};

#endif
