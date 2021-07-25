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
    TreeNode *buildTree(vector<int>& preorder,int lo, int hi, vector<int>& inorder, int l, int r) {
        // preorder traverse
        // preorder中第一個元素為根節點，先處理根節點的業務，在處理左右子樹
        if(lo > hi || l>r) return nullptr;
        if(preorder.size()==1 && inorder.size()==1) return new TreeNode(preorder[0]);
        
        TreeNode *root = new TreeNode(preorder[lo]);
        // 從 inorder 找尋根節點，並切分出左右子樹的數組
        int index = -1;
        for(int i=l;i<=r;++i){
            if(inorder[i] == preorder[lo]){
                index = i;
                break;
            }
        }
        
        root->left = buildTree(preorder, lo+1,lo +index-l,  inorder,l, index-1);
        root->right =  buildTree(preorder, lo +index-l+1, hi,inorder,index+1, r);
        
        return root;
    
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        return buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
        
        
    }
};