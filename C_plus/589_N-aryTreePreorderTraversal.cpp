/*
 * @Author: yuan
 * @Date: 2021-07-16 20:07:53
 * @LastEditTime: 2021-07-16 20:09:49
 * @FilePath: /leet_code/C_plus/589_N-aryTreePreorderTraversal.cpp
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
    void preorder(Node *root, vector<int> &ret)
    {
        if (!root)
            return;

        ret.push_back(root->val);

        for (Node *child : root->children)
        {
            // left to right
            preorder(child, ret);
        }
    }
    vector<int> preorder(Node *root)
    {
        vector<int> ret;
        preorder(root, ret);
        return ret;
    }
};