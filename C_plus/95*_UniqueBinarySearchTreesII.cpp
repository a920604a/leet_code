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
    vector<TreeNode *> build(int lo, int hi)
    {
        //定義：建造 閉區間 [lo, hi] 組成的BST
        // base case
        if (lo > hi)
        {
            return {nullptr};
        }

        vector<TreeNode *> ret;

        // 1. 窮舉root 節點的所有可能
        for (int i = lo; i <= hi; ++i)
        {

            // 2. 遞回構造出左右子樹的所有合法BST
            vector<TreeNode *> leftTree = build(lo, i - 1);
            vector<TreeNode *> rightTree = build(i + 1, hi);

            // 3. 給root節點窮舉所有左右子樹的組合
            for (TreeNode *left : leftTree)
            {
                for (TreeNode *right : rightTree)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    ret.push_back(root);
                }
            }
        }
        return ret;
    }
    vector<TreeNode *> build(int lo, int hi, vector<vector<vector<TreeNode *> > > &memo)
    {
        if (lo > hi)
            return {nullptr};

        if (!memo[lo - 1][hi - 1].empty())
            return memo[lo - 1][hi - 1];

        vector<TreeNode *> ret;

        for (int i = lo; i <= hi; ++i)
        {
            vector<TreeNode *> leftTree = build(lo, i - 1, memo);
            vector<TreeNode *> rightTree = build(i + 1, hi, memo);

            for (TreeNode *left : leftTree)
            {
                for (TreeNode *right : rightTree)
                {
                    TreeNode *node = new TreeNode(i);
                    node->left = left;
                    node->right = right;
                    ret.push_back(node);
                }
            }
        }
        return memo[lo - 1][hi - 1] = ret;
    }
    vector<TreeNode *> generateTrees(int n)
    {
        // option 1
        // if(n == 0) return {};
        // return build(1, n);

        // option 1.1 memo pattern
        vector<vector<vector<TreeNode *> > > memo(n, vector<vector<TreeNode *> >(n));
        return build(1, n, memo);
    }
};