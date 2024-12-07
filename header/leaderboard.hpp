#ifndef LEADERBOARD_H
#define LEADERBOARD_H
#include <string>
#include <vector>
#include "user.hpp"

using namespace std;

class Leaderboard {
    private:
        string leaderboardFileName; //file name to store log data

        //helper functions
        vector<User> fetchLeaderboard(const string&); //stores log data for a given quizName into a sorted vector
        void sortRankingByScore(vector<User>&);
    public:
        Leaderboard(const string& file) : leaderboardFileName(file) {} 

        void logPlay(const User&, const string&); //call after each game played to record it
        void displayLeaderboard(const string&) const; //calls fetchLeaderboard and print returned vector
};

#endif