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
        // option 1 iterative with stack support and new treenode
        //         if(!root) return;
        //         TreeNode *ret = new TreeNode(-1), *pre = ret;
        //         stack<TreeNode *> sta;
        //         sta.push(root);
        //         while(!sta.empty()){
        //             TreeNode *node = sta.top();
        //             sta.pop();
        //             pre->right = node;
        //             pre->left = nullptr;
        //             // 因為stack先進後出的性質，會後處理right
        //             if(node->right) sta.push(node->right);
        //             if(node->left) sta.push(node->left);
        //             pre = node;

        //         }
        //         root = ret->right;

        // option 1 version 2  iterative without stack
        // while(root){
        //     if(root->left){
        //         TreeNode * pre = root->left;
        //         while(pre->right) pre = pre->right;
        //         pre->right = root->right;
        //         root->right = root->left;
        //         root->left = nullptr;
        //     }
        //     root = root->right;
        // }

        // option 2 recursive
                if(!root) return;

                // postorder
                flatten(root->left);
                flatten(root->right);
                // 左右子樹都已經是flatten

                TreeNode *temp = root->right;
                root->right =  root->left;
                root->left = nullptr;

                TreeNode *p = root;
                while(p->right) p=p->right;
                p->right = temp;

        // option 3 recursive
        // while (root)
        // {
        //     if (root->left)
        //     {
        //         flatten(root->left);
        //         TreeNode *right = root->right;
        //         root->right = root->left;
        //         root->left = nullptr;

        //         while (root->right)
        //         {
        //             root = root->right;
        //         }
        //         root->right = right;
        //     }
        //     root = root->right;
        // }
    }
};