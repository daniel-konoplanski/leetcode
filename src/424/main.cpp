#include <print>
#include <string>
#include <unordered_map>

class Solution
{
public:
    int characterReplacement(std::string s, int k)
    {
        auto map = std::unordered_map<char, int>();
        int pa{0}, result{0}, max_freq{0};

        for (int pb{0}; pb < s.size(); ++pb)
        {
            max_freq = std::max(max_freq, ++map[s[pb]]);

            int window_size = pb - pa + 1;
            bool is_k_exceeded = (window_size - max_freq) > k;

            if (is_k_exceeded)
            {
                --map[s[pa]];
                ++pa;
            }
        }

        return s.size() - pa;
    }
};

auto main() -> int
{
    std::string s = "AABABBA";
    auto result = Solution().characterReplacement(s, 1);

    std::println("result: {}", result);
}
