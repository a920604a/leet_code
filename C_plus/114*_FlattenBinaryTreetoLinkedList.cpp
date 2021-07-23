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
    void flatten(TreeNode *root)
    {
        // option 1  stack
        // 1. new new root on top of original root andnewRoot->right = root
        // if(!root) return;
        // TreeNode *ret = new TreeNode(-1), *pre = ret;
        // stack<TreeNode *> sta;
        // sta.push(root);
        // while(!sta.empty()){
        //     TreeNode *node = sta.top();
        //     sta.pop();
        //     pre->right = node;
        //     pre->left = nullptr;
        //     if(node->right) sta.push(node->right);
        //     if(node->left) sta.push(node->left);
        //     pre= node;
        // }

        // option 1.1 improved option 1 without stack
        // while(root){
        //     if (root -> left) {
        //         TreeNode* pre = root -> left;
        //         while (pre -> right) {
        //             pre = pre -> right;
        //         }
        //         pre -> right = root -> right;
        //         root -> right = root -> left;
        //         root -> left = nullptr;
        //     }
        //     root = root->right;
        // }

        // option 2 recursive

        // while (root) {
        //     if (root -> left) {
        //         flatten(root -> left);
        //         TreeNode* right = root -> right;
        //         root -> right = root -> left;
        //         root -> left = NULL;
        //         while (root -> right) {
        //             root = root -> right;
        //         }
        //         root -> right = right;
        //     }
        //     root = root -> right;
        // }

        // option 2.1 version 2
        if (root == nullptr)
            return;

        flatten(root->left);
        flatten(root->right);

        /**** 后序遍历位置 ****/
        // step1. 左右子樹已經被拉成一條linked list
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        // step2. 將左子樹作為右子樹
        root->left = nullptr;
        root->right = left;

        // step3. 將原先的右子樹揪到當前右子樹的末端
        TreeNode *p = root;
        while (p->right != nullptr)
            p = p->right;
        p->right = right;
    }
};