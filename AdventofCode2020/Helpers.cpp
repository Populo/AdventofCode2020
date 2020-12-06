#include <fstream>

#include "Helpers.h"

vector<string> Helpers::ReadFile(string fileName) {
    vector<string> input;

    ifstream file(fileName);
    string line;
    string::iterator sit;
    string cleanStr = "";
    while (getline(file, line)) {
		for (sit = line.begin(); sit < line.end(); ++sit) // day 5 has garbage in input for some reason :(
		{
            int charId = (int)*sit;
            if (charId >= 0) cleanStr += *sit;
		}
        input.push_back(cleanStr);
        cleanStr = "";
    }
    file.close();

    return input;
}

// can also be used for day 6
vector<string> Helpers::CleanUpDayFour(vector<string> input) {
    vector<string> cleaned;

    vector<string>::iterator it;

    string current;
    for (it = input.begin(); it < input.end(); ++it) {
        if (*it == "") {
            cleaned.push_back(current);
            current = "";
        }
        else {
            if (current.empty()) current += *it;
            else {
                current += " ";
                current += *it;
            }
        }
    }

    // handle last one
    if (!current.empty()) cleaned.push_back(current);

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

// dear god have mercy on my soul
vector<string> Helpers::SplitOnChar(string s, char delim)
{
    vector<string> out;
    string cur = "";

	for(auto it = s.begin(); it < s.end(); ++it)
	{
		if (*it == delim)
		{
            out.push_back(cur);
            cur = "";
		} else
		{
            cur += *it;
		}
	}

    out.push_back(cur);
	
    return out;
}

