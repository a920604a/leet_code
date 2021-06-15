/*
 * @Author: yuan
 * @Date: 2021-05-04 09:07:19
 * @LastEditTime: 2021-05-04 09:07:30
 * @FilePath: /C_plus/430_ FlattenaMultilevelDoublyLinkedList.cpp
 */
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
        Node *cur = head;
        if (!head)
            return head;
        stack<Node *> s;
        while (cur->next || cur->child)
        {
            if (cur->child)
            {
                if (cur->next)
                {
                    s.push(cur->next);
                    cur->next->prev = nullptr;
                }
                cur->child->prev = cur;
                cur->next = cur->child;
                cur->child = nullptr;
            }

            cur = cur->next;
        }
        cout << endl;
        while (!s.empty())
        {
            Node *p = s.top();
            s.pop();

            cur->next = p;
            p->prev = cur;
            while (cur->next)
            {
                cur->next->prev = cur;
                cur = cur->next;
            }
        }

        return head;
    }
};