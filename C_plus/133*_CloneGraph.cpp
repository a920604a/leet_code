/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
public:
    unordered_map<Node *, Node *> m;
    Node *dfs(Node *node)
    {

        if (!node)
            return nullptr;
        if (m.count(node))
            return m[node];

        Node *clone = new Node(node->val);
        m[node] = clone;
        vector<Node *> childrend;
        for (Node *child : node->neighbors)
        {
            childrend.push_back(dfs(child));
        }
        clone->neighbors = childrend;

        return clone;
    }
    Node *cloneGraph(Node *node)
    {
        //DFS
        return dfs(node);
    }
};