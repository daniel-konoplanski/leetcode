#include <cstdint>
#include <limits>
#include <numeric>
#include <utility>
#include <vector>
#include <iostream>

class Solution
{
public:
    double findMaxAverage(std::vector<int>& nums, int k)
    {
        double sum = std::accumulate(nums.begin(), nums.begin() + k, 0);
        double result = sum / k;

        for (int start{0}, end{k - 1}; end < nums.size() - 1; ++start, ++end)
        {
            std::cout << "start: " << start << "\n";
            std::cout << "end: " << end << "\n";

            sum -= nums[start];
            sum += nums[end + 1];

            double tmpResult = sum / k;

            if (tmpResult > result) result = tmpResult;
        }

        return result;
    }
};

int main()
{
    std::vector<int32_t> value{1,12,-5,-6,50,3};

    auto result = Solution().findMaxAverage(value, 4);

    std::cout << "result " << result << "\n";
}
