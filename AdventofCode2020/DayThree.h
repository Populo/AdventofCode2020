#pragma once

#include <vector>
#include <string>

using namespace std;

class DayThree {
private:
	int DX = 3;
	int DY = 1;
public:
	int PartOne(vector<string> input);
	long long PartTwo(vector<string> input);
};