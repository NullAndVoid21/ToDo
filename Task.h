#ifndef TASK_H
#define TASK_H
#include <iostream>
#include <string>

using namespace std;

class Task{
public:
    string name;
    string description = "No Description";
    string status = "No Status";
    Task(string);
    Task();
    void print(void);
};

#endif