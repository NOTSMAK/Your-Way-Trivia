#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cctype>
#include <limits>
#include <stdexcept>
#include "../header/gameManager.hpp"

using namespace std;
void gameManager::displayOptions() {
    int userInput;
    do {
        cout << "Welcome to Trivia Games!!" << endl;
        cout << "1. Start Trivia" << endl;
        cout << "2. Create New Trivia" << endl;
        cout << "3. View Leaderboard" << endl;
        cout << "4. Read Existing Trivia" << endl;
        cout << "5. Exit" << endl;

        while (!(cin >> userInput) || userInput < 1 || userInput > 5) {
            cout << "Invalid Input. Choose 1 of the 5 options! " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }

        switch (userInput) {
            case 1:
                playGame();
                break;
            case 2:
                createGame();
                break;
            case 3:
                cout << "Viewing Leaderboard..." << endl;
                break;
            case 4:
                readGameFiles();
                break;
            case 5:
                cout << "Exiting GAME..." << endl;
                break;
        }
    } while (userInput != 5);
}

triviaGame gameManager::loadQuiz(const string& quizName) {
    ifstream quizInput;
    quizInput.open(quizName + ".txt");
    triviaGame newGame;
    if (quizInput.fail()) {
        cout << "Quiz with that name does not exist.";
        return newGame;
    }
    newGame.setTitle(quizName);
    while (!quizInput.eof()) {
        int type = 0;
        string inputType;
        string inputQuestion;
        answerOption inputOption;
        string answer;
        getline(quizInput, inputType);
        if (inputType == "MCQ") {
            type = 1;
        }
        if (inputType == "OWA") {
            type = 2;
        }
        if (inputType == "TOF") {
            type = 3;
        }
        if (type == 1) {
            bool answerCorrectness;
            getline(quizInput, inputQuestion);
            getline(quizInput, answer);
            quizInput >> answerCorrectness;
            quizInput.ignore();
            inputOption.answer = answer;
            inputOption.isCorrect = answerCorrectness;
            newGame.addQuestion(type, inputQuestion, inputOption);
            for (int i = 0; i < 3; i++) {
                getline(quizInput, answer);
                quizInput >> answerCorrectness;
                quizInput.ignore();
                answerOption additionalOption;
                additionalOption.answer = answer;
                additionalOption.isCorrect = answerCorrectness;
                newGame.addQuestionOption(additionalOption);
            }
        }
        else if (type == 2 || type == 3) {
            getline(quizInput, inputQuestion);
            getline(quizInput, answer);
            inputOption.answer = answer;
            inputOption.isCorrect = true;
            newGame.addQuestion(type, inputQuestion, inputOption);
        }
    }
    quizInput.close();
    return newGame;
}

void gameManager::saveQuiz(triviaGame quizToSave) {
    ifstream quizInput;
    quizInput.open(quizToSave.getTitle() + ".txt");
    if (quizInput.is_open()) {
        cout << "Quiz with that name already exists.";
        quizInput.close();
        return;
    }
    quizInput.close(); 
    ofstream savingQuiz;
    savingQuiz.open(quizToSave.getTitle() + ".txt");
    for (int i = 0; i < quizToSave.numQuestions(); i++) {
        if (quizToSave.getType(i) == 1) {
            savingQuiz << "MCQ" << endl;
            savingQuiz << quizToSave.getQuestion(i) << endl;
            for (int j = 0; j < 4; j++) {
                savingQuiz << quizToSave.getAnswer(i, j) << endl;
                savingQuiz << quizToSave.getAnswerCorrectness(i, j) << endl;
            }
        }
        else if (quizToSave.getType(i) == 2) {
            savingQuiz << "OWA" << endl;
            savingQuiz << quizToSave.getQuestion(i) << endl;
            savingQuiz << quizToSave.getAnswer(i, 0) << endl;
        }
        else if (quizToSave.getType(i) == 3) {
            savingQuiz << "TOF" << endl;
            savingQuiz << quizToSave.getQuestion(i) << endl;
            savingQuiz << quizToSave.getAnswer(i, 0) << endl;
        }
    }
    savingQuiz.close();

}
void gameManager::createGame() {
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
    gameToSave.addToGameFiles(newTriviaGame.getTitle());
    
}

