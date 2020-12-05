#include "DayFive.h"

#include <algorithm>

vector<int> DayFive::BuildSortedSeatIDs(vector<string> input)
{
    vector<string>::iterator sit;
    vector<int> seatIDs;

    for (sit = input.begin(); sit < input.end(); ++sit)
    {
        seatIDs.push_back(CalculateSection(*sit));
    }

    std::sort(seatIDs.begin(), seatIDs.end());

    return seatIDs;
}

int DayFive::CalculateSection(string in)
{	
    string fb = in.substr(0, 7);
    string lr = in.substr(7);

    int row = BinarySearch(0, 127, fb, 'B', 'F');
    int column = BinarySearch(0, 7, lr, 'R', 'L');

    return (row * 8) + column;
}

int DayFive::BinarySearch(int min, int max, string directions, char up, char down)
{
    if (min == max) return min;
    if (directions.empty()) return min;

    double dblHalf = (max-min) / 2.0;
	
    int half = (int)(dblHalf + 0.5) + min;
	if (directions[0] == up)
	{
        return BinarySearch(half, max, directions.substr(1), up, down);
	}

	if (directions[0] == down)
    {
        return BinarySearch(min, half, directions.substr(1), up, down);
    }
}

int DayFive::PartOne(vector<string> input)
{
    return *(BuildSortedSeatIDs(input).end() - 1);
}

int DayFive::PartTwo(vector<string> input)
{
    vector<int> seatIDs = BuildSortedSeatIDs(input);

    vector<int>::iterator it;

    int p = 0, c = 0;
	
	for(it = seatIDs.begin() + 1; it < seatIDs.end() - 2; ++it)
	{
        p = *(it - 1);
        c = *(it);

        if ((p + 1) != c) return p + 1;
	}

    return 0;
}
