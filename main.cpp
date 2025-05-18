#include "functions.h"
#include "common.h"

int main() {
    ifstream input("text.txt");
    ofstream wordOutput("output.txt");
    ofstream urlOutput("url.txt");
    ofstream xrefOutput("xref.txt");

    if (!input.is_open()) {
        cerr << "Failed to open text.txt\n";
        return 1;
    }

    input.close();
    wordOutput.close();
    urlOutput.close();
    xrefOutput.close();
        
    return 0;
}