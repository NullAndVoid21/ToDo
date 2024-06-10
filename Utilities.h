#ifndef UTILITIES_H
#define UTILITIES_H
#include <string>
#include <vector>
#include <map>
#include <windows.h>

using namespace std;

bool isNumber(string);
void setColor(int);
string checkOptions(string, vector<string>);

extern int WHITE;
extern int LIGHT_GRAY;
extern int DARK_GRAY;
extern map<string, vector<string>> acceptedOptions;

#endif