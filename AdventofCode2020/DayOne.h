#pragma once

#include <vector>

using namespace std;

class DayOne {
	private:
		int BinarySumFinder(int i, vector<int> toSearch, int j);
	public:
		int PartOne(vector<int> input);
		int PartTwo(vector<int> input);
};
