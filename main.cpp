#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>
#include "Task.h"
#include "DataHandler.h"

using namespace std;

void setColor(int);


int main (int argc, char *argv[]){
    vector<Task> tasks;
    Task task;
    string command = argv[1];

    tasks = load("data.txt");

    if (command == "list"){

        if (argc == 2){ // No other arguments
            for (int i = 0; i < tasks.size(); i++) cout << tasks[i].name << endl;
        }

        else{
            for (int i = 0; i < tasks.size(); i++){
                if (argv[2] == tasks[i].name){
                    task = tasks[i];

                    cout << endl;
                    setColor(15);
                    cout << "\033[4m" << task.name << "\033[24m" << endl;
                    setColor(8);
                    cout << task.description << endl;
                    cout << task.status << endl;

                    break;
                }
                else if (i = tasks.size() - 1) cout << "No task found with that name";
            }
        }

        setColor(15);
    }











    else if (command == "add"){
        if (argc == 2){
            // No other arguments
            cout << "No task name given";
        }
        else{
            Task task(argv[2]);
            task.print();
        }
    }
    else {
        //cout << "bruh";
    }

    write("data.txt", tasks);
}


void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}