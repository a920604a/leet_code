class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        // option 1 bit manipulation
        // a ^ a = 0 a ^ 0 = a，^有交換率，成對的數字變成０
        // int ret = 0;
        // for(int n:nums) ret^= n;
        // return ret;

        // optnio 2 general case
        int ret = 0;
        for (int i = 0; i < 32; ++i)
        {
            int sum = 0;
            for (int n : nums)
            {
                sum += (n >> i) & 1;
            }
            ret += (sum % 2) << i;
        }
        return ret;
    }
};