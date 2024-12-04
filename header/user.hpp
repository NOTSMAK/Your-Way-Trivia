#include <string>
#include <vector>
using namespace std;
class User {
private:
    string name;
    int score = 0;

public:
    
    void playGame();
    void createGame();
    string getName() const { return name; }
    void setScore(int userScore) {score = userScore; }
    void setName(string userName) {name = userName;}
    int getScore() const { return score; }
    void updateScore(int newScore) { score = newScore; }
};