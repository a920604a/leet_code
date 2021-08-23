/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    void connectTwoNode(Node *node1, Node *node2)
    {
        if (node1 == nullptr || node2 == nullptr)
            return;

        // preorder
        node1->next = node2;

        // 連接相同父節點的兩個子節點
        connectTwoNode(node1->left, node1->right);
        connectTwoNode(node2->left, node2->right);

        // 連接跨越父節點的兩個子節點
        connectTwoNode(node1->right, node2->left);
    }
    Node *connect(Node *root)
    {
        

        // option 1 preorder
        if (root == nullptr)  return root;

        connectTwoNode(root->left, root->right);
        return root;


        // option 2 level order traverse
        if(!root) return nullptr;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int size =  q.size();
            for(int i = 0; i <size ; ++i){
                Node *p = q.front();
                q.pop();
                if(i<size-1 ) p->next = q.front(); 
                else p->next = nullptr;
                
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
        }
            
        return root;
    }
};