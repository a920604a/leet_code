/*
 * @Author: yuan
 * @Date: 2021-07-16 21:49:27
 * @LastEditTime: 2021-07-16 21:49:27
 * @FilePath: /leet_code/C_plus/653*_TwoSumIV-InputisaBST.cpp
 */
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
private:
    unordered_set<int> s;

public:
    //     void inorder(TreeNode *root, vector<int> & vec){
    //         if(!root) return ;

    //         inorder(root->left, vec);
    //         vec.push_back(root->val);
    //         inorder(root->right, vec);
    //     }
    bool findTarget(TreeNode *root, int k)
    {
        // option 1 利用vector紀錄每一個節點 O(n) tiem and O(n) space
        // vector<int> vec;
        // inorder(root, vec);
        // // two pointer
        // int l =0,r= vec.size()-1;
        // while(l<r){
        //     if(vec[l]+vec[r]==k) return true;
        //     else if(vec[l]+vec[r]<k) l++;
        //     else r--;
        // }
        // return false;

        // option 2 use set + DFS
        if (!root)
            return false;
        if (s.count(k - root->val))
            return true;
        s.insert(root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);


        // option 2.1 BFS +queue
        unordered_set<int> s;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *p = q.front();
            q.pop();
            if(s.count(k - p->val )) return true;
            s.insert(p->val);
            if(p->left) q.push(p->left);
            if(p->right) q.push(p->right);
                   
            
        }
        
        return false;

    }
};