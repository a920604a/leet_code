
A critical point in a linked list is defined as either a local maxima or a local minima.

A node is a local maxima if the current node has a value strictly greater than the previous node and the next node.

A node is a local minima if the current node has a value strictly smaller than the previous node and the next node.

Note that a node can only be a local maxima/minima if there exists both a previous node and a next node.

Given a linked list head, return an array of length 2 containing [minDistance, maxDistance] where minDistance is the minimum distance between any two distinct critical points and maxDistance is the maximum distance between any two distinct critical points. If there are fewer than two critical points, return [-1, -1].


Example 1:
```
Input: head = [3,1]
Output: [-1,-1]
Explanation: There are no critical points in [3,1].
```

Example 2:
```
Input: head = [5,3,1,2,5,1,2]
Output: [1,3]
Explanation: There are three critical points:
- [5,3,1,2,5,1,2]: The third node is a local minima because 1 is less than 3 and 2.
- [5,3,1,2,5,1,2]: The fifth node is a local maxima because 5 is greater than 2 and 1.
- [5,3,1,2,5,1,2]: The sixth node is a local minima because 1 is less than 5 and 2.
The minimum distance is between the fifth and the sixth node. minDistance = 6 - 5 = 1.
The maximum distance is between the third and the sixth node. maxDistance = 6 - 3 = 3.
```
Example 3:
```
Input: head = [1,3,2,2,3,2,2,2,7]
Output: [3,3]
Explanation: There are two critical points:
- [1,3,2,2,3,2,2,2,7]: The second node is a local maxima because 3 is greater than 1 and 2.
- [1,3,2,2,3,2,2,2,7]: The fifth node is a local maxima because 3 is greater than 2 and 2.
Both the minimum and maximum distances are between the second and the fifth node.
Thus, minDistance and maxDistance is 5 - 2 = 3.
Note that the last node is not considered a local maxima because it does not have a next node.
```

Example 4:

```
Input: head = [2,3,3,2]
Output: [-1,-1]
Explanation: There are no critical points in [2,3,3,2].

```

Example 5:
```
Input: head = [2,2,1,3]
Output: [-1,-1]
Explanation: There are no critical points in [2,2,1,3].

```
Constraints:
```
The number of nodes in the list is in the range [2, 105].
1 <= Node.val <= 105

```

```cpp
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
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // O(n) time
        int local_min = INT_MAX, local_max = INT_MIN;
        
        vector<int> ret(2,-1);
        if(!head || !head->next || !head->next->next) return ret;
        ListNode *pre = head, *cur = head->next, *post = head->next->next;
        // vector<pair<ListNode*, int>> collect;
        vector<int> nums;
        int i = 1;
        while(post){
            if(cur->val > pre->val && cur->val > post->val){
                local_max = max(local_max, cur->val);
                // collect.push_back(make_pair(cur, i));
                nums.push_back(i);
                
            }
            else if(cur->val < pre->val && cur->val < post->val) {
                local_min = min(local_min, cur->val);
                // collect.push_back(make_pair(cur, i));
                nums.push_back(i);
            }
            
            i++;
            pre = cur;
            cur = post;
            post = post->next;
        }
        
        
        if(nums.empty()) return {-1,-1};
        // for(int n:nums) cout<<n<<" ";
        // given increase arr , to find max diff and min diff
        //  2   4   5 => 1,3
        //  1   4   =>  3,3
        //  
        int minDistance = INT_MAX, maxDistance = INT_MIN;
        maxDistance = nums.back() - nums.front();
        for(int i=1;i<nums.size() ; ++i){
            minDistance = min(minDistance, nums[i] - nums[i-1]);
        }

        return {minDistance, maxDistance};
    }
};
```