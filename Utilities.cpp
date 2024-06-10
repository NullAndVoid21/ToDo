#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <windows.h>
#include "Utilities.h"

using namespace std;

bool isNumber(string s)
{
    for (char c : s) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

string checkOptions(string function, vector<string> options){
    if (acceptedOptions.find(function) == acceptedOptions.end()) {
        throw invalid_argument("Invalid function");
    }

    vector<string> accepted = acceptedOptions[function];

    for (int i = 0; i < options.size(); i++){
        if (count(accepted.begin(), accepted.end(), options[i]) > 0) continue;
        else{
            return options[i];
        }
    }

    return "";
}




int WHITE = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
int LIGHT_GRAY =  FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
int DARK_GRAY = FOREGROUND_INTENSITY;

map<string, vector<string>> acceptedOptions = {
        {"list", {"-d"}},
        {"add", {""}}
};