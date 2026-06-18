#include <unordered_map>
#include <utility>
#include <vector>
#include <queue>

class Solution
{
private:
    using Pair = std::pair<int, int>;
    using MaxHeap = std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>>;

public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k)
    {
        // O(n)
        std::unordered_map<int, int> map;
        for (int n : nums) map[n]++;

        // O(n logn)
        MaxHeap heap;
        for (const auto& [num, count] : map)
        {
            heap.push({count, num});
            if (heap.size() > k) heap.pop();
        }

        std::vector<int> result;
        result.reserve(k);

        // O(n)
        while (!heap.empty())
        {
            result.push_back(heap.top().second);
            heap.pop();
        }

        return result;
    }
};

auto main() -> int
{
}
