class Solution
{
public:
    bool canReorderDoubled(vector<int> &arr)
    {

        //   4  -2  2   4
        //  -2  -4  2   4   i=0,1 => [1] = 2*[0]
        //  1   2   4   8   4   16
        //  i=0,1,2
        // 兩兩一組，能不能找到一種組法，使得 兩兩成對，會為2倍關係

        //. 1 2 4 8 2 16  =>    1  2    2   4   8   16
        //
        int n = arr.size();
        unordered_map<int, int> mp;
        for (int n : arr)
            mp[n]++;
        //
        vector<int> keys;
        for (auto &a : mp)
            keys.push_back(a.first);

        // 確保 -4 出現在 -8 之前
        sort(keys.begin(), keys.end(), [](int i, int j)
             { return abs(i) < abs(j); });

        for (int k : keys)
        {
            if (mp[k] > mp[2 * k])
                return false;
            mp[2 * k] -= mp[k];
        }
        return true;
    }
};