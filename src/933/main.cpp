#include <print>
#include <queue>

class RecentCounter
{
public:
    RecentCounter()
    {
    }

    int ping(int t)
    {
        queue.emplace(t);
        removeOverduePings();

        std::print("size: {}\n", queue.size());
        return queue.size();
    }

private:
    void removeOverduePings()
    {
        constexpr int time{3000};

        auto backElement  = queue.back();
        auto frontElement = queue.front();

        while (backElement - frontElement > 3000)
        {
            std::print("frontElement: {}\n", frontElement);
            std::print("backElement: {}\n", backElement);
            std::print("difference: {}\n", backElement - frontElement);

            queue.pop();
            backElement  = queue.back();
            frontElement = queue.front();
        }
    }

private:
    std::queue<int> queue{};
};

int main()
{
    RecentCounter counter{};

// [[],[642],[1849],[4921],[5936],[5957]]

    counter.ping(642);
    counter.ping(1849);
    counter.ping(4921);
    counter.ping(5936);
    counter.ping(5957);
}