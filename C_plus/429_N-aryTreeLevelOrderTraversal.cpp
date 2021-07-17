/*
 * @Author: yuan
 * @Date: 2021-07-16 20:22:57
 * @LastEditTime: 2021-07-16 20:22:57
 * @FilePath: /leet_code/C_plus/429_N-aryTreeLevelOrderTraversal.cpp
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
public:
    vector<vector<int> > levelOrder(Node *root)
    {
        if (!root)
            return {};
        vector<vector<int> > ret;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            vector<int> tmp;
            while (size)
            {
                Node *cur = q.front();
                q.pop();
                tmp.push_back(cur->val);
                for (Node *child : cur->children)
                    q.push(child);
                size--;
            }
            ret.push_back(tmp);
        }

        return ret;
    }
};