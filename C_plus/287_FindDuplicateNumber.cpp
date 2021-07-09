class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        // option 1
        // make use of set O(n) space, O(nlogn) time
        // set<int>s;
        // for(int n:nums) {
        //     if(s.find(n)!=s.end()) return n;
        //     s.insert(n);
        // }
        // return -1;

        // option 2 O(1) space
        // slow fast pointer
        int slow = 0, fast = 0, t = 0;
        // detect cycle exists
        while (1)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast)
                break;
        }
        // find begining of cycle
        while (1)
        {
            slow = nums[slow];
            t = nums[t];
            if (t == slow)
                break;
        }
        return slow;

        // option 3
        // bit-wise hard
    }
};