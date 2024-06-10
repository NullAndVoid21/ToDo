#ifndef TASKLIST_H
#define TASKLIST_H
#include <string>
#include <vector>
#include <fstream>
#include "Task.h"
#include <map>

using namespace std;
class TaskList{
    private:
    string fileName;
    vector<Task> tasks;
    map<string, int> lookup;
    map<string, vector<string>> acceptedOptions;
    public:
    TaskList(string);
    void write(void);

    // Main Functions
    void list(vector<string>, vector<string>);
    void add(vector<string>, vector<string>);
};

#endif