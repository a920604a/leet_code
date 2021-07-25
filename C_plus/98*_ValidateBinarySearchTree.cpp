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

        if (root == nullptr)
            return true;
        // V
        if (!root->left && root->val <= min)
            return false;
        if (!root->right && root->val >= max)
            return false;

        // L R
        return isValidBST(root->left, min, root->val) && isValidBST(root->right, root->val, max);
    }

    bool isValidBST(TreeNode *root, TreeNode *min, TreeNode *max)
    {
        if (root == nullptr)
            return true;
        // V
        if (min && root->val <= min->val)
            return false;
        if (max && root->val >= max->val)
            return false;

        return isValidBST(root->left, min, root) && isValidBST(root->right, root, max);
    }

    bool isValidBST(TreeNode *root)
    {

        // option 1 O(nlogn)  time and O(n) space

        // preorder traverse and insert to vector and then check vector it is ascend
        //         vector<int> vec;
        //         traverse(root, vec);

        //         for(int i=1;i<vec.size(); ++i){
        //             if(vec[i]<= vec[i-1]) return false;
        //         }
        //         return true;

        // option 2 Integer version or TreeNode version
        // return isValidBST(root, LONG_MIN, LONG_MAX);
        return isValidBST(root, nullptr, nullptr);
    }
};