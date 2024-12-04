#include <string>
#include <vector>
using namespace std;
class triviaGame {

    string title;
    vector<int> type;
    vector<string> question;
    vector<vector<string>> options;  
    vector<string> answer;

    public:

    void setTitle (const string& newTitle) { title = newTitle; }
    void addType (const int& newType) { type.push_back(newType); }
    void addQuestion (const string& newQuestion) { question.push_back(newQuestion); }
    void addOptions (vector<string> newOptions) { options.push_back(newOptions); }
    void addAnswer (const string& newAnswer) { answer.push_back(newAnswer); }
    int numberOfQuestions() {return question.size();}
    const string& getTitle() {return title;}
    int getType(int questionIndex) {return type.at(questionIndex);}
    const string& getQuestion(int questionIndex) {return question.at(questionIndex);}
    const vector<string>& getOptions(int questionIndex) {return options.at(questionIndex);}
    const string& getAnswer(int questionIndex) {return answer.at(questionIndex);}
};