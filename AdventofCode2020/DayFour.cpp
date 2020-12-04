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

    regex eclRegex("(.*)(ecl:)+(.*)"),
        pidRegex("(.*)(pid:)+(.*)"),
        eyrRegex("(.*)(eyr:)+(.*)"),
        hclRegex("(.*)(hcl:)+(.*)"),
        iyrRegex("(.*)(iyr:)+(.*)"),
        cidRegex("(.*)(cid:)+(.*)"),
        hgtRegex("(.*)(hgt:)+(.*)"),
        byrRegex("(.*)(byr:)+(.*)");

    smatch m;

    regex_search(in, m, eclRegex);
    if (m.size() == 0) valid = false;
    else {}

    regex_search(in, m, byrRegex);
    if (m.size() == 0) valid = false;
    else {}

    regex_search(in, m, pidRegex);
    if (m.size() == 0) valid = false;
    else {}

    regex_search(in, m, iyrRegex);
    if (m.size() == 0) valid = false;
    else {}
    
    regex_search(in, m, eyrRegex);
    if (m.size() == 0) valid = false;
    else {}
    
    regex_search(in, m, hclRegex);
    if (m.size() == 0) valid = false;
    else {}
    
    regex_search(in, m, cidRegex);
    if (m.size() == 0) {}//valid = false;
    else {}

    regex_search(in, m, hgtRegex);
    if (m.size() == 0) valid = false;
    else {}

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
    return 0;
}
