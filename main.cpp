#include "functions.h"
#include "common.h"

int main() {
    ifstream input("text.txt");
    ofstream wordOutput("output.txt");
    ofstream urlOutput("url.txt");
    ofstream xrefOutput("xref.txt");

    if (!input.is_open()) {
        cout << "Failed to open text.txt" << endl;
        return 1;
    }

    unordered_map<string, pair<int, set<int>>> wordInfo;
    set<string> urls;

    string line;
    int lineNum = 0;

    while (getline(input, line)) {
        lineNum++;
        stringstream ss(line);
        string word;

        while (ss >> word) {
            if (isURL(word)) {
                urls.insert(word);
                continue;
            }

            string word = cleanWord(word);
            if (!word.empty()) {
                wordInfo[word].first++;
                wordInfo[word].second.insert(lineNum);
            }
        }
    }

    input.close();
    wordOutput.close();
    urlOutput.close();
    xrefOutput.close();
        
    return 0;
}