#include <vector>
#include <print>

class Solution
{
public:
    int largestAltitude(std::vector<int>& gains)
    {
        int highest{};
        int altitude{};

        for (auto gain : gains)
        {
            altitude += gain;
            if (altitude > highest) highest = altitude;
        }

        return highest;
    }
};

int main()
{
    std::vector<int> gain{-5,1,5,0,-7};
    auto result = Solution().largestAltitude(gain);

    std::print("result: {}", result);
}