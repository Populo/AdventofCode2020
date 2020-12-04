#pragma once

#include <vector>
#include <string>

using namespace std;

class Helpers {
public:
	vector<string> ReadFile(string file);
	vector<int> ConvertToInt(vector<string> s);
};