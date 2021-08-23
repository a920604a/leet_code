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
    void inorder(TreeNode *root, vector<int> &ret)
    {
        if (root)
        {
            inorder(root->left, ret);
            ret.push_back(root->val);
            inorder(root->right, ret);
        }
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        // option 1 recursive O(n) space
        vector<int> ret;
        inorder(root, ret);
        return ret;

        // option 2 stack+iterative O(n) space
        vector<int> ret;
        stack<TreeNode *> sta;
        addLeftToStack(sta, root);

        while (!sta.empty())
        {
            TreeNode *cur = sta.top();
            sta.pop();
            ret.push_back(cur->val);
            addLeftToStack(sta, cur->right);
        }

        return ret;

        // option 3 Morris Traversal O(1) space
        // 所有原本為空的右子節點指向中序遍歷順序後的那個節點

        // step 1 如果當前節點的左孩子為空，則輸出當前節點並將右孩子當作當前節點
        // step 2 如果當前左孩子不為空，在當前節點的左子樹中找到當前節點在中序遍歷下的前驅節點
        //      a) 如果前驅節點的右孩子為空，將他的右孩子設為當前節點。當前節點更新為當前節點的左子樹
        //      b) 如果前驅節點的右孩子為當前節點，將他的右孩子設為空(恢復樹的形狀)。輸出當前節點。當前節點更新為當前節點的右孩子
        // stpe 3 重複step 1 step 2 直到當前節點為空。

        vector<int> vec;
        TreeNode *cur = root, *prev = nullptr;

        while (cur)
        {
            if (cur->left == nullptr)
            { //1
                vec.push_back(cur->val);
                cur = cur->right;
            }
            else
            {
                // find 前驅點
                prev = cur->left;
                while (prev->right != nullptr && prev->right != cur)
                {
                    prev = prev->right;
                }

                if (prev->right == nullptr)
                { // 2.a
                    prev->right = cur;
                    cur = cur->left;
                }
                else
                { /// 2.b
                    prev->right = nullptr;
                    vec.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        return vec;
    }
    void addLeftToStack(stack<TreeNode *> &sta, TreeNode *root)
    {
        while (root != nullptr)
        {
            sta.push(root);
            root = root->left;
        }
    }
};