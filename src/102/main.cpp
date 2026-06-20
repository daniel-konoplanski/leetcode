#include <algorithm>
#include <queue>
#include <vector>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode()
        : val(0)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x)
        , left(left)
        , right(right)
    {
    }
};

class Solution
{
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root)
    {
        if (!root) return {};

        std::vector<std::vector<int>> results{};
        std::queue<TreeNode*> nodes{};
        nodes.push(root);

        while (!nodes.empty())
        {
            auto size = nodes.size();
            std::vector<int> row;
            row.reserve(size);

            while (size--)
            {
                auto node = nodes.front();
                nodes.pop();
                if (node->left) nodes.push(node->left);
                if (node->right) nodes.push(node->right);

                row.push_back(node->val);
            }

            results.push_back(std::move(row));
        }

        return results;
    }
};

auto main() -> int
{
}
