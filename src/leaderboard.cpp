#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "../header/leaderboard.hpp"
#include <fstream>
#include <cctype>

using namespace std;

void logPlay(const User& player, const string& quizName) {
    ofstream file(leaderboardFileName, ios::app); //append mode
    if (!file.is_open()) throw runtime_error("Error: Could not open file " + leaderboardFile);

    //write each detail on a new line
    file << player.getQuizName() << endl;
    file << player.getName() << endl;
    file << player.getScore() << endl;

    file.close();
}
void displayLeaderboard(const User& quizName){
    vector<User> ranking = fetchLeaderboard(quizName); //get sorted vector

    cout << "Ranking for " << quizName << ":\n";
    int rank = 1;
    
    //print loop
    for(const User& user : leaderboard){
        cout << rank << ". " << user.getUsername() << ": " << user.getScore() << endl;
        rank++;
    }
}

//HELPERS

vector<User> fetchLeaderboard(const string& quizName) const{
    ifstream inputFile(leaderboardFileName + ".txt");  //open file
    if(!inputFile.is_open()) throw runtime_error("Error opening file." << endl);
    
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
    sort(ranking.begin(), ranking.end(), [](const User& a, const User& b)){
        return a.getScore() > b.getScore();  
    };
}
    

