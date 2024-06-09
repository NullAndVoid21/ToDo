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
    public:
    TaskList(string);
    void write(void);

    void list(vector<string>, vector<string>);

    vector<Task> tasks;
    map<string, int> lookup;
};

bool isNumber(string);
void setColor(int);


#endif