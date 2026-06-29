#include <algorithm>
#include <limits>
#include <vector>
#include <queue>

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
    bool isValidBST(TreeNode* root, int64_t min = std::numeric_limits<int64_t>::min(), int64_t max = std::numeric_limits<int64_t>::max())
    {
        if (!root) return true;
        if (root->val <= min || root->val >= max) return false;
        return isValidBST(root->left, min, root->val) && isValidBST(root->right, root->val, max);
    }
};

auto main() -> int
{
    TreeNode* root = new TreeNode(2, new TreeNode(1), new TreeNode(3));
    Solution solution;
    bool result = solution.isValidBST(root);
}
