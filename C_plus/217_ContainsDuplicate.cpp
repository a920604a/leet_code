class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {

        // O(nlogn) time and O(m) space
        // unordered_set<int> s;
        // for(int n:nums){
        //     if(s.count(n)) return true;
        //     s.insert(n);
        // }
        // return false;

        // O(nlogn) time and O(1) space
        sort(nums.begin(), nums.end());
        int temp = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            if (temp == nums[i])
                return true;
            temp = nums[i];
        }
        return false;
    }
};