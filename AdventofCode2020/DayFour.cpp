#include "DayFour.h"

#include <regex>

using namespace std;

bool DayFour::ProcessPassport(string in) {
    bool valid = true;

    /*
        ecl
        pid
        eyr
        hcl
        byr
        iyr
        cid - optional at moment
        hgt
    */

    regex eclRegex("(ecl:){1}(amb|blu|brn|gry|grn|hzl|oth){1}"),
        pidRegex("(pid:){1}([0-9]){9}(?![0-9])"), // lol space to stop at length 9
        eyrRegex("(eyr:){1}(20){1}([0-9]){2}"),
        hclRegex("(hcl:{1,1})(#)([0-9]|[a-f]){6}"),
        iyrRegex("(iyr:){1}(20){1}([0-9]){2}"),
        hgtRegex("(hgt:){1}([0-9]+)(in|cm){1}"),
        byrRegex("(byr:){1}([0-9]){4}");

    smatch m;

    regex_search(in, m, eclRegex);
    if (m.empty()) valid = false;
    else
    {
	    // do i need anything?
    }

    regex_search(in, m, byrRegex);
    if (m.empty()) valid = false;
    else
    {
	    // if this is in here then we can assume the first is the full match
        string clause = m[0].str();
        int split = clause.find(':');
        int year = stoi(clause.substr(split + 1)); // ignore :
        if (year < 1920 || year > 2002) valid = false;
    }

    regex_search(in, m, pidRegex);
    if (m.empty()) valid = false;
    else
    {
	    // shouldnt need anything
    }

    regex_search(in, m, iyrRegex);
    if (m.empty()) valid = false;
    else
    {
        // if this is in here then we can assume the first is the full match
        string clause = m[0].str();
        int split = clause.find(':');
        int year = stoi(clause.substr(split + 1)); // ignore :
        if (year < 2010 || year > 2020) valid = false;
    }
    
    regex_search(in, m, eyrRegex);
    if (m.empty()) valid = false;
    else
    {
        // if this is in here then we can assume the first is the full match
        string clause = m[0].str();
        int split = clause.find(':');
        int year = stoi(clause.substr(split + 1)); // ignore :
        if (year < 2020 || year > 2030) valid = false;
    }
    
    regex_search(in, m, hclRegex);
    if (m.empty()) valid = false;
    else
    {
	    // shouldnt need anything
    }

    regex_search(in, m, hgtRegex);
    if (m.empty()) valid = false;
    else
    {
        // if this is in here then we can assume the first is the full match
        string clause = m[0].str();
        int split = clause.find(':');
        int height = stoi(clause.substr(split + 1, clause.size() - 2)); // ignore : and unit
        string unit = clause.substr(clause.size() - 2);

        if (unit == "cm")
        {
            if (height < 150 || height > 193) valid = false;
        } else if (unit == "in")
        {
            if (height < 59 || height > 76) valid = false;
        } else
        {
            valid = false;
        }
    }

    return valid;
}

int DayFour::PartOne(vector<string> input)
{
    int valid = 0;

    vector<string>::iterator it;

    for (it = input.begin(); it < input.end(); ++it) {
        if (ProcessPassport(*it)) ++valid;
    }

    return valid;
}

int DayFour::PartTwo(vector<string> input)
{
    int valid = 0;

    vector<string>::iterator it;

    for (it = input.begin(); it < input.end(); ++it) {
        if (ProcessPassport(*it)) ++valid;
    }

    return valid;
}
