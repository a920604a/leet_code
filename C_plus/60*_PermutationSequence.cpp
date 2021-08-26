class Solution
{
public:
    vector<int> nextPermutation(vector<int> nums)
    {
        // 1   2   7   4   3   1
        // 1   3   7   4   2   1
        // 1. 從右往左找第一個非遞增數字
        // 2. 找到2 索引i 之後，從右往左找第一個比2大的數字索引j
        // 3. swap(s[i], s[j])
        // 4. reverse(s.begin() + i+1, s.end())

        int n = nums.size();
        int i, j;
        for (i = n - 2; i > -1; i--)
        {
            if (nums[i] < nums[i + 1])
                break;
        }
        if (i < 0)
            reverse(nums.begin(), nums.end());
        else
        {
            for (j = n - 1; j > i; j--)
            {
                if (nums[j] > nums[i])
                    break;
            }

            swap(nums[i], nums[j]);
            reverse(nums.begin() + i + 1, nums.end());
        }

        return nums;
    }

    void traverse(string s, int k, string out, vector<string> &ret)
    {
        if (out.size() == s.size())
        {
            ret.push_back(out);
            return;
        }

        for (int i = 0; i < s.size(); ++i)
        {
            if (out.find(s[i]) != string::npos)
                continue;
            out = out + s[i];
            traverse(s, i + 1, out, ret);
            out.pop_back();
        }
    }
    string getPermutation(int n, int k)
    {

        // option 1 O(n) time out
        // generate string depend n
        // vector<int> next(n);
        // for(int i=1;i<=n;++i) next[i-1] = i;
        // string ret ;
        // for(int i=1;i<k;++i){
        //     next = nextPermutation(next);
        // }
        // for(int j = 0;j<n;++j) ret += to_string(next[j]);
        // return ret;

        // option 2 BFS time out
        string s;
        for (int i = 1; i <= n; ++i)
            s += to_string(i);
        vector<string> ret;
        traverse(s, 0, "", ret);
        return ret[k - 1];
    }
};