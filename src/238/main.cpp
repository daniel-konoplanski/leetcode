#include <cstdint>
#include <numeric>
#include <ranges>
#include <vector>

class Solution
{
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums)
    {
        const auto n = nums.size();

        std::vector<int32_t> prefixProduct(n);
        std::exclusive_scan(nums.begin(), nums.end(), prefixProduct.begin(), 1, std::multiplies{});

        std::vector<int32_t> suffixProduct(n);
        std::exclusive_scan(nums.rbegin(), nums.rend(), suffixProduct.rbegin(), 1, std::multiplies{});

        return std::views::zip_transform(std::multiplies{}, prefixProduct, suffixProduct)
               | std::ranges::to<std::vector>();
    }
};

auto main() -> int
{
    std::vector<int32_t> nums{ 1, 2, 3, 4 };
    Solution().productExceptSelf(nums);
}
