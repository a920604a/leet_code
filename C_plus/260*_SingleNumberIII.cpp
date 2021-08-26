class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {

        // option O(n) time and O(1) space
        // 1. 將所有數字 xor，得到結果為那兩個單獨的數字的xor diff
        // 2. 藉由 diff & -diff 去解出 那兩個數字

        if (nums.size() == 2)
            return nums;

        int diff = 0;
        for (int n : nums)
            diff ^= n;
        diff &= -diff;
        vector<int> ret(2, 0);
        for (int a : nums)
        {
            if (a & diff)
                ret[0] ^= a;
            else
            {
                cout << a << endl;
                ret[1] ^= a;
            }
        }
        return ret;
    }
};