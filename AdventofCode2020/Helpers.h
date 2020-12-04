#pragma once

#include <vector>
#include <string>

using namespace std;

class Helpers {
public:
	vector<string> ReadFile(string file);
	vector<string> CleanUpDayFour(vector<string> input);
	vector<int> ConvertToInt(vector<string> s);
};