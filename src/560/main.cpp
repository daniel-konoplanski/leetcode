#include <print>
#include <vector>
#include <ranges>

class Solution
{
public:
    int subarraySum(std::vector<int>& nums, int k)
    {
        int result{};

        for (int i{0}; i < nums.size(); ++i)
        {
            int sum = nums[i];

            if (sum == k) ++result;

            for (int num : nums | std::views::drop(i + 1))
            {
                sum += num;
                if (sum == k) ++result;
            }
        }

        return result;
    }
};

int main()
{
    auto nums = std::vector<int>{28,54,7,-70,22,65,-6};
    auto result = Solution().subarraySum(nums, 100);

    std::println("{}", result);
}
