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

    taskList.write();
    
}


    // if (argc == 2){ // No other arguments
    //         for (int i = 0; i < tasks.size(); i++) cout << tasks[i].name << endl;
    //     }d

    //     else{
    //         for (int i = 0; i < tasks.size(); i++){
    //             if (argv[2] == tasks[i].name){
    //                 task = tasks[i];

    //                 cout << endl;
    //                 setColor(15);
    //                 cout << "\033[4m" << task.name << "\033[24m" << endl;
    //                 setColor(8);
    //                 cout << task.description << endl;
    //                 cout << task.status << endl;

    //                 break;
    //             }
    //             else if (i = tasks.size() - 1) cout << "No task found with that name";
    //         }
    //     }

    //     setColor(15);