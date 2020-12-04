#include "DayTwo.h"

bool DayTwo::CheckPassword(string input, bool p2 = false)
{
    bool valid = false;

    int colonInd = input.find(':');
    string requirements = input.substr(0, colonInd);
    string password = input.substr(colonInd + 2); // ignore space and colon

    int sepInd = requirements.find('-');
    int spaceInd = requirements.find(' ');
    int min = stoi(requirements.substr(0, sepInd));
    int max = stoi(requirements.substr(sepInd+1, spaceInd)); // drop -
    string toFind = requirements.substr(spaceInd + 1); // drop space, string because i'm assuming part 2 will have strings instead of chars

    if (!p2) {
        int appearances = 0;
        for (int i = 0; i < password.size(); ++i) {
            string check = password.substr(i, toFind.size());
            if (check.size() < toFind.size()) break; // too far into the string to find any more matches
            if (check == toFind) ++appearances;
        }

        if (appearances >= min && appearances <= max) valid = true;
    }
    else {
        // my part 2 assumption was wrong lol
        char c1 = password[min-1]; // index 1 = index 0
        char c2 = password[max-1]; // index 1 = index 0

        if ((c1 == toFind[0]) ^ (c2 == toFind[0])) valid = true;
    }
    
    return valid;
}

int DayTwo::PartOne(vector<string> input)
{
    int c = 0;

    vector<string>::iterator i;
    for (i = input.begin(); i < input.end(); ++i) {
        bool valid = CheckPassword(*i);
        if (valid) ++c;
    }

    return c;
}

int DayTwo::PartTwo(vector<string> input)
{
    int c = 0;

    vector<string>::iterator i;
    for (i = input.begin(); i < input.end(); ++i) {
        bool valid = CheckPassword(*i, true);
        if (valid) ++c;
    }

    return c;
}
