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
        if (root)
        {

            if (root->left)
                traverse(root->left, ret); // L
            ret.push_back(root->val);      // V
            if (root->right)
                traverse(root->right, ret); // R
        }
    }
    int kthSmallest(TreeNode *root, int k)
    {
        // option 1
        // use vector to save each node value ,and sort the vector. wheather any tree traverse
        // if inorder traverse , get sorted vector
        // vector<int> ret;
        // traverse(root, ret);
        // sort(ret.begin(), ret.end()); // if inorder traverse , get sorted vector
        // return ret[k-1];

        // option 2
        // use stack + inorder non-recurrent
        int cnt = 0;
        stack<TreeNode *> s;
        TreeNode *p = root;
        while (p || !s.empty())
        {
            while (p)
            { // find the smallest node
                s.push(p);
                p = p->left;
            }
            p = s.top();
            s.pop();
            cnt++;
            if (cnt == k)
                return p->val;
            p = p->right;
        }
        return 0;
    }
};