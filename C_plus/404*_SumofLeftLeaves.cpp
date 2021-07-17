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
    // void findLeftLeave(TreeNode *root, vector<int> & ret){
    void findLeftLeave(TreeNode *root, int &ans)
    {
        if (root == nullptr)
            return;
        if (root->left && root->left->left == nullptr && root->left->right == nullptr)
        {
            // ret.push_back(root->left->val);
            ans += root->left->val;
        }
        findLeftLeave(root->left, ans);
        findLeftLeave(root->right, ans);
    }
    int sumOfLeftLeaves(TreeNode *root)
    {
        // option 1 維護一個變量或vector 紀錄left leaves 的總和或是所有left leaves，inorder
        if (root->left == nullptr && root->right == nullptr)
            return 0;
        vector<int> ret;
        int ans = 0;
        findLeftLeave(root, ans);

        // for(auto r:ret) ans+=r;
        return ans;
    }
};