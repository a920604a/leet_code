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

        int i = 0, ret = 0;
        ListNode *p = head;
        while (p)
        {
            i++;
            // rand()%i 相當於 生成 [0,i) 的整數
            // rand()%i ==0 相當於 這個整數等於0 的機率是 1/i
            if (rand() % i == 0)
                ret = p->val;
            p = p->next;
        }
        return ret;
    }
};