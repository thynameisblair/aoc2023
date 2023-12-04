#include "../common.h"

static const char* kInputFileName = "input.txt";

static const char* kDigits = "0123456789";

int DigitForLine(const std::string& s)
{
    size_t i1 = s.find_first_of(kDigits);
    size_t i2 = s.find_last_of(kDigits);

    int d1 = s[i1] - '0';
    int d2 = s[i2] - '0';

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