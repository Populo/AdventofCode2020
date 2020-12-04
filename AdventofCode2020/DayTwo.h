#pragma once

#include <vector>
#include <string>

using namespace std;

class DayTwo {
private:
	bool CheckPassword(string input, bool p2);
public:
	int PartOne(vector<string> input);
	int PartTwo(vector<string> input);
};