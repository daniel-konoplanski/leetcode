#include <stack>
#include <vector>

class Solution
{
private:
    struct Measurement
    {
        int value;
        int day;
    };

public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures)
    {
        std::vector<int> result(temperatures.size(), 0);
        std::stack<Measurement> tempStack{};

        for (int day{}; day < temperatures.size(); ++day)
        {
            while (!tempStack.empty() && temperatures[day] > tempStack.top().value)
            {
                int pastDay     = tempStack.top().day;
                result[pastDay] = day - pastDay;
                tempStack.pop();
            }

            tempStack.push({temperatures[day], day});
        }

        return result;
    }
};

auto main() -> int
{
    std::vector<int> temps{73,74,75,71,69,72,76,73};
    auto result = Solution().dailyTemperatures(temps);
}
