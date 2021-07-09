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
    void traverse(TreeNode *root, vector<int> &ret)
    {
        if (!root)
            return;

        traverse(root->left, ret);
        ret.push_back(root->val);
        traverse(root->right, ret);
    }

    bool isValidBST(TreeNode *root, long min, long max)
    {
        if (!root)
            return true;

        if (root->val <= min || root->val >= max)
            return false;

        return isValidBST(root->left, min, root->val) && isValidBST(root->right, root->val, max);
    }
    bool isValidBST(TreeNode *root)
    {
        // option 1 O(nlogn)  time and O(n) space
        // inorder traverse must be ascend sequence
        //         vector<int>  ret;
        //         traverse(root, ret);

        //         // check wheather is ascend

        //         for(int i= 1;i<ret.size();++i){
        //             if(ret[i]<= ret[i-1]) return false;
        //         }
        //         return true;

        // option 2
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }
};