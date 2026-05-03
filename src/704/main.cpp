#include <print>
#include <span>
#include <vector>

class Solution
{
public:
    int search(std::vector<int>& nums, int target)
    {
        return search_recursive(std::span<int>(nums), target, 0);
    }

private:
    int search_recursive(std::span<int> nums, int target, int addition)
    {
        if (nums.empty()) return -1;

        int m = nums.size() / 2;

        if (nums[m] == target)
        {
            return addition + m;
        }
        else if (target > nums[m])
        {
            return search_recursive(nums.subspan(m + 1), target, addition + m + 1);
        }
        else
        {
            return search_recursive(nums.subspan(0, m), target, addition);
        }
    }
};

auto main() -> int
{
    auto nums   = std::vector<int>{ -1, 0, 3, 5, 9, 12 };
    auto nums2  = std::vector<int>{ 2, 5 };
    auto result = Solution().search(nums2, 2);

    std::println("result: {}", result);
}
