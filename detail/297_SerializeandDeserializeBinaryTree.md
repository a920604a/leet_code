---
title: 297. Serialize and Deserialize Binary Tree
tags:
    - backtracking
    - bfs
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/)
## solution

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    
    string encode(TreeNode *root){
        if(!root)  return "#";
        string ret ;
        
        ret += to_string( root->val) + ",";
        ret += encode(root->left);
        ret += encode(root->right);
        return ret;
        //  1,2,##3,4,##5,##
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ret = encode(root);
        return ret;
    }

    TreeNode* decode(vector<string> &vec, int &i){
        if(i==vec.size()) return nullptr;
        if(vec[i] == "#") {
            i++;
            return nullptr;
            
        }
        int val = 0, j= 0 ;
        string temp = vec[i];
        bool flag = true;
        if(temp[j]=='-'){
            flag = false;
            j++;
        }
        for(;j<temp.size();j++) val = 10*val + temp[j]-'0';
        if(!flag) val *= -1;
        TreeNode *root = new TreeNode(val);
        i++;
        
        root->left = decode(vec, i);
        root->right = decode(vec, i);
        return root;
    }
    vector<string> split(string data){
        vector<string> ret;
        string cur;
        for(int i=0;i<data.size(); ++i){
            if(data[i] == ','){
                ret.push_back(cur);
                cur.clear();
            }
            else if(data[i]=='#') ret.push_back("#");
            else cur+=data[i];
        }
        return ret;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        vector<string> vec = split(data);
        int i = 0;
        TreeNode *root = decode(vec, i);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
```

