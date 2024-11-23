#include "MultipleChoiceQuestion.h"
#include "TrueFalseQuestion.h"
#include "OneWordResponseQuestion.h"
#include <iostream>
#include <memory>

using namespace std;

int main() {
    // Multiple Choice
    try {
        vector<string> choices = {"Red", "Blue", "Green", "Yellow"};
        MultipleChoiceQuestion mcq("What is the color of the sky?", choices, 2);
        mcq.displayQuestion();
        cout << (mcq.checkAnswer("2") ? "Correct!" : "Incorrect.") << endl;
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }

    // True/False
    TrueFalseQuestion tfq("The Earth is flat.", false);
    tfq.displayQuestion();
    cout << (tfq.checkAnswer("false") ? "Correct!" : "Incorrect.") << endl;

    // One Word Response
    OneWordResponseQuestion owq("What is the capital of France?", "Paris");
    owq.displayQuestion();
    cout << (owq.checkAnswer("paris") ? "Correct!" : "Incorrect.") << endl;

    return 0;
}
