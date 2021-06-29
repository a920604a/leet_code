class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        // option 1 cheat O(n) time and O(n) space
        //         vector<int> ret;
        //         int times = 1+nums.size()/3;
        //         unordered_map<int,int> m;
        //         for(int n:nums) m[n]++;

        //         for(auto n:m){
        //             if(n.second>=times) ret.emplace_back(n.first);
        //         }
        //         return ret;

        // option 2  O(n) time and O(1) space
        // 多數投票算法 O(n) time and O(1) space
        // 任意一數組出現次數大於 n/3 的數最多有兩個
        vector<int> res;
        int a = 0, b = 0, cnt1 = 0, cnt2 = 0, n = nums.size();
        for (int num : nums)
        {
            if (num == a)
                cnt1++;
            else if (num == b)
                cnt2++;
            else if (cnt1 == 0)
            {
                a = num;
                cnt1 = 1;
            }
            else if (cnt2 == 0)
            {
                b = num;
                cnt2 = 1;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = cnt2 = 0;
        for (int num : nums)
        {
            if (num == a)
                cnt1++;
            else if (num == b)
                cnt2++;
        }
        if (cnt1 > n / 3)
            res.emplace_back(a);
        if (cnt2 > n / 3)
            res.emplace_back(b);

        return res;
    }
};