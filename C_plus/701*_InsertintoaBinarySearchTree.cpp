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
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        // option 1 recursive without adjust
        //         // 增刪查改 涉及到改函數就要返回 TreeNode 類型
        //         // base case 找到空位置
        //         if(!root) return new TreeNode(val);

        //         // 假設不會插入重複的元素
        //         // if(root->val == val)

        //         if(root->val < val) root->right = insertIntoBST(root->right, val);
        //         if(root->val > val) root->left = insertIntoBST(root->left, val);
        //         return root;

        // option 2 iterative
        if (!root)
            return new TreeNode(val);
        TreeNode *cur = root;
        while (true)
        {
            if (cur->val > val)
            { // 往左子樹搜尋
                if (!cur->left)
                {
                    cur->left = new TreeNode(val);
                    break;
                }
                cur = cur->left;
            }
            else if (cur->val < val)
            { // 往右子樹搜尋
                if (!cur->right)
                {
                    cur->right = new TreeNode(val);
                    break;
                }
                cur = cur->right;
            }
        }
        return root;
    }
};