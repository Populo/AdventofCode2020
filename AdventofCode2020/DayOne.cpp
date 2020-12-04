#include "DayOne.h"
#include <vector>

using namespace std;

int DayOne::BinarySumFinder(int i, vector<int> toSearch, int j = 0)
{
	int result = 0;
	int base = i + j;

	int middle = toSearch.size() / 2;
	int val = toSearch[middle];

	if (base + val == 2020) {
		return toSearch[middle];
	}
	else {
		if (toSearch.size() == 1) return 0;

		vector<int> searchHalf;
		if (base + val > 2020) {
			if (toSearch.size() == 2) {
				searchHalf.insert(searchHalf.begin(), toSearch.begin(), toSearch.end() - middle);
			}
			else {
				searchHalf.insert(searchHalf.begin(), toSearch.begin(), toSearch.end() - middle - 1);
			}
			return BinarySumFinder(i, searchHalf, j);
		}
		else {
			if (toSearch.size() == 2) {
				searchHalf.insert(searchHalf.begin(), toSearch.begin() + middle, toSearch.end());
			}
			else {
				searchHalf.insert(searchHalf.begin(), toSearch.begin() + middle + 1, toSearch.end());
			}
			return BinarySumFinder(i, searchHalf, j);
		}
	}
	return result;
}

// Day One Part One
// WE ARE ASSUMING ARRAY IS SORTED
int DayOne::PartOne(vector<int> input)
{
	if (NULL == input[0]) return 0;

	int size = input.size();

	bool cont = true;
	int i = 0;
	int j = 0;

	while (cont && i < size) {
		vector<int> subset;
		subset.insert(subset.begin(), input.begin() + i + 1, input.end());
		j = BinarySumFinder(input[i], subset);

		if (j != 0) cont = false;
		else ++i;
	}

	return input[i] * j;
}


int DayOne::PartTwo(vector<int> input) {
	if (NULL == input[0]) return 0;

	int size = input.size();

	bool cont = true;
	int i = 0;
	int j = 0;
	int k = 0;

	while (cont && i < size) {
		j = i + 1;
		while (cont && j < size) {
			vector<int> subset;
			subset.insert(subset.begin(), input.begin() + i + 1, input.end());
			k = BinarySumFinder(input[i], subset, input[j]);
			if (k != 0) cont = false;
			else ++j;
		}
		if (cont) ++i;
	}

	return input[i] * input[j] * k;
}