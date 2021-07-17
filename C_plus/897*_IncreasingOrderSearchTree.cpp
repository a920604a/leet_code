/*
 * @Author: yuan
 * @Date: 2021-07-17 09:49:09
 * @LastEditTime: 2021-07-17 09:49:09
 * @FilePath: /leet_code/C_plus/897*_IncreasingOrderSearchTree.cpp
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
    void inorder(TreeNode *root, vector<int> &vec)
    {
        if (!root)
            return;

        inorder(root->left, vec);
        vec.push_back(root->val);
        inorder(root->right, vec);
    }
    TreeNode *increasingBST(TreeNode *root)
    {
        // option 1 直覺用vector紀錄所有點排序後
        //         vector<int> vec;
        //         inorder(root, vec);

        //         TreeNode *cur = new TreeNode(vec[0]), *ret = cur;
        //         for(int i=1;i<vec.size();++i){
        //             cur->right = new TreeNode(vec[i]);
        //             cur = cur->right;
        //         }
        //         return ret;

        // option 2
        TreeNode *ans;
        TreeNode *temp = new TreeNode();
        ans = temp;
        inorder(temp, root);
        return ans->right;
    }
    void inorder(TreeNode *&ans, TreeNode *root)
    {
        if (!root)
            return;
        inorder(ans, root->left);
        ans->left = nullptr;
        ans->right = new TreeNode(root->val);
        ans = ans->right;
        inorder(ans, root->right);
    }
};