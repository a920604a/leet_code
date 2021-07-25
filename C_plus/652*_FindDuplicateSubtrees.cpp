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
    unordered_map<string, int> memo;
    vector<TreeNode *> res;

public:
    string traverse(TreeNode *root)
    {
        // postorder，因為必須要先知道左右子樹長怎樣，再加上根節點去構建
        // 用字符串列 "," 將二元樹序列化
        // 利用hash外部資料結構，將自己子樹序列化結果存進去
        if (!root)
            return "#";

        string left = traverse(root->left);
        string right = traverse(root->right);

        string key = left + "," + right + "," + to_string(root->val);
        // 如果有重複的話，只會存一次
        if (memo.count(key) && memo[key] == 1)
            res.push_back(root);

        memo[key]++;
        return key;
    }
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {

        traverse(root);
        return res;
    }
};