#include <string>
#include <vector>
#include <iostream>
#include "../header/triviaGame.hpp"
#include <fstream>
#include <cctype>

using namespace std;

int main() {

    string question;
    string title;
    int type;
    int qCount

    triviaGame newTriviaGame; //MAIN GAME

    cout << "What would you like to call your quiz?:" << endl;
    getline(cin, title);
    newTriviaGame.setTitle(title);

    cout << "How many questions would you like to add?" << endl;
    getline(cin, qCount);
    while(qCount >= 1){

    vector<string> answerChoices;

    cout << "What type of question would you like to add? (1|MPQ (Multiple Choice Question), 2|OWA (One Word Answer), 3|TF (True or false)):" << endl;
    getline(cin, type);
    newTriviaGame.addType(type);

    cout << "Enter question:" << endl;;
    getline(cin, question);
    newTriviaGame.addQuestion(question);

    if (type == 1) //MPQ
    {
        string choice;

        cout << "Enter first answer choice:" << endl;
        getline(cin,choice);
        answerChoices.push_back(choice);
        
        cout << "Enter second answer choice:" << endl;
        getline(cin,choice);
        answerChoices.push_back(choice);

        cout << "Enter third answer choice:" << endl;
        getline(cin,choice);
        answerChoices.push_back(choice);

        cout << "Enter fourth answer choice:" << endl;
        getline(cin,choice);
        answerChoices.push_back(choice);

        newTriviaGame.addOptions(answerChoices);
    }
    if(type == 2) //OWA
    {
        string answer;
        vector<string> OWA;
        cout << "Enter one word answer" << endl;
        getline(cin,answer);
        newTriviaGame.addAnswer(answerChoices);

        

    }
    if(type == 3) //TF
    {
        int answerT;
        vector<string> OWA;
        cout << "Enter 1 or 0 (True or False):" << endl;
        getline(cin,answerT);
        newTriviaGame.addAnswer(answerChoices);

    }

    qCount--;
    }

}