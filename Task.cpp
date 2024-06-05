#include <iostream>
#include <string>
#include "Task.h"

using namespace std;

Task::Task(string name){
    this->name = name;
}
Task::Task(){
    this->name = "No Name";
}

void Task::print(void){
    cout << name;
}
