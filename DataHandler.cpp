#include <fstream>
#include <vector>
#include "Task.h"

using namespace std;

vector<Task> load(string fileName){

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
    Task task;
    vector<Task> tasks;

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

    return tasks;
}

void write(string fileName, vector<Task> tasks){
    ofstream file(fileName);
    for (int i = 0; i < tasks.size(); i++){
        file << tasks[i].name << endl;
        file << '\t' << tasks[i].description << endl;
        file << '\t' << tasks[i].status << endl;
        if (i != tasks.size() - 1) file << endl;
    }
    file.close();
}