void gameManager::playGame() {
    string userName;
    string quizName;
    string ignoredGetLine;
    cout << "Enter Username: " ;
    cin >> userName;
    getline(cin, ignoredGetLine);
    cout << "Enter Quiz Name (no spaces): " ;
    cin >> quizName;
    getline(cin, ignoredGetLine);
    cout << "STARTING GAME...." << endl << endl << endl;
    triviaGame newGame;
    newGame = loadQuiz(quizName);
    if(newGame.getTitle() == "") {
        cout << "Game does not exist." << endl;
        return;
    }
 int score = 0;

 string userAnswer;
 int i;
for (i = 0; i < newGame.numQuestions(); i++) {
    cout << newGame.getQuestion(i) << endl;
    if (newGame.getType(i) == 1) {
        for (int j = 0; j < 4; j++) {
            cout << j + 1 << ". " << newGame.getAnswer(i, j) << endl;
        }
        getline(cin, userAnswer);
        while (true) {
            if (userAnswer == "1") {
                userAnswer = newGame.getAnswer(i, 0);
                break;
            } else if (userAnswer == "2") {
                userAnswer = newGame.getAnswer(i, 1);
                break;
            } else if (userAnswer == "3") {
                userAnswer = newGame.getAnswer(i, 2);
                break;
            } else if (userAnswer == "4") {
                userAnswer = newGame.getAnswer(i, 3);
                break;
            } else {
                cout << "Please input a number 1-4 corresponding to your answer:" << endl;
                getline(cin, userAnswer);
            }
        }
        bool isCorrect = false;
        for(int k = 0; k < 4; k++){ 
            if(userAnswer == newGame.getAnswer(i, k) && newGame.getAnswerCorrectness(i, k) == true) {
                score++;
                isCorrect = true;
            }
        }
        if(isCorrect) {
            cout << "Correct Answer! - Current score: " << score << endl;
        } else {
            cout << "Wrong Answer! - Current score: " << score << endl;
        }          
    }
    else if (newGame.getType(i) == 2) {
        cout << "Enter your answer: " << endl;
        cin >> userAnswer;
        getline(cin, ignoredGetLine);
        if (userAnswer == newGame.getAnswer(i, 0)) {
            score++;
            cout << "Correct Answer! - Current score: " << score << endl;
        }
        else{
            cout << "Wrong Answer! - Current score: " << score << endl;
        }
    }
    else if (newGame.getType(i) == 3) {
        cout << "Enter your answer (1 = true, 0 = false): ";
        cin >> userAnswer;
        getline(cin, ignoredGetLine);
        while (true) {
            if (userAnswer == "1" && newGame.getAnswer(i, 0) == "true") {
                score++;
                cout << "Correct Answer! - Current score: " << score << endl;
                break;
            }
            else if (userAnswer == "0" && newGame.getAnswer(i, 0) == "false") {
                score++;
                cout << "Correct Answer! - Current score: " << score << endl;            
                break;
            }
            else if (userAnswer != "1" && userAnswer != "0") {
                cout << "Please answer with 1 or 0. Try again:" << endl;
                cin >> userAnswer;
                getline(cin, ignoredGetLine);
            }
            else{
                cout << "Wrong Answer! - Current score:  " << score << endl;
                break;
            }
        }
    }
}
cout << "Game Over!" << endl;
    cout << "Game name: " << quizName << endl;
    cout << "Name: " << userName << endl;
    cout << "Final Score: " << score << " / " << newGame.numQuestions()<< endl << endl << endl;
}


void gameManager::readGameFiles(){
    fstream gameFile;
       string gameFileName = "savedGameNames.txt";
    gameFile.open(gameFileName);
    if (!gameFile) {
        cout << "Unable to open file." << endl;
        return;
    }

    string line;
    while (getline(gameFile, line)) {
        cout << "Game Name: " << line << endl;
    }
    cout << endl << endl << endl;
    gameFile.close();
}

void gameManager::addToGameFiles (string gameName){
    fstream gameFile;
    string gameFileName = "savedGameNames.txt";
    gameFile.open(gameFileName, fstream::app);
    if (!gameFile) {
        cout << "Unable to open file." << endl;
        return;
    }

    gameFile << gameName << endl;

    gameFile.close();
    
}
