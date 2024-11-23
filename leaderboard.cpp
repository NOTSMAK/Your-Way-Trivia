#include "Menu.h"
#include <iostream>
#include <fstream>



void Leaderboard::addUserToLeaderBoard(const string& filePath, const string& userName, int initialScore) {
    ifstream inputFile(filePath);

    if (!inputFile.is_open()) {
        cout << "Error: Could not open " << filePath << endl;
        return;
    }

    string line;
    bool userExists = false;
    
    while (getline(inputFile, line)) {
        unsigned spacePos = line.find(' ');
        if (spacePos != string::npos) {
            string name = line.substr(0, spacePos); 
            if (name == userName) {
                cout << "User " << userName << " already exists!" << endl;
                userExists = true;
                break;
            }
        }
    }
    inputFile.close();

    if(!userExists) {
        ofstream outputFile(filePath);
        if (!outputFile.is_open()) {
            cerr << "Error: Could not open " << filePath << endl;
            return;
        }
        outputFile << userName << " " << initialScore << endl;
        outputFile.close();
    }
}
//Need update
 void Leaderboard::updateScore(const string& userName, int newScore) {
        for (auto& user : users) {
            if (user.getName() == userName) {
                user.updateScore(newScore);
                return;
            }
        }
        cout << "User " << userName << " does not exist!" << endl;
    }

 void displayLeaderboard(const string& fileName) {
        ifstream file(fileName);
        if (!file.is_open()) {
            cout << "Error: Could not open file " << fileName << endl;
            return;
        }

        cout << "Leaderboard:" << endl;
        string name;
        int score;

        while (file >> name >> score) { 
            cout << "Name: " << name << " Score: " << score << endl;
        }

        file.close(); 
    }