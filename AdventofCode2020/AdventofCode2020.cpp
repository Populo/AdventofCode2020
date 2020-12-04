// AdventofCode2020.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include "Helpers.h"
#include "DayOne.h"

string year = "2020", day = "01";

using namespace std;

int main()
{
    cout << "Year: " << year << " Day: " << day << endl;
    Helpers h;
    DayOne d;
    string fileName = year + "." + day + ".txt";
    vector<string> input = h.ReadFile(fileName);
    vector<int> inputInt = h.ConvertToInt(input);
    // sort
    sort(inputInt.begin(), inputInt.end());

    cout << "Part One: " << d.PartOne(inputInt) << endl;
    cout << "Part Two: " << d.PartTwo(inputInt) << endl;
}

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
