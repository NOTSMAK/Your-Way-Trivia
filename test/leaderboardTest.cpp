#include <gtest/gtest.h>
#include "../header/leaderboard.hpp"

class LeaderboardTest : public ::testing::Test {
protected:
    std::string testFileName = "test_leaderboard.log";
    Leaderboard* leaderboard;

    void SetUp() override {
        leaderboard = new Leaderboard(testFileName);

        std::ofstream outFile(testFileName);
        if (outFile.is_open()) {
            outFile << "Quiz1\nAlice\n50\n";
            outFile << "Quiz1\nBob\n40\n";
            outFile << "Quiz1\nCharlie\n60\n";
            outFile.close();
        }
    }

    void TearDown() override {
        delete leaderboard;

        std::remove(testFileName.c_str());
    }
};

//TEST CASES
TEST_F(LeaderboardTest, LogPlay) {
    User newUser{"David", 70};
    leaderboard->logPlay(newUser, "Quiz1");

    std::vector<User> fetchedLeaderboard = leaderboard->fetchLeaderboard("Quiz1");
    ASSERT_EQ(fetchedLeaderboard.size(), 4);  // Should now include 4 users
    EXPECT_EQ(fetchedLeaderboard.back().name, "David");
    EXPECT_EQ(fetchedLeaderboard.back().score, 70);
}

TEST_F(LeaderboardTest, FetchLeaderboard) {
    std::vector<User> fetchedLeaderboard = leaderboard->fetchLeaderboard("Quiz1");
    ASSERT_EQ(fetchedLeaderboard.size(), 3);  // Should contain the 3 initial users

    EXPECT_EQ(fetchedLeaderboard[0].name, "Charlie");  // Sorted by score
    EXPECT_EQ(fetchedLeaderboard[1].name, "Alice");
    EXPECT_EQ(fetchedLeaderboard[2].name, "Bob");
}

TEST_F(LeaderboardTest, DisplayLeaderboard) {
    // Capture the display output
    testing::internal::CaptureStdout();
    leaderboard->displayLeaderboard("Quiz1");
    std::string output = testing::internal::GetCapturedStdout();

    // Verify output contains sorted leaderboard data
    EXPECT_TRUE(output.find("Charlie: 60") != std::string::npos);
    EXPECT_TRUE(output.find("Alice: 50") != std::string::npos);
    EXPECT_TRUE(output.find("Bob: 40") != std::string::npos);
}


