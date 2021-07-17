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
    int childDepth(Node *root)
    {

        if (root == nullptr)
            return 0;
        vector<Node *> tmp;
        if (root->children == tmp)
            return 1;
        int _max = 0;
        for (Node *child : root->children)
        {
            _max = max(childDepth(child), _max);
        }
        return 1 + _max;
    }
    int maxDepth(Node *root)
    {
        if (root == nullptr)
            return 0;
        int ret = 0;
        return childDepth(root);
    }
};