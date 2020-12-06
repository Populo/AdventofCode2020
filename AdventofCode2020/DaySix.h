#pragma once
#include <string>
#include <vector>

class DaySix
{
private:
	std::string GetUniqueChars(std::string s);
	std::string Thunderdome(std::string unique, std::vector<std::string> participants);
public:
	int PartOne(std::vector<std::string> input);
	int PartTwo(std::vector<std::string> input);
};