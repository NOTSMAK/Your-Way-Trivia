#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>
using namespace std;

class GameManager {
private:
    vector<TriviaGame*> games;

public:
    void displayOptions();
    void StartGame(string file) const; //runs the game, keeps track of the score, displays questions, gets user input 
    string createGame(); // returns game title
    void loadGame(const string& filePath);
    void viewLeaderboad() const; // opens leaderboard file and prints it to terminal
   
    //running game functions

    void run(TriviaGame* game); // display questions, current score, and correct and user answers
    
    
};

class TriviaGame {
private:

    string title; // title of the trivia
    QuestionPool pool; // question pool
public:
    QuestionPool* getPool(){return &pool;} 
    string getTitle(){return title;}
    void addQuestion(Question* question);
    void loadFromPool(const string& filePath, const string& format); // loadQuestions specific format questions from pool 
    void saveGame(const string& filePath) const; //save the trivia
    void randomizePool(); // randomize the poool for use
};

class Question {
protected:
    string correctAnswer;
    string userAnswer;
public:
    virtual void display() const = 0; // display
    virtual bool checkAnswer(const string& userAnswer) const = 0; // check answer function
    virtual string serialize() const = 0;
    virtual ~Question() = default; 
};

//In1
class MultipleChoiceQuestion : public Question {
private:
    vector<string> options;

public:
    void display() const override;
    bool checkAnswer(const string& userAnswer) const override;
    string serialize() const override;
};
//In2
class TrueFalseQuestion : public Question {
private:
    bool correctAnswer;

public:
    void display() const override;
    bool checkAnswer(const string& userAnswer) const override;
    string serialize() const override;
};

// In3
class OneWordResponseQuestion : public Question {
public:
    void display() const override;
    bool checkAnswer(const string& userAnswer) const override;
    string serialize() const override;
};

// QuestionPool class
class QuestionPool {
private:
   
public:
    vector<Question*> pool; 
    void loadFromFile(const string& filePath, const string& format);
    vector<Question*> getQuestionsByType(const string& type, int count);
    ~QuestionPool();
};


class User {
private:
    string name;
    int score = 0;

public:
    

    string getName() const { return name; }
    void setScore(int userScore) {score = userScore; }
    void setName(string userName) {name = userName;}
    int getScore() const { return score; }
    void updateScore(int newScore) { score = newScore; }
};

class Leaderboard {
private:
     vector<User> users;

public:
  void addUserToLeaderBoard(const string& filePath, const string& userName, int initialScore);
  void updateScore(const string& userName, int newScore);
  void displayLeaderboard(const string& fileName);
  

};
#endif 