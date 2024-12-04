#include <string>
#include <vector>
#include <iostream>
#include "../header/triviaGame.hpp"
#include <fstream>
#include <cctype>

using namespace std;

int main() {
    triviaGame newTriviaGame;
    newTriviaGame.setTitle("Water");
    newTriviaGame.addType(1);
    cout << "Enter question:";
    string question;
    getline(cin, question);
    newTriviaGame.addQuestion(question);
}