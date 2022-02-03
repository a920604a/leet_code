/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *reverseList(struct ListNode *head)
{

    //     if(!head || !head->next) return head;
    //     struct ListNode *pre = (struct ListNode *)malloc(sizeof(struct ListNode)) ;
    //     pre->next = head;
    //     struct ListNode *cur = head;
    //     while(cur->next){
    //         struct ListNode * temp = cur->next;
    //         cur->next = temp->next;
    //         temp->next = pre->next;
    //         pre->next = temp;

    //     }
    //     return pre->next;

    if (!head)
        return head;
    if (!head->next)
        return head;
    struct ListNode *node = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return node;
}