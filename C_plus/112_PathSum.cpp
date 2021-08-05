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
class Solution {
public:
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        // option 1 brute force DFS O(logN)
        // if(!root) return false;
        // if(root->val == targetSum && !root->left && !root->right) return true;
        // int target = targetSum-root->val;
        // return hasPathSum(root->left, target) || hasPathSum(root->right, target);
        
        // BFS + stack or queue
//         if (!root) return false;
//         stack<TreeNode*> sta{{root}};
        
        
//         while(!sta.empty()){
//             TreeNode *t  = sta.top();
//             sta.pop();
//             if (!t->left && !t->right) {
//                 if (t->val == targetSum) return true;
//             }
//             if(t->right){
//                 t->right->val += t->val;
//                 sta.push(t->right);
//             }
//             if(t->left){
//                 t->left->val += t->val;
//                 sta.push(t->left);  
//             }
            
//         }
//         return false;
        
        
        //queue<TreeNode *> q;
        
        if (!root) return false;
        queue<TreeNode*> q{{root}};
        
        
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;++i){
                TreeNode *t  = q.front();
                q.pop();
                if (!t->left && !t->right) {
                    if (t->val == targetSum) return true;
                }
                if(t->right){
                    t->right->val += t->val;
                    q.push(t->right);
                }
                if(t->left){
                    t->left->val += t->val;
                    q.push(t->left);  
                }
            }
        }
        return false;
        
        
    }
};