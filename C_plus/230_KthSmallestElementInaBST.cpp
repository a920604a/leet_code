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

struct MyTreeNode {
    int val;
    int size ;
    MyTreeNode *left;
    MyTreeNode *right;
    MyTreeNode(int x) : val(x), size(1), left(nullptr), right(nullptr) {}
    
 };


class Solution {
private:
    vector<int> v;
    int ret = 0, rank = 0;
public:
    void traverse(TreeNode* root){
        // base case
        if(!root) return ;
        
        // inorder
        // L
        traverse(root->left);
        // V
        v.push_back(root->val);
        // R
        traverse(root->right);
    } 
    void traverse(TreeNode *root, int k ){
        //base case
        if(!root) return ;
        
        //inorder
        // L
        traverse(root->left, k);
        
        // V
        rank++;
        if( k==rank){
            ret = root->val;
            return;
        }
        // R
        traverse(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        // option 1 
        // 因為是BST，inorder traverse 本身會是已排序的
        // traverse(root);
        // return v[k-1];
        
        
        // option 1.1 optimalize option 1 using one varialbe
        // traverse(root, k);
        // return ret;
        
        
        // option 1.3 divid and conquer
        // preorder
        // int cnt = count(root->left);
        // if( k<=cnt) return kthSmallest(root->left, k);
        // else if(k>cnt +1 ) return kthSmallest(root->right, k-cnt-1);
        // return root->val;
        
        
        // option 2 iterative + stack support
        int cnt = 0;
        stack<TreeNode *> sta;
        TreeNode *p = root;
        while(p || !sta.empty()){       
            // L
            while(p){
                sta.push(p);
                p=p->left;
            }
            p = sta.top();
            sta.pop();
            
            // V
            cnt++;
            if(cnt ==k) return p->val;
            
            // R
            p=p->right;
        }
        return 0;
        
        
        // option 3 高級寫法
        // 295. Find Median from Data Stream
        // MyTreeNode *node = build(root);
        // return helper(node, k);
    }
    int count(TreeNode *node){
        if(!node) return 0;
        return count(node->left) + count(node->right) +1;
    }
    MyTreeNode* build(TreeNode* root) {
    
        if(!root) return nullptr;
        
        // traverse
        MyTreeNode *node = new MyTreeNode(root->val);
        node->left = build(root->left);
        node->right = build(root->right);
        if (node->left) node->size += node->left->size;
        if (node->right) node->size += node->right->size;
        return node;
        
    }
    int helper(MyTreeNode * node, int k){
        if(node->left){
            int cnt = node->left->size;
            if(k<=cnt) return helper(node->left, k);
            else if(k> cnt+1) return helper(node->right, k-1-cnt);
            
            return node->val;
        }
        else{
            if(k==1) return node->val;
            return helper(node->right, k-1);
        }
    }
    
};