#include <string>
#include <vector>
#include <iostream>
#include "../header/gameManager.hpp"
#include <fstream>
#include <cctype>

using namespace std;

int main() {
    string question;
    string title;
    int type;
    int qCount;

    triviaGame newTriviaGame; //MAIN GAME

    cout << "What would you like to call your quiz?:" << endl;
    getline(cin, title);
    newTriviaGame.setTitle(title);

    cout << "How many questions would you like to add?" << endl;
    cin >> qCount;
    while(qCount >= 1){

        cout << "What type of question would you like to add? (1|MPQ (Multiple Choice Question), 2|OWA (One Word Answer), 3|TF (True or false)):" << endl;
        cin >> type;
        cin.ignore();

        cout << "Enter question:" << endl;;
        getline(cin, question);

        answerOption inputOption;

        if (type == 1) //MPQ
        {
            string choice;
            bool isCorrect;
            

            cout << "Enter answer choice 1:" << endl;
            getline(cin,choice);
            cout << "Will this answer be true or false (1 = true, 0 = false)?" << endl;
            cin >> isCorrect;
            cout << "input option answer" << endl;
            inputOption.answer = choice;
            cout << "input option is correct" << endl;
            inputOption.isCorrect = isCorrect;
            cout << "add question" << endl;
            newTriviaGame.addQuestion(type, question, inputOption);
            cin.ignore();

            for (int i = 2; i < 5; i++) {
                answerOption additionalOption;
                cout << "Enter answer choice " << i << ":" << endl;
                getline(cin,choice);
                cout << "Will this answer be true or false (1 = true, 0 = false)?" << endl;
                cin >> isCorrect;
                cin.ignore();
                additionalOption.answer = choice;
                additionalOption.isCorrect = isCorrect;
                newTriviaGame.addQuestionOption(additionalOption);
            }
        }
        if(type == 2) //OWA
        {
            string answer;
            cout << "Enter one word answer" << endl;
            getline(cin,answer);
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