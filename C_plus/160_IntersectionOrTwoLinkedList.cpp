/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {

        // option 1
        // 1. 是否有相同終點以判斷是否有交集
        // 2. 如果有交集，讓長串列先走幾步
        int asize = 0, bsize = 0;
        for (ListNode *p = headA; p; p = p->next)
            asize++;
        for (ListNode *p = headB; p; p = p->next)
            bsize++;
        ListNode *pa = headA, *pb = headB;
        while (pa->next)
            pa = pa->next;
        while (pb->next)
            pb = pb->next;
        if (pa != pb)
            return nullptr;

        /* Set pointers to the start of each linked list. */
        ListNode *longer = (asize >= bsize) ? headA : headB;
        ListNode *shorter = (asize < bsize) ? headA : headB;

        // get k node in the linked list
        int len = abs(asize - bsize);
        while (len)
        {
            longer = longer->next;
            len--;
        }

        /* Move both pointers until you have a collision. */
        while (shorter != longer)
        {
            shorter = shorter->next;
            longer = longer->next;
        }
        return shorter;

        // option 2

        //         ListNode *a = headA, *b = headB;

        //         while(a!=b){

        //             if(a==nullptr) a = headB;
        //             else a=a->next;
        //             if(b==nullptr) b = headA;
        //             else b=b->next;
        //         }
        //         return a;
    }
};