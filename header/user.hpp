#ifndef user_H
#define user_H

#include <string>
#include <vector>

using namespace std;
class User {
private:
    string name;
    int score = 0;

public:
    User() {}
    string getName() const { return name; }
    void setScore(int userScore) {score = userScore; }
    void setName(string userName) {name = userName;}
    int getScore() const { return score; }
    void updateScore(int newScore) { score = newScore; }
};

#endif