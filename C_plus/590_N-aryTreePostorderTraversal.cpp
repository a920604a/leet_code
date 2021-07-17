/*
 * @Author: yuan
 * @Date: 2021-07-16 20:13:25
 * @LastEditTime: 2021-07-16 20:13:25
 * @FilePath: /leet_code/C_plus/590_N-aryTreePostorderTraversal.cpp
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
    void postorder(Node *root, vector<int> &ret)
    {

        if (!root)
            return;
        for (Node *child : root->children)
        {
            postorder(child, ret);
        }
        ret.push_back(root->val);
    }
    vector<int> postorder(Node *root)
    {
        vector<int> ret;
        postorder(root, ret);
        return ret;
    }
};