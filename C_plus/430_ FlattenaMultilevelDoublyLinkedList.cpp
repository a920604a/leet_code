/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution
{
public:
    Node *flatten(Node *head)
    {
        if (!head)
            return head;
        stack<Node *> sta;
        Node *cur = head;
        while (cur->next || cur->child)
        {
            if (cur->child)
            {
                if (cur->next)
                {
                    sta.push(cur->next);
                    cur->next->prev = nullptr;
                }

                cur->child->prev = cur;
                cur->next = cur->child;
                cur->child = nullptr;
            }
            cout << cur->val << " ";
            cur = cur->next;
        }

        while (!sta.empty())
        {
            Node *p = sta.top();
            sta.pop();
            cur->next = p;
            p->prev = cur;
            while (cur->next)
            {

                cur = cur->next;
            }
        }

        return head;
    }
};