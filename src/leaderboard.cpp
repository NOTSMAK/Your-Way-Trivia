#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <cctype>
#include "../header/leaderboard.hpp"

using namespace std;

void logPlay(const User& player, const string& quizName) {
    ofstream file(leaderboardFileName, ios::app); //append mode
    if (!file.is_open()) throw runtime_error("Error: Could not open file.");

    //write each detail on a new line
    file << quizName << endl;
    file << player.getName() << endl;
    file << player.getScore() << endl;

    file.close();
}
void displayLeaderboard(const string& quizName){
    vector<User> ranking = fetchLeaderboard(quizName); //get sorted vector

    cout << "Ranking for " << quizName << ":\n";
    int rank = 1;
    
    //print loop
    for(const User& user : ranking){
        cout << rank << ". " << user.getUsername() << ": " << user.getScore() << endl;
        rank++;
    }
}

//HELPERS

vector<User> fetchLeaderboard(const string& quizName){
    ifstream inputFile(leaderboardFileName + ".txt");  //open file
    if(!inputFile.is_open()) throw runtime_error("Error opening file.");
    
    vector<User> ranking;
    string logQuizName, logName;
    int logScore;
    //reading loop
    while(getline(inputFile, logQuizName)){
        getline(inputFile, logName);

        inputFile >> logScore;
        inputFile.ignore();

        if(logQuizName == quizName){
            ranking.push_back(User(logName, logScore));
        }
    }
    inputFile.close();

    return sortRankingByScore(ranking);
}

void sortRankingByScore(vector<User>& playerList){
    sort(playerList.begin(), playerList.end(), [](const User& a, const User& b){
        return a.getScore() > b.getScore();  
    });
}
    

