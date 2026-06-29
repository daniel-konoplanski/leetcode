#include <array>
#include <vector>

class Solution
{
private:
    struct Position
    {
        int x{};
        int y{};
    };

    inline int isInBounds(std::vector<std::vector<char>>& grid, const Position& pos)
    {
        if (pos.x >= 0 and pos.y >= 0 and pos.x < grid.size() and pos.y < grid[pos.x].size())
        {
            return true;
        }

        return false;
    }

    void dfsZeroConnectedOnes(std::vector<std::vector<char>>& grid, Position pos)
    {
        if (not isInBounds(grid, pos)) return;
        if (grid[pos.x][pos.y] == '0') return;

        grid[pos.x][pos.y] = '0';

        std::array<Position, 4> neighbours{ Position{ pos.x - 1, pos.y },
                                            Position{ pos.x + 1, pos.y },
                                            Position{ pos.x, pos.y - 1 },
                                            Position{ pos.x, pos.y + 1 } };

        for (const auto& pos : neighbours)
        {
            dfsZeroConnectedOnes(grid, pos);
        }
    }

public:
    int numIslands(std::vector<std::vector<char>>& grid)
    {
        int result{};

        for (int i{ 0 }; i < grid.size(); ++i)
        {
            for (int j{ 0 }; j < grid[i].size(); ++j)
            {
                auto element = grid[i][j];

                if (element == '1')
                {
                    ++result;
                    dfsZeroConnectedOnes(grid, { i, j });
                }
            }
        }

        return result;
    }
};

auto main() -> int
{
}
