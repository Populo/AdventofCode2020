#include "DaySix.h"
#include "Helpers.h"

using namespace std;

Helpers h;

string DaySix::GetUniqueChars(string s)
{
    string u = "";
	for(auto i = s.begin(); i < s.end(); ++i)
	{
		if (*i >= 'a' && *i <= 'z')
		{
            auto occ = u.find_first_of(*i);
            if (occ == string::npos) u += *i;
		}
	}
    return u;
}

std::string DaySix::Thunderdome(string unique, vector<string> participants)
{
    vector<string>::iterator it;
	
    for(int i = 0; i < unique.size(); ++i)
    {
	    for(it = participants.begin(); it < participants.end(); ++it)
	    {
            auto loc = (*it).find(unique[i]);
	    	if (loc == string::npos)
	    	{
                unique.erase(i, 1);
                --i; // jesus
                break;
	    	}
	    }
    }

    return unique;
}

int DaySix::PartOne(vector<string> input)
{
    int sum = 0;
    for(auto it = input.begin(); it < input.end(); ++it)
    {
    	string u = GetUniqueChars(*it);
        sum += u.size();
    }
    return sum;
}

int DaySix::PartTwo(std::vector<std::string> input)
{
    int sum = 0;

    for (auto it = input.begin(); it < input.end(); ++it)
    {
        string u = GetUniqueChars(*it);

        auto participants = h.SplitOnChar(*it, ' ');
    	
        u = Thunderdome(u, participants);
    	
        sum += u.size();
    }

    return sum;
}
