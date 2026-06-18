#include <print>
#include <unordered_map>
#include <vector>

class Solution
{
private:
    struct Nums
    {
        bool inNums1_{};
        bool inNums2_{};
    };

public:
    std::vector<std::vector<int>> findDifference(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        std::unordered_map<int, Nums> map{};

        for (auto num : nums1)
        {
            map[num] = Nums{.inNums1_ = true};
        }

        for (auto num : nums2)
        {
            auto elementIter = map.find(num);

            if (elementIter == map.end()) map[num] = Nums{.inNums2_ = true};
            else elementIter->second.inNums2_ = true;
        }

        std::vector<int> result1{}, result2{};
        result1.reserve(2000), result2.reserve(2000);

        for (const auto& pair : map)
        {
            const auto& [key, nums] = pair;

            if (nums.inNums1_ && !nums.inNums2_) result1.push_back(key);
            else if (!nums.inNums1_ && nums.inNums2_) result2.push_back(key);
        }

        return {std::move(result1), std::move(result2)};
    }
};

int main()
{
    std::vector<int> nums1 = {1,2,3};
    std::vector<int> nums2 = {2,4,6};

    Solution().findDifference(nums1, nums2);
}
