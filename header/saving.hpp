#include <string>
#include <vector>

using namespace std;


struct savedQuiz {
    string title;
    int type;
    vector<string> question;
    vector<vector<string>> options;  
    vector<string> answer;
    void saveQuiz(const string& quizName);
};