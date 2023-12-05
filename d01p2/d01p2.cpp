#include "../common.h"

#include <regex>

static const char* kInputFileName = "input.txt";

static const char* kDigits = "0123456789";

static const std::unordered_map<std::string, int> kValues = {
    { "one", 1 },
    { "two", 2 },
    { "three", 3 },
    { "four", 4 },
    { "five", 5 },
    { "six", 6 },
    { "seven", 7 },
    { "eight", 8 },
    { "nine", 9 },
    { "zero", 0 },
    { "1", 1 },
    { "2", 2 },
    { "3", 3 },
    { "4", 4 },
    { "5", 5 },
    { "6", 6 },
    { "7", 7 },
    { "8", 8 },
    { "9", 9 },
    { "0", 0 },
};

int DigitForString(const std::string& s)
{
    auto it = kValues.find(s);
    return (it != kValues.end()) ? it->second : 0;
}

int DigitForLine(const std::string& s)
{
    // 86vbnpsixthreetwonevng -> 8, two -> 8, 2, should be 8, 1
    static std::regex regex_first { R"R(.*?(one|two|three|four|five|six|seven|eight|nine|zero|\d).*)R" };
    static std::regex regex_last { R"R(.*(one|two|three|four|five|six|seven|eight|nine|zero|\d).*?)R" };

    std::string first, last;
    std::smatch match;
    if (std::regex_search(s, match, regex_first))
    {
        first = match[1];
    }
    if (std::regex_search(s, match, regex_last))
    {
        last = match[1];
    }

    int d1 = DigitForString(first);
    int d2 = DigitForString(last);

    std::cout <<
        s << " -> " <<
        first << ", " << last << " -> " <<
        d1 << ", " << d2 <<
        std::endl;


    return d1 * 10 + d2;
}

int main()
{
    auto lines = ReadLines(kInputFileName);

    int sum = 0;
    for (const auto& line : lines)
    {
        sum += DigitForLine(line);
    }

    std::cout << sum << std::endl;

    return 0;
}