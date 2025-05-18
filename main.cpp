#include "functions.h"
#include "common.h"

int main() {
    ifstream input("text.txt");

    if (!input.is_open()) {
        cout << "Failed to open text.txt" << endl;
        return 1;
    }

    ofstream wordOutput("words.txt");
    ofstream urlOutput("urls.txt");
    ofstream xrefOutput("xref.txt");

    /*
        the maps keys are words, the value is a pair in which the first element is an int representing
        the amount of times the word has repeated, the second element is a set<int> that represents
        at what line numbers that particular word was encountered.
    */
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

            string cleanedWord = cleanWord(word);
            if (!cleanedWord.empty()) {
                wordInfo[cleanedWord].first++;
                wordInfo[cleanedWord].second.insert(lineNum);
            }
        }
    }

    wordOutput << left << setw(15) << "Word" 
           << setw(10) << "Count" << endl;

    for (const auto& [word, info] : wordInfo) {
        if (info.first > 1) {
            wordOutput << left << setw(15) << word 
                    << setw(10) << info.first << endl;
        }
    }

    xrefOutput << left << setw(15) << "Word"
           << setw(10) << "Count"
           << "Lines" << endl;

    for (const auto& [word, info] : wordInfo) {
        if (info.first > 1) {
            xrefOutput << left << setw(15) << word
                    << setw(10) << info.first;

            for (int lineNum : info.second) {
                xrefOutput << lineNum << " ";
            }
            xrefOutput << endl;
        }
    }

    for (const string& url : urls) {
        urlOutput << url << endl;
    }

    input.close();
    wordOutput.close();
    urlOutput.close();
    xrefOutput.close();

    cout << "Successfully finished." << endl;
        
    return 0;
}