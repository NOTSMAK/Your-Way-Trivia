#include "OneWordResponseQuestion.h"
#include <iostream>
#include <algorithm>

OneWordResponseQuestion::OneWordResponseQuestion(const string& prompt, const string& correctAnswer)
    : Question(prompt), correctAnswer(correctAnswer) {}

void OneWordResponseQuestion::displayQuestion() const {
    cout << prompt << " (Answer in one word)" << endl;
}

bool OneWordResponseQuestion::checkAnswer(const string& answer) const {
    string lowerAnswer = answer;
    string lowerCorrectAnswer = correctAnswer;

    // Convert both to lowercase
    for (auto& ch : lowerAnswer) ch = tolower(ch);
    for (auto& ch : lowerCorrectAnswer) ch = tolower(ch);

    return lowerAnswer == lowerCorrectAnswer;
}
