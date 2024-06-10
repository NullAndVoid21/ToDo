#include <fstream>
#include <algorithm>
#include <windows.h>
#include "TaskList.h"
#include "Utilities.h"

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

    string check = checkOptions("list", options);
    if (check != ""){
        cout << "Unknown optional argument " << check;
        return;
    }

    if (commands.size() == 1){ // Print out full list
        for (int i = 0 ; i < tasks.size(); i++){
            cout << i << ' ' << "\u2588"<< ' ' << tasks[i].name << endl;
            if(find(options.begin(), options.end(), "-d") != options.end()) {
                setColor(DARK_GRAY);
                cout << "  " << "\u2588"<<'\t' << tasks[i].description << endl;
                setColor(WHITE);
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
        setColor(WHITE);
        cout << "\033[4m" << task.name << "\033[24m" << endl;
        setColor(DARK_GRAY);
        cout << task.description << endl;
        cout << task.status << endl;
        setColor(WHITE);
    }

    else{
        cout << "Command not recognized";
        return;
    }
}

void TaskList::add(vector<string> commands, vector<string> options){

    string check = checkOptions("add", options);
    if (check != ""){
        cout << "Unknown optional argument " << check;
        return;
    }
}