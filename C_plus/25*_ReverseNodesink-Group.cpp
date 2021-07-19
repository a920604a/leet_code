/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    int getSize(ListNode *head)
    {
        int size = 0;
        for (ListNode *p = head; p; p = p->next)
            size++;
        return size;
    }
    ListNode *getNextNode(ListNode *head, int k)
    {
        ListNode *p = head;
        for (; k; k--)
            p = p->next;
        return p;
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (!head->next)
            return head;
        int size = getSize(head);
        int reverseTime = size / k;

        ListNode *cur = head, *pre = new ListNode(-1), *ret = pre;
        pre->next = head;
        // reverse unit
        while (reverseTime)
        {
            ListNode *nextHead = getNextNode(cur, k);
            // cout<<"nextHead:"<<nextHead->val<<endl;
            ListNode *temp;
            while (cur->next != nextHead)
            {
                temp = cur->next;
                cur->next = temp->next;
                temp->next = pre->next;
                pre->next = temp;
            }
            reverseTime--;
            pre = cur;
            cur = nextHead;
        }

        return ret->next;
    }
};