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
class BSTIterator {
private:
    stack<TreeNode * >sta;
public:
    BSTIterator(TreeNode* root) {
        // inorder traverse
        // O(h) space
        TreeNode *p = root;
        while(p){
            sta.push(p);
            p=p->left;
        }
       
    }
    
    int next() {
        // O(1) time
        TreeNode * p = sta.top();
        sta.pop();
        int ans = p->val;
        if(p->right){
            p = p->right;
            while(p){
                // 因為是BST 下一個節點並存在右子樹最小的節點，也就是右子樹的最左邊的葉子
                sta.push(p);
                p=p->left;
            }
        }
        
        return ans;
        
    }
    
    bool hasNext() {
        // O(1) time 
        return !sta.empty();
        
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */