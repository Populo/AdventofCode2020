#include <fstream>

#include "Helpers.h"

vector<string> Helpers::ReadFile(string fileName) {
    vector<string> input;

    ifstream file(fileName);
    string line;
    while (getline(file, line)) {
        input.push_back(line);
    }
    file.close();

    return input;
}

vector<int> Helpers::ConvertToInt(vector<string> s) {
    vector<int> i;

    vector<string>::iterator it;

    for (it = s.begin(); it != s.end(); ++it) {
        i.push_back(stoi(*it));
    }

    return i;
}

