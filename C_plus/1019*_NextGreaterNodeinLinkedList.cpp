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
    vector<int> nextLargerNodes(ListNode *head)
    {
        // option 1 O(n^2)  timeout
        // vector<int> tmp;
        // for(ListNode *p=head;p;p=p->next){
        //     tmp.emplace_back(p->val);
        // }
        // vector<int> ret ;
        // for(int i=0;i<tmp.size()-1;++i){
        //     int _max = 0;
        //     for(int j=i+1;j<tmp.size();++j){
        //         if(tmp[i]<tmp[j]){
        //             _max = tmp[j];
        //             break;
        //         }
        //     }
        //     ret.emplace_back(_max);
        // }
        // ret.emplace_back(0);
        // return ret;

        // option 2 use stack inspiration from hint
        stack<int> sta;
        int _max = 0;
        vector<int> nums;
        for (ListNode *p = head; p; p = p->next)
            nums.emplace_back(p->val);
        vector<int> ret(nums.size(), 0);
        for (int i = 0; i < nums.size(); ++i)
        {

            while (!sta.empty() && nums[i] > nums[sta.top()])
            {
                ret[sta.top()] = nums[i];
                sta.pop();
            }
            sta.push(i);
            cout << sta.top() << endl;
        }
        return ret;
    }
};