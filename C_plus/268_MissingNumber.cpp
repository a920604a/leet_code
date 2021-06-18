class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        // option 1 O(n*logn)
        sort(nums.begin(), nums.end()); // O(nlogn)
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (ans != nums[i])
                break;
            ans++;
        }
        return ans;
        // option 2 math
        // int total = nums.size()*(nums.size()+1)/2;
        // for(int a:nums) total-=a;
        // return total;
    }
};