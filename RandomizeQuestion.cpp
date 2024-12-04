#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

void randomizeQuestions(vector<string>& questions) {
    // Seed the random number generator
    srand(time(nullptr));
    
    // Shuffle the questions
    random_shuffle(questions.begin(), questions.end());
}

int main() {
    // Example set of questions
    vector<string> quizQuestions = {
        "What is the capital of France?",
        "Who wrote 'To Kill a Mockingbird'?",
        "What is 2 + 2?",
        "Name the largest planet in our solar system.",
        "What is the boiling point of water?"
    };

    // Randomize the questions
    randomizeQuestions(quizQuestions);

    // Display the randomized questions
    cout << "Randomized Quiz Questions:\n";
    for (const auto& question : quizQuestions) {
        cout << question << "\n";
    }

    return 0;
}