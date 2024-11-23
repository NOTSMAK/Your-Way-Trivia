#include "TrueFalseQuestion.h"
#include <iostream>

TrueFalseQuestion::TrueFalseQuestion(const string& prompt, bool correctAnswer)
    : Question(prompt), correctAnswer(correctAnswer) {}

void TrueFalseQuestion::displayQuestion() const {
    cout << prompt << " (True/False)" << endl;
}

bool TrueFalseQuestion::checkAnswer(const string& answer) const {
    string lowerAnswer = answer;
    for (auto& ch : lowerAnswer) ch = tolower(ch);

    if (lowerAnswer == "true" || lowerAnswer == "t") {
        return correctAnswer;
    } else if (lowerAnswer == "false" || lowerAnswer == "f") {
        return !correctAnswer;
    }
    return false;
}
