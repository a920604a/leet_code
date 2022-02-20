---
title: 653. Two Sum IV - Input is a BST
categories: leetcode
comments: false
---



## [problem](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/)

## solution

#### option 1 - vector record
```c++
class Solution {
public:
    void traverse(TreeNode * node, vector<int>& ret){
        if(!node) return;
        traverse(node->left, ret);
        ret.push_back(node->val);
        traverse(node->right, ret);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> ret;
        traverse(root, ret);
        int n = ret.size();
        int l = 0,r = n-1;
        while(l<r){
            if(ret[l] + ret[r] ==k)  return true;
            else if(ret[l] + ret[r] < k) l++;
            else r--;
        }
        return false;
        
    }
};
```

#### option 2 - dfs

```c++
class Solution {
public:
    unordered_set<int> visited;
    bool traverse(TreeNode *node, int k ){
        
        if(!node) return false;
        // pre-order traverse
        bool left = traverse(node->left, k);
        
        if(visited.find(k-node->val)!=visited.end() ) return true;
        visited.insert(node->val);
        
        bool right = traverse(node->right, k);
        return left || right;
    }
    bool findTarget(TreeNode* root, int k) {
        return traverse(root, k);
    }
};
```



#### option 3 - bfs

```c++
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        queue<TreeNode *> q;
        unordered_set<int> visited;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;++i){
                TreeNode *p = q.front();
                q.pop();
                
                if(visited.find(k-p->val)!=visited.end()) return true;
                visited.insert(p->val);
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
                
            }
        }
        return false;
        
    }
};
```
## analysis
- option 1
    - time complexity `O(n)` n is number of node
    - space complexity `O(n)`
- option 2
    - time complexity `O(n)` 
    - space complexity `O(1)`
