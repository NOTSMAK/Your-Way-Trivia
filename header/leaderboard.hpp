

#include <string>
#include <vector>
#include <iostream>
#include "../header/user.hpp"
class Leaderboard {
private:
     vector<User> users;

public:
  void addUserToLeaderBoard(const string& filePath, const string& userName, int initialScore);
  void updateScore(const string& userName, int newScore);
  void displayLeaderboard(const string& fileName);
  

};