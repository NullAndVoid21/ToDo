#include <fstream>
#include <algorithm>
#include <windows.h>
#include "TaskList.h"

TaskList::TaskList(string fileName){

    this->fileName = fileName;

    ifstream file(fileName);
    vector<string> lines;
    string line;
    while (getline (file, line)) {
        lines.push_back(line);
    }
    file.close();

    int index;
    int taskCount;
    size_t startPos;

    for (int i = 0; i < lines.size(); i++){
        index = i % 4;
        taskCount = i / 4;

        // Removes any leading whitespace
        startPos = lines[i].find_first_not_of(" \t\n\r");
        if (startPos != std::string::npos) lines[i] = lines[i].substr(startPos);
        
        switch(index){
            case 0: // Name
                tasks.push_back(Task());
                tasks[taskCount].name = lines[i];
                lookup[lines[i]] = taskCount;
                break;
            case 1: // Description
                tasks[taskCount].description = lines[i];
                break;
            case 2: // Status
                tasks[taskCount].status = lines[i];
                break;
            case 3: // Endline
                break;
        }
    }
}

void TaskList::write(void){
    ofstream file(fileName);
    for (int i = 0; i < tasks.size(); i++){
        file << tasks[i].name << endl;
        file << '\t' << tasks[i].description << endl;
        file << '\t' << tasks[i].status << endl;
        if (i != tasks.size() - 1) file << endl;
    }
    file.close();
}

void TaskList::list(vector<string> commands, vector<string> options){
    if (commands.size() == 1){ // Print out full list
        for (int i = 0 ; i < tasks.size(); i++){
            cout << tasks[i].name << endl;
            if(find(options.begin(), options.end(), "-d") != options.end()) {
                cout << '\t' << tasks[i].description << endl;
            }
        } 
    }

    else if(commands.size() == 2){ // Print out single list item
        string name = commands[1];
        int index;
        if (isNumber(name)) index = stoi(name);
        else{
            if (lookup.find(name) == lookup.end()){
                cout << "No task with that name";
                return;
            }
            else{
                index = lookup[name];
            }
        }

        if (index > tasks.size() - 1){
            cout << "No task with that index";
            return;
        }

        Task task = tasks[index];

        cout << endl;
        setColor(15);
        cout << "\033[4m" << task.name << "\033[24m" << endl;
        setColor(8);
        cout << task.description << endl;
        cout << task.status << endl;
    }
}




// Utilities

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