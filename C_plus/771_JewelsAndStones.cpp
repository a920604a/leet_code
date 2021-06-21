class Solution
{
public:
    int numJewelsInStones(string jewels, string stones)
    {
        // option 1 O( nlogn)
        //         set<char> s(jewels.begin(), jewels.end());

        //         int ret = 0;
        //         for(char c:stones){
        //             if(s.find(c)!=s.end()) ret++;
        //         }

        //         return ret;

        // option 2 O(n)
        vector<int> v(128, 0);
        for (char c : stones)
            v[c]++;
        int ret = 0;
        for (char c : jewels)
            ret += v[c];
        return ret;
    }
};