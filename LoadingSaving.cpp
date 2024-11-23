#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

using namespace std;

void assignName() {
    string fileName;
    cout << "Enter the file name: ";
    getline(cin, fileName);

    ofstream file(fileName);
    if (!file) {
        cerr << "Unable to open file " << fileName << endl;
        return;
    }

    string secretTitle;
    cout << "Enter a secret title for the file: ";
    getline(cin, secretTitle);

    file << "\n" << secretTitle << endl;
    file.close();

    cout << "Secret title added to the file." << endl;
}

void loadQuiz() {
    string secretTitle;
    cout << "Enter the secret title to load the quiz: ";
    getline(cin, secretTitle);

    bool found = false;

    for (auto& p : file(fileName)) {
        ifstream file(p.path());
        if (!file) continue;

        string line, lastLine;
        while (getline(file, line)) {
            if (!line.empty()) lastLine = line;
        }

        if (lastLine == secretTitle) {
            found = true;
            cout << "Quiz found in file: " << p.path().filename() << endl;
            ifstream quizFile(p.path());
            cout << quizFile.rdbuf();
            quizFile.close();
            break;
        }
    }

    if (!found) {
        cout << "Quiz with the title not found." << endl;
    }
}
