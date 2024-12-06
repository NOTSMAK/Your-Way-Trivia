#ifndef LEADERBOARD_H
#define LEADERBOARD_H
#include <string>
#include <vector>
#include <iostream>
#include "../header/gameManager.hpp"
#include <fstream>
#include <cctype>

using namespace std;

class Leaderboard {
    private:
        string leaderboardFileName; //file name to store log data

        //helper functions
        vector<User> fetchLeaderboard(const string& quizName) const; //stores log data for a given quizName into a sorted vector
    public:
        Leaderboard(const string& file) : leaderboardFile(file) {} 

        void logPlay(const User& player); //call after each game played to record it
        void displayLeaderboard(const string& quizName) const; //calls fetchLeaderboard and print returned vector
};

#endif