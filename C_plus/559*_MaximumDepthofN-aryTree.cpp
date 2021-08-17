/*
 * @Author: yuan
 * @Date: 2021-07-16 19:42:54
 * @LastEditTime: 2021-07-16 19:42:54
 * @FilePath: /leet_code/C_plus/559*_MaximumDepthofN-aryTree.cpp
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
    int maxDepth(Node *root)
    {
        if (!root)
            return 0;
        int ret = 1;
        for (Node *x : root->children)
        {
            ret = max(1 + maxDepth(x), ret);
        }
        return ret;
    }
};