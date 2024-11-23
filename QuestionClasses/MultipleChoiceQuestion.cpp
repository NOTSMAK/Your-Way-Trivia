#include "MultipleChoiceQuestion.h"
#include <iostream>

MultipleChoiceQuestion::MultipleChoiceQuestion(const string& prompt, const vector<string>& choices, int correctChoice)
    : Question(prompt), correctChoice(correctChoice) {
    if (choices.size() > 4 || choices.size() < 2) {
        throw invalid_argument("MultipleChoiceQuestion must have between 2 and 4 choices.");
    }
    this->choices = choices;
    if (correctChoice < 1 || correctChoice > choices.size()) {
        throw out_of_range("Correct choice must be a valid option index (1-based).");
    }
}

void MultipleChoiceQuestion::displayQuestion() const {
    cout << prompt << endl;
    for (size_t i = 0; i < choices.size(); ++i) {
        cout << i + 1 << ". " << choices[i] << endl;
    }
}

bool MultipleChoiceQuestion::checkAnswer(const string& answer) const {
    try {
        int choice = stoi(answer);
        return choice == correctChoice;
    } catch (...) {
        return false;
    }
}
