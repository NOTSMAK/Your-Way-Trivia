//check for output when two answers are true;
//check for incorrect input or out of ordinary inputs;
//create quiz doesn't count questions correctly so I inputed 3 questions to add and it gave me options for 4
#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "../header/question.hpp"


struct answerOption {
    std::string answer;
    bool isCorrect;
};

class Question {
public:
    void addAnswerOption(answerOption newOption) {
        options.push_back(newOption);
    }

    const std::vector<answerOption>& getOptions() const {
        return options;
    }

private:
    std::vector<answerOption> options;
};

TEST(QuestionTest, AddAnswerOption) {
    Question q;

    EXPECT_TRUE(q.getOptions().empty());

    answerOption opt1;
    opt1.answer = "Paris";
    opt1.isCorrect = true;

    q.addAnswerOption(opt1);

    ASSERT_EQ(q.getOptions().size(), 1);
    EXPECT_EQ(q.getOptions()[0].answer, "Paris");
    EXPECT_TRUE(q.getOptions()[0].isCorrect);

    answerOption opt2;
    opt2.answer = "London";
    opt2.isCorrect = false;

    q.addAnswerOption(opt2);

    ASSERT_EQ(q.getOptions().size(), 2);
    EXPECT_EQ(q.getOptions()[1].answer, "London");
    EXPECT_FALSE(q.getOptions()[1].isCorrect);
    
}