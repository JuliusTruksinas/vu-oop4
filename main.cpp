#include "functions.h"
#include "common.h"

int main() {
    ifstream input("text.txt");
    ofstream wordOutput("words.txt");
    ofstream urlOutput("urls.txt");
    ofstream xrefOutput("xref.txt");

    if (!input.is_open()) {
        cout << "Failed to open text.txt" << endl;
        return 1;
    }

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

            string word = cleanWord(word);
            if (!word.empty()) {
                wordInfo[word].first++;
                wordInfo[word].second.insert(lineNum);
            }
        }
    }

    wordOutput << "Word\tCount\n";
    for (const auto& [word, info] : wordInfo) {
        if (info.first > 1) {
            wordOutput << word << "\t" << info.first << "\n";
        }
    }

    xrefOutput << "Word\tCount\tLines\n";
    for (const auto& [word, info] : wordInfo) {
        if (info.first > 1) {
            xrefOutput << word << "\t" << info.first << "\t";
            for (int lineNum : info.second) {
                xrefOutput << lineNum << " ";
            }
            xrefOutput << "\n";
        }
    }

    input.close();
    wordOutput.close();
    urlOutput.close();
    xrefOutput.close();
        
    return 0;
}