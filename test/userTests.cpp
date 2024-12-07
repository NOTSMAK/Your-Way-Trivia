//check for output when two answers are true;
//check for incorrect input or out of ordinary inputs;
//create quiz doesn't count questions correctly so I inputed 3 questions to add and it gave me options for 4
#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "../header/user.hpp"

class Player {
public:
    std::string getName() const { return name; }
    void setScore(int userScore) { score = userScore; }
    void setName(std::string userName) { name = userName; }
    int getScore() const { return score; }
    void updateScore(int newScore) { score = newScore; }

private:
    std::string name;
    int score = 0;
};

TEST(PlayerTest, GetNameReturnsCorrectName) {
    Player p;
    p.setName("Alice");
    EXPECT_EQ(p.getName(), "Alice");
}

TEST(PlayerTest, SetScoreSetsCorrectValue) {
    Player p;
    p.setScore(42);
    EXPECT_EQ(p.getScore(), 42);
}

TEST(PlayerTest, SetNameSetsCorrectValue) {
    Player p;
    p.setName("Bob");
    EXPECT_EQ(p.getName(), "Bob");
}

TEST(PlayerTest, GetScoreReturnsCorrectValue) {
    Player p;
    p.setScore(100);
    EXPECT_EQ(p.getScore(), 100);
}

TEST(PlayerTest, UpdateScoreSetsCorrectValue) {
    Player p;
    p.setScore(10);
    p.updateScore(50);
    EXPECT_EQ(p.getScore(), 50);
}



