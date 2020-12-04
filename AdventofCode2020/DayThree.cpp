#include "DayThree.h"

using namespace std;

int DayThree::PartOne(vector<string> input)
{
    int hits = 0;

    if (input.empty()) return 0;

    int width = input[0].size();
    int currentX = 0;

    vector<string>::iterator it;

    for (it = input.begin()+1; it < input.end(); ++it) {
        currentX = (currentX + DX) % width;
        string line = *it;
        char tree = line[currentX];
        
        if (tree == '#') ++hits;
    }

    return hits;
}

long long DayThree::PartTwo(vector<string> input)
{
    if (input.empty()) return 0;

    long long result = 1; // multiplication

    const int trials = 5;
    int lineSize = input[0].size();
    int hits;
    vector<string>::iterator it;
    vector<int> hitCounts;
    vector<int>::iterator hitIt;

    int steps[trials][2] = {
        {1, 1},
        {3, 1},
        {5, 1},
        {7, 1},
        {1, 2}
    };

    int currentX, currentY = 0;
    int i = 0;
    for (i; i < trials; ++i) {
        int x = steps[i][0];
        int y = steps[i][1];
        hits = 0;

        currentX = 0;
        currentY = 0;

        it = input.begin();
        while ((currentY + y) < input.size()) {
            it += y;
            currentY += y; // fix y = 2 going out of bounds

            currentX = (currentX + x) % lineSize;
            string line = *it;

            char tree = line[currentX];
            if (tree == '#') ++hits;
        }

        hitCounts.push_back(hits);
    }

    for (hitIt = hitCounts.begin(); hitIt < hitCounts.end(); ++hitIt) {
        result *= *hitIt;
    }

    return result;
}
