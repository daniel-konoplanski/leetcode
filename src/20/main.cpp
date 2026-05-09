#include <print>
#include <span>
#include <stack>
#include <string>
#include <unordered_map>

class Solution
{
public:
    bool isValid(std::string s)
    {
        if (s.size() % 2 != 0) return false;

        std::stack<char> stack;

        for (char c : s)
        {
            if (isOpening(c))
            {
                stack.push(c);
                continue;
            }

            if (stack.empty() || pMapping.at(stack.top()) != c) return false;
            stack.pop();
        }

        return stack.empty();
    }

private:
    inline static const std::unordered_map<char, char> pMapping{ { '(', ')' }, { '[', ']' }, { '{', '}' } };

    inline static bool isOpening(char c)
    {
        return pMapping.contains(c);
    }
};

auto main() -> int
{
    std::string exmaple = "((";
    auto result         = Solution().isValid(exmaple);

    std::println("{}", result);
}
