#include <algorithm>
#include <string>
#include <iostream>

class Solution
{
public:
    std::string mergeAlternately(std::string word1, std::string word2)
    {
        std::string result{};

        auto max_size = std::max(word1.size(), word2.size());
        auto min_size = std::min(word1.size(), word2.size());

        const auto& longer_word = (max_size == word1.size()) ? word1 : word2;

        for (int i{0}; i < min_size; ++i)
        {
            result += word1[i];
            result += word2[i];
        }

        result += longer_word.substr(min_size, max_size - 1);

        return result;
    }
};

int main()
{
    std::string word1 = "ab", word2 = "pqrs";
    std::cout << Solution().mergeAlternately(word1, word2) << "\n";
}
