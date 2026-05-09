#include <print>
#include <span>
#include <vector>

class Solution
{
public:
    int search(std::vector<int>& nums, int target)
    {
        return search_recursive(nums, target, 0);
    }

    auto search_recursive(std::span<int> nums, int target, int addition) -> int
    {
        if (nums.empty()) return -1;

        int m = nums.size() / 2;

        if (nums[m] == target)
        {
            return addition + m;
        }
        else if (target < nums[m])
        {
            if (nums.front() <= target && target < nums[m])
                return search_recursive(nums.subspan(0, m), target, addition);
            else
                return search_recursive(nums.subspan(m + 1), target, addition + m + 1);
        }
        else
        {
            if (nums[m] < target && target <= nums.back())
                return search_recursive(nums.subspan(m + 1), target, addition + m + 1);
            else
                return search_recursive(nums.subspan(0, m), target, addition);
        }
    }
};

auto main() -> int
{
    std::vector<int> nums{ 3, 1 };
    auto result = Solution().search(nums, 3);

    std::println("result: {}", result);
}
