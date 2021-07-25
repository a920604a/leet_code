/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums, int lo, int hi)
    {
        // preorder
        // 找到最大值，並記下index
        if (lo > hi)
            return nullptr;
        int index = -1, maxVal = INT_MIN;
        for (int i = lo; i <= hi; ++i)
        {
            if (nums[i] > maxVal)
            {
                maxVal = nums[i];
                index = i;
            }
        }
        TreeNode *root = new TreeNode(nums[index]);
        root->left = constructMaximumBinaryTree(nums, lo, index - 1);
        root->right = constructMaximumBinaryTree(nums, index + 1, hi);
        return root;
    }
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        if (nums.empty())
            return nullptr;
        // overload
        return constructMaximumBinaryTree(nums, 0, nums.size() - 1);
    }
};