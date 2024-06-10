#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <windows.h>
#include "Task.h"
#include "TaskList.h"

using namespace std;

int main (int argc, char *argv[]){
    TaskList taskList("data.txt");
    vector<string> commands;
    vector<string> options;
    
    string arg;

    for (int i = 1; i < argc; i++){
        arg = argv[i];
        if (arg[0] == '-'){
            options.push_back(arg);
        }
        else{
            commands.push_back(arg);
        }
    }

    string command = commands[0];

    if (command == "list"){
        taskList.list(commands, options);
    }

    else if (command == "add"){
        taskList.add(commands, options);
    }

    taskList.write();
    
}
