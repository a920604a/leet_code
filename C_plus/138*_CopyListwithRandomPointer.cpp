/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        Node *ret = new Node(-1), *p = ret;
        map<Node *, Node *> m; // old list mapping new list
        Node *cur = head;
        while (cur)
        {
            p->next = new Node(cur->val);
            m[cur] = p->next;
            p = p->next;
            cur = cur->next;
        }

        // for(p=ret->next;p;p=p->next) cout<<p->val<<endl;  // for debug

        cur = head;
        while (cur)
        {
            m[cur]->random = m[cur->random];
            cur = cur->next;
        }
        return ret->next;
    }
};