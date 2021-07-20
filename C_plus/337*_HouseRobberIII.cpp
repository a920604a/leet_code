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
class Solution {
private:
    unordered_map<TreeNode*,int> memo;
public:
    int rob(TreeNode* root) {
        if(root==nullptr) return 0;
        
        if(memo[root]) return memo[root];
        
        // 搶
        int do_it = root->val;
        if(root->left!=nullptr) do_it += rob(root->left->left) +rob(root->left->right);
        if(root->right !=nullptr) do_it += rob(root->right->left) + rob(root->right->right);
        // 不搶
        int not_do =  rob(root->left) + rob(root->right);
        int res = max(not_do, do_it);
        memo[root] = res;
        return res;
        
        
    }
};