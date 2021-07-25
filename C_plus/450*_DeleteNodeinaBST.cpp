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
    TreeNode *getMin(TreeNode *node)
    {
        while (node->left)
            node = node->left;
        return node;
    }
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == nullptr)
            return nullptr;
        //先「找」再「改」
        if (root->val == key)
        {
            //找到了，進行刪除
            // 情況一，刪除點剛好是葉子，刪除則完事
            // 情況二，刪除點有一個孩子，要讓其孩子接替自己位置
            // 情況三，刪除點有兩個孩子，要找左子樹最大節點或是右子樹最小節點來接替自己位置
            // 這兩個 if 把情況 1 和 2 都正確處理了
            if (root->left == nullptr)
                return root->right;
            if (root->right == nullptr)
                return root->left;

            // 處理情況三
            // 找右子樹最小節點
            TreeNode *minNode = getMin(root->right);
            // 替代策略
            root->val = minNode->val;
            root->right = deleteNode(root->right, minNode->val);
        }
        else if (root->val > key)
        {
            // 往左子樹找
            root->left = deleteNode(root->left, key);
        }
        else if (root->val < key)
        {
            // 往右子樹找
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};