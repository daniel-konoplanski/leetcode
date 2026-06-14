#include <print>
#include <ranges>
#include <vector>

class Solution
{
public:
    int findDuplicate(std::vector<int>& nums)
    {
        auto getXorProduct = [](const auto& range) {
            int result{};

            for (int i : range)
            {
                result ^= i;
            }

            return result;
        };

        int xorNums = getXorProduct(nums);
        int xorN = getXorProduct(std::views::iota(1, static_cast<int>(nums.size())));

        return xorN ^ xorNums;
    }
};

auto main() -> int
{
    std::vector vec{ 1, 3, 4, 2, 2 };
    std::println("{}", Solution().findDuplicate(vec));
}
