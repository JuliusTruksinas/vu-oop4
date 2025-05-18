#include "functions.h"

string cleanWord(const string& word) {
    string cleaned;
    for (char ch : word) {
        if (isalpha(ch) || isdigit(ch))
            cleaned += tolower(ch);
    }
    return cleaned;
}

// this function returns true if the word passed in is a URL
bool isURL(const string& word) {
    regex url_regex(R"((https?://)?(www\.)?[a-zA-Z0-9\-]+\.(lt|com|org|net|edu|gov|io|co)(/\S*)?)");
    return regex_match(word, url_regex);
}
