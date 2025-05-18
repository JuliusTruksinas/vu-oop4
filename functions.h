#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <cctype>
#include <regex>

using namespace std;

string cleanWord(const string& word);
bool isURL(const string& word);

#endif