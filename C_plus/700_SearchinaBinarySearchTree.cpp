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
    TreeNode *ans;

public:
    void traverse(TreeNode *root, int val)
    {
        if (!root)
            return;

        traverse(root->left, val);

        if (root->val == val)
        {
            ans = root;
            return;
        }

        traverse(root->right, val);
    }

    TreeNode *searchBST(TreeNode *root, int val)
    {

        // option 1 brute force whether it is BST
        // ans = new TreeNode(-1);
        // traverse(root, val);
        // if(ans->val == -1) return nullptr;
        // return ans;

        // option 1.1 imroved using BST
        if (!root)
            return nullptr;
        // V 找到目標
        if (root->val == val)
            return root;
        // L
        else if (root->val < val)
            return searchBST(root->right, val);
        // R
        else
            return searchBST(root->left, val);

        // option 2  meaningless iterative  + stack support
        // if(!root) return nullptr;
        // stack<TreeNode *> sta;
        // TreeNode *q = root;
        // while(q || !sta.empty()){
        //     // L
        //     while(q){
        //         sta.push(q);
        //         q = q->left;
        //     }
        //     q = sta.top();
        //     sta.pop();
        //     // V 找到目標
        //     if(q->val == val) return q;
        //     // R
        //     q=q->right;
        // }
        // return nullptr;
    }
};