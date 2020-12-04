#pragma once

#include <string>
#include <vector>

using namespace std;

class DayFour {
private:
	bool ProcessPassport(string in);
public:
	int PartOne(vector<string> input);
	int PartTwo(vector<string> input);
};