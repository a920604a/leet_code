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
private:
    int maxSum = 0;
    struct str
    {
        bool isBST;
        int minVal;
        int maxVal;
        int sum;
    };

public:
    str traverse(TreeNode *root)
    {
        if (!root)
        {
            return {true, INT_MAX, INT_MIN, 0};
        }

        // 遞迴計算左右子樹
        str left = traverse(root->left);
        str right = traverse(root->right);

        // postorder
        str ret;
        if (left.isBST == true && right.isBST == true && root->val > left.maxVal && root->val < right.minVal)
        {

            ret.isBST = true;
            ret.minVal = min(left.minVal, root->val);
            ret.maxVal = max(right.maxVal, root->val);

            ret.sum = left.sum + right.sum + root->val;

            maxSum = max(maxSum, ret.sum);
        }
        else
        {
            ret.isBST = false;
        }
        return ret;
    }
    int maxSumBST(TreeNode *root)
    {
        // 1. 左右子樹是否為BST，如果其一不合法，那我本身也不合法
        // 2. 如果左右子樹都合法，還得看看加上自己是否合法，所以得找左子樹最大值和右子樹最小值
        // 3. 左右子樹節點值之和

        traverse(root);
        return maxSum;
    }
};