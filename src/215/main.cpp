#include <functional>
#include <queue>

class Solution
{
private:
    using MinHeap = std::priority_queue<int, std::vector<int>, std::greater<int>>;

public:
    int findKthLargest(std::vector<int>& nums, int k)
    {
        MinHeap heap;

        for (int n : nums)
        {
            heap.push(n);
            if (heap.size() > k) heap.pop();
        }

        return heap.top();
    }
};

auto main() -> int
{
}
