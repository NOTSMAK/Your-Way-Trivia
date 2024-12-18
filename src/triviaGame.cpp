#include <string>
#include <vector>
#include <iostream>
#include "../header/gameManager.hpp"
#include <fstream>
#include <cctype>

using namespace std;

int main() {
    triviaGame newTriviaGame; //MAIN GAME
    string title;
    string ignoredGetLine;

    cout << "What would you like to call your new quiz? (should not contain spaces):" << endl;
    cin >> title;
    getline(cin, ignoredGetLine);
    newTriviaGame.setTitle(title);

    cout << "How many questions would you like to add?" << endl;
    int qCount;
    while (true) {
        cin >> qCount;
        if (qCount > 0) {
            break;
        } else {
            cout << "Number of questions has to be a positive integer, try again:" << endl;
            cin.clear();
            cin.ignore();
        }
    }
    getline(cin, ignoredGetLine);

    string question;
    int type;
    while(qCount >= 1){

        cout << "What type of question would you like to add? (1 | MCQ (Multiple Choice Question), 2 | OWA (One Word Answer), 3 | TF (True or false)):" << endl;
        while (true) {
            cin >> type;
            if (type == 1 || type == 2 || type == 3) {
                break;
            } else {
                cout << "Not a valid option, try again:" << endl;
                cin.clear();
                cin.ignore();
            }
        }
        getline(cin, ignoredGetLine);

        cout << "Enter question:" << endl;
        getline(cin, question);

        answerOption inputOption;
        if (type == 1) //MCQ
        {
            string choice;
            string stringBool;
            bool isCorrect;

            cout << "Enter answer choice 1:" << endl;
            getline(cin,choice);

            cout << "Will this answer be true or false (1 = true, 0 = false)?" << endl;
            cin >> stringBool;
            getline(cin, ignoredGetLine);
            while (true) {
                if (stringBool == "1") {
                    isCorrect = true;
                    break;
                } else if (stringBool == "0"){
                    isCorrect = false;
                    break;
                } else {
                    cout << "Not a valid input try again:" << endl;
                    cin >> stringBool;
                    getline(cin, ignoredGetLine);
                }
            }
            inputOption.answer = choice;
            inputOption.isCorrect = isCorrect;
            newTriviaGame.addQuestion(type, question, inputOption);

            for (int i = 2; i < 5; i++) {
                answerOption additionalOption;
                cout << "Enter answer choice " << i << ":" << endl;
                getline(cin,choice);

                cout << "Will this answer be true or false (1 = true, 0 = false)?" << endl;
                cin >> stringBool;
                getline(cin, ignoredGetLine);
                while (true) {
                    if (stringBool == "1") {
                        isCorrect = true;
                        break;
                    } else if (stringBool == "0"){
                        isCorrect = false;
                        break;
                    } else {
                        cout << "Not a valid input try again:" << endl;
                        cin >> stringBool;
                        getline(cin, ignoredGetLine);
                    }
                }
                additionalOption.answer = choice;
                additionalOption.isCorrect = isCorrect;
                newTriviaGame.addQuestionOption(additionalOption);
            }
        }
        
        if(type == 2) //OWA
        {
            string answer;

            cout << "Enter one word answer:" << endl;
            cin >> answer;
            getline(cin, ignoredGetLine);

            inputOption.answer = answer;
            inputOption.isCorrect = true;
            newTriviaGame.addQuestion(type, question, inputOption);
        }
        if(type == 3) //TF
        {
            string answer;

            cout << "Enter answer as 1 or 0 (True or False):" << endl;
            getline(cin,answer);

            while (true) {
                if (answer == "1") {
                    inputOption.answer = "true";
                    break;
                } else if (answer == "0"){
                    inputOption.answer = "false";
                    break;
                } else {
                    cout << "Not a valid input try again:" << endl;
                    getline(cin,answer);
                }
            }
            inputOption.isCorrect = true;
            newTriviaGame.addQuestion(type, question, inputOption);
        }

        qCount--;
    }
    
    gameManager gameToSave;
    gameToSave.saveQuiz(newTriviaGame);
}