// AdventofCode2020.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include "Helpers.h"
#include "DaySix.h"

string year = "2020", day = "06";

using namespace std;

int main()
{
    cout << "Year: " << year << " Day: " << day << endl;
    Helpers h;
    DaySix d;
    string fileName = year + "." + day + ".txt";
    vector<string> input = h.ReadFile(fileName);
    input = h.CleanUpDayFour(input);
    //vector<int> inputInt = h.ConvertToInt(input);
    // sort
    //sort(inputInt.begin(), inputInt.end());

    cout << "Part One: " << d.PartOne(input) << endl;
    cout << "Part Two: " << d.PartTwo(input) << endl;
}
