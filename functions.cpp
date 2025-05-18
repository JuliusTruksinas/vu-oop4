#include "functions.h"

string cleanWord(const string& word) {
    string cleaned;
    for (char ch : word) {
        if (isalpha(ch) || isdigit(ch))
            cleaned += tolower(ch);
    }
    return cleaned;
}