#pragma once

#include <string>
#include <vector>

using namespace std;

class DayFive {
private:
	vector<int> BuildSortedSeatIDs(vector<string> input);
	int CalculateSection(string in);
	int BinarySearch(int min, int max, string directions, char up, char down);
public:
	int PartOne(vector<string> input);
	int PartTwo(vector<string> input);
};