class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {

        int slow = 0, fast = 0;
        while (fast < nums.size())
        {

            if (nums[fast] != val)
            {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        return slow;
    }

    void moveZeroes(vector<int> &nums)
    {

        // option 1 two pointer
        //         int n= nums.size(), slow=0;
        //         for(int i =0;i<n;++i){
        //             if(nums[i]!=0){ // sawp index-slow index-i ，不必考慮index-i 是否為0
        //                 swap(nums[slow], nums[i]);
        //                 slow++;
        //             }
        //         }

        // option 2
        int p = removeElement(nums, 0);
        for (; p < nums.size(); ++p)
        {
            nums[p] = 0;
        }
    }
};