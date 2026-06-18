#include <algorithm>
#include <cstddef>
#include <iterator>
#include <print>
#include <string>
#include <stack>

class Solution
{
public:
    std::string removeStars(std::string s)
    {
        std::stack<char> stack{};
        std::string      result{};

        result.reserve(s.size());

        int skip_counter{0};

        for (int i{static_cast<int>(s.size()) - 1}; i >= 0; --i)
        {
            char character = s[i];

            if (character == '*')
                ++skip_counter;
            else if (skip_counter == 0)
                stack.push(character);
            else --skip_counter;
        }

        while (!stack.empty())
        {
            result += stack.top();
            stack.pop();
        }

        return result;
    }
};


int main()
{
    auto x = Solution().removeStars("dupa");
}