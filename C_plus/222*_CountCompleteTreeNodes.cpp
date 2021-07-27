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
    int countNodes(TreeNode *root)
    {
        // option 1 O(n)
        // if(!root) return 0;
        // return 1 + countNodes(root->left) + countNodes(root->right);

        // option 2 O(logn * logn) , worse case O(N*logN)
        // 求高度
        if (!root)
            return 0;

        TreeNode *left = root, *right = root;
        int hl = 0, hr = 0;
        while (left)
        { // O(logN)
            left = left->left;
            hl++;
        }
        while (right)
        { // O(logN)
            right = right->right;
            hr++;
        }

        // 代表此Complete binary tree 同時也是 Full binary tree
        if (hr == hl)
            return pow(2, hl) - 1;
        // 如果左右高度不一樣，則按照普通二元樹的計算高度方式
        return 1 + countNodes(root->left) + countNodes(root->right); // O(N)
    }
};