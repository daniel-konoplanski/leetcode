#include <algorithm>
#include <print>
#include <string>
#include <unordered_map>

class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        int pa{0}, pb{0}, result{0};

        auto map = std::unordered_map<char, int>();

        while (pb < s.size())
        {
            char character = s[pb];

            if (map.contains(character))
            {
                pa = std::max(pa, map[character] + 1);
            }

            map[character] = pb;

            int current_score = pb - pa + 1;
            result = std::max(result, current_score);

            ++pb;
        }

        return result;
    }
};

auto main() -> int
{
    std::string s = "abba";
    auto result = Solution().lengthOfLongestSubstring(s);

    std::println("{}", result);
}