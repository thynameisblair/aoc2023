#pragma once

#include <fstream> // ifstream
#include <iostream> // cout
#include <string> // getline
#include <vector>

auto ReadLines(const std::string& in)
{
    std::ifstream infile(in);
    std::vector<std::string> result;
    std::string line;
    while (std::getline(infile, line))
    {
        result.push_back(line);
    }
    return result;
}