#include "Menu.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include <stdexcept>
using namespace std;
void GameManager::displayOptions() {
    cout << "Welcome to ...." << endl;
    cout << "1. Start Trivia" << endl;
    cout << "2. Create New Trivia" << endl;
    cout << "3. load Trivia" << endl;
    cout << "4. View Leaderboard" << endl;
    cout << "5. Exit" << endl;
    int userInput;
    cin >> userInput;
    while(!(cin >> userInput) || userInput < 1 || userInput > 5){
        cout << "Invalid Input. Choose 1 of the 5 options! " << endl;
         cin.clear(); // Clear the error flag 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
    }
    if(userInput  == 1 ){
        int chooseTrivia;
         cout << "1. Create New Trivia" << endl;
         cout << "2. load Trivia" << endl;
         cin >> chooseTrivia;
        if(chooseTrivia == 1){
            StartGame(createGame());
         }
        if(chooseTrivia == 2 ){
            cout << "Saved Gamefile Name: ";
            string savedFile;
            cin >> savedFile;
            StartGame(savedFile);
         }
    }
    else if(userInput == 2){
        createGame();
    }
    else if(userInput == 3){
        cout << "Saved Gamefile Name: ";
        string savedFile;
        cin >> savedFile;
        loadGame(savedFile);

    }
    else if(userInput == 4){
        viewLeaderboad();
    }
    else if(userInput == 5){
        return;
    }

}

void GameManager::StartGame(string savedFile) const {
    string name;
    cout << "UserName: " << endl;
    cin >> name;
    User newUser;
    newUser.setName(name);
    int checker = 0;
    TriviaGame* currGame;
    for(int i = 0; i< games.size()-1; i++){
        if(savedFile == games.at(i)->getTitle()){
            currGame = games.at(i);
            checker++;
            break;
        }
    }
     if (currGame == nullptr) {
        cout << "Error: No game found with the title " << savedFile << endl;
        return;
    }
    if(checker >= 1) {
      QuestionPool* newPool = currGame->getPool();
      for ( auto&  question : newPool->pool) {
       question->display();
//NOT DONE

      }

    }

    
    

}
