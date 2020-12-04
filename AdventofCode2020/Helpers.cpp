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

vector<string> Helpers::CleanUpDayFour(vector<string> input) {
    vector<string> cleaned;

    vector<string>::iterator it;

    string current = "";
    for (it = input.begin(); it < input.end(); ++it) {
        if (*it == "") {
            cleaned.push_back(current);
            current = "";
        }
        else {
            if (current == "") current += *it;
            else {
                current += " ";
                current += *it;
            }
        }
    }

    // handle last one
    if (current != "") cleaned.push_back(current);

    return cleaned;
}

vector<int> Helpers::ConvertToInt(vector<string> s) {
    vector<int> i;

    vector<string>::iterator it;

    for (it = s.begin(); it != s.end(); ++it) {
        i.push_back(stoi(*it));
    }

    return i;
}

