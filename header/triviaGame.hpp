#include <string>
#include <vector>

class triviaGame {

    std::string title;
    std::vector<int> type;
    std::vector<std::string> question;
    std::vector<std::vector<std::string>> options;  
    std::vector<std::string> answer;

    public:

    void setTitle (const std::string& newTitle) { title = newTitle; }
    void addType (const int& newType) { type.push_back(newType); }
    void addQuestion (const std::string& newQuestion) { question.push_back(newQuestion); }
    void addOptions (std::vector<std::string> newOptions) { options.push_back(newOptions); }
    void addAnswer (const std::string& newAnswer) { answer.push_back(newAnswer); }
    int numberOfQuestions() { return question.size(); }
    const string& getTitle() { return title; }
    int getType(int questionIndex) { return type.at(questionIndex); }
    const string& getQuestion(int questionIndex) { return question.at(questionIndex); }
    const vector<string>& getOptions(int questionIndex) { return options.at(questionIndex); }
    const string& getAnswer (int questionIndex) { return answer.at(questionIndex); }
};