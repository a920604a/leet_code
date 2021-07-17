/*
 * @Author: yuan
 * @Date: 2021-07-16 16:14:23
 * @LastEditTime: 2021-07-16 16:19:15
 * @FilePath: /leet_code/C_plus/501_FindModeinBinarySearchTree.cpp
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
public:
    void dfs(TreeNode *root, map<int, int> &mp)
    {
        if (root == nullptr)
            return;

        dfs(root->left, mp);
        mp[root->val]++;
        dfs(root->right, mp);
    }
    vector<int> findMode(TreeNode *root)
    {
        // option 1 O(nlogn) time,  O(n) space
        // 用hash table紀錄節點的值對應出現頻率
        // map<int,int> mp;
        // dfs(root, mp);
        // priority_queue<pair<int,int>, vector<pair<int,int>>> pq;
        // for(auto p :mp)  pq.push(make_pair(p.second, p.first));
        // vector<int> ret;
        // int _max =pq.top().first;
        // while(!pq.empty()){
        //     pair it = pq.top();
        //     if(ret.empty() || pq.top().first==_max ) ret.push_back(it.second);
        //     pq.pop();
        // }
        // return ret;

        // option 1.1 improved
        map<int, int> mp;
        int _max = 0;
        dfs(root, mp, _max);
        vector<int> ret;
        for (auto m : mp)
        {
            if (m.second == _max)
                ret.push_back(m.first);
        }
        return ret;
    }
    void dfs(TreeNode *root, map<int, int> &mp, int &mx)
    {
        if (root == nullptr)
            return;

        dfs(root->left, mp, mx);
        mp[root->val]++;
        mx = max(mx, mp[root->val]);
        dfs(root->right, mp, mx);
    }
};