/*
 * @Author: yuan
 * @Date: 2021-07-17 09:21:24
 * @LastEditTime: 2021-07-17 09:21:24
 * @FilePath: /leet_code/C_plus/872_Leaf-SimilarTrees.cpp
 */
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
    void getLeaves(TreeNode *root, vector<int> &leaves)
    {
        // preorder traverse
        if (!root)
            return;
        if (root->left == nullptr && root->right == nullptr)
            leaves.push_back(root->val);

        getLeaves(root->left, leaves);
        getLeaves(root->right, leaves);
    }
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        // option 1 vector
        //         vector<int> leaves1;
        //         vector<int> leaves2;
        //         getLeaves(root1, leaves1);
        //         getLeaves(root2, leaves2);

        //         return leaves1 == leaves2;

        // option 1.1 instead of vector, string
        string leaves1 = "";
        string leaves2 = "";
        getLeaves(root1, leaves1);
        getLeaves(root2, leaves2);

        return leaves1 == leaves2;
    }

    void getLeaves(TreeNode *root, string &leaves)
    {
        // preorder traverse
        if (!root)
            return;
        if (root->left == nullptr && root->right == nullptr)
            leaves.append(to_string(root->val) + "-");

        getLeaves(root->left, leaves);
        getLeaves(root->right, leaves);
    }
};