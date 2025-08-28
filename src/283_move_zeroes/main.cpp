#include <cstdint>
#include <utility>
#include <vector>
#include <iostream>

template <typename T>
void print(const std::vector<T>& vec)
{
    for (const auto& x : vec)
    {
        std::cout << x << " ";
    }

    std::cout << "\n";
}

class Solution
{
public:
    void moveZeroes(std::vector<int>& nums)
    {
        uint_fast16_t a{0}, b{0};

        /*
         *  a checks if its on a zero
         *      yes: b searches for non zero
         *      no: a gets incremented
         */

        while (a != nums.size() && b != nums.size())
        {
            if (b < a) b = a;

            if (nums[a] == 0)
            {
                if (nums[b] != 0) std::swap(nums[a], nums[b]);
                else ++b;
                continue;
            }

            ++a;
        }
    }
};



int main()
{
    std::vector<int> input{0,1,0,3,12};

    print(input);

    Solution().moveZeroes(input);

    print(input);
}