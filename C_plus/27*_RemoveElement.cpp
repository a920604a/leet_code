class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        //option 1
        // vector<int>::iterator it;
        // for (it = nums.begin(); it != nums.end();)
        // {
        //     if (*it == val)
        //     {
        //         it = nums.erase(it);
        //     }
        //     else
        //         it++;
        // }
        // return nums.size();

        //option 2
        // int ret=0;
        // for(int i=0;i<nums.size();++i){
        //     if(nums[i]!=val) nums[ret++] = nums[i];
        // }
        // return ret;

        //option 3
        if (nums.empty())
            return 0;
        int l = -1;
        int r = 0;
        while (r < nums.size())
        {
            if (nums[r] == val)
                r++;
            else if (nums[r] != val)
            {
                l++;
                nums[l] = nums[r];
                r++;
            }
        }
        return l + 1;
    }
};