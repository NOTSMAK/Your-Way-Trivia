#ifndef trivia_game_H
#define trivia_game_H

#include <string>
#include <vector>
#include "./question.hpp"

using namespace std;

class triviaGame : Question {
    std::string title;
    std::vector<Question> questions;

    public:

    triviaGame();
    void setTitle(std::string title) { this->title = title; }
    void addQuestion(int type, std::string question, answerOption option) { questions.push_back(Question(type, question, option)); }
    void addQuestionOption(answerOption option) { options.push_back(option); }
    const int numQuestions() { return questions.size(); }
    const string& getTitle() { return title; }
    const int getType(int questionIndex) { return questions.at(questionIndex).type; }
    const string& getQuestion(int questionIndex) { return questions.at(questionIndex).question; }
    const string& getAnswer(int questionIndex, int answerIndex) { return questions.at(questionIndex).getAnswer(answerIndex); }
    const bool& getAnswerCorrectness(int questionIndex, int answerIndex) { return questions.at(questionIndex).getAnswerCorrectness(answerIndex); }
};

#endif