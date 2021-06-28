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

// option 1
// class Solution {
// private:
//     int len;
//     ListNode *head ;
// public:
//     /** @param head The linked list's head.
//         Note that the head is guaranteed to be not null, so it contains at least one node. */
//     Solution(ListNode* head) {
//         this->head = head;
//         len = 0;
//         for(ListNode *p = head; p;p=p->next) len++;
//     }

//     /** Returns a random node's value. */
//     int getRandom() {
//         /* 產生 [min , max] 的整數亂數 */

//         ListNode *p = head;
//         int randomer = rand() % len;
//         for(randomer = randomer;randomer>0;randomer--){
//             p=p->next;
//         }
//         return p->val;
//     }
// };

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

// option 2  水塘抽样 Reservoir Sampling
class Solution
{
private:
    ListNode *head;

public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode *head)
    {
        this->head = head;
    }

    /** Returns a random node's value. */
    int getRandom()
    {

        int ret = head->val, i = 2;
        ListNode *cur = head->next;
        while (cur)
        {
            int j = rand() % i;
            if (j == 0)
                ret = cur->val;
            i++;
            cur = cur->next;
        }
        return ret;
    }
};