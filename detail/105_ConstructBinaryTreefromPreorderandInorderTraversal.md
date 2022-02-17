# 105. Construct Binary Tree from Preorder and Inorder Traversal


###### tags: `leetcode` `backtracking` `Blind Curated 75`


## [problem](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)


## solution

`preorder[l]`為根節點，並從`inorder[l:r]`找到該節點，並用此節點切割，左半部為此節點的左子樹，右半部為此節點的右子樹，並遞迴下去。

```c++
class Solution {
public:
    TreeNode *build(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir){
        if(pl>pr || il>ir) return nullptr;
        int val = preorder[pl];
        TreeNode *root = new TreeNode(val);
        int idx = -1;
        for(int i=il;i<=ir;++i){
            if(inorder[i] == val){
                idx = i;
                break;
            }
        }
        root->left = build(preorder, inorder, pl+1, pl+idx-il, il, idx-1);
        root->right = build(preorder, inorder, pl+idx-il+1, pr, idx+1, ir);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        return build(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
        
    }
};
```

## analysis
- time complexity `O(n^2)`
- space complexity `O(n^2)`  n is node number