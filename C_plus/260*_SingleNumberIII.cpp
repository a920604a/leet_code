class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {

        // option 1 O(n) time and O(n) space
        set<int> s;
        for (int n : nums)
        {
            if (s.count(n))
                s.erase(n);
            else
                s.insert(n);
        }

        vector<int> ret;
        for (int n : nums)
        {
            if (s.count(n))
                ret.push_back(n);
        }
        return ret;

        // option O(n) time and O(1) space
        // 1. 將所有數字 xor，得到結果為那兩個單獨的數字的xor diff
        // 2. 藉由 diff & -diff 去解出 那兩個數字

        unsigned int diff = 0;
        for (int n : nums)
            diff ^= n;
        diff &= -diff;
        //-diff 110 => reverse bit and + 1 => 001 -> 010 
        // set this diff bit to divide two part
        vector<int> ret(2, 0);
        for (int a : nums)
        {
            if (a & diff)
            {
                ret[0] ^= a;
            }
            else
            {
                ret[1] ^= a;
            }
        }
        return ret;
    }
};