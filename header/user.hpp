#include <string>
#include <vector>
using namespace std;
class User {
private:
    string name;
    int score = 0;

public:
    User(const string& uname, int scr) : name(uname), score(scr) {}
    void playGame();
    void createGame();
    string getName() const { return name; }
    void setScore(int userScore) {score = userScore; }
    void setName(string userName) {name = userName;}
    int getScore() const { return score; }
    void updateScore(int newScore) { score = newScore; }
    
};