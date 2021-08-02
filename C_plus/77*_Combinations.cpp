class Solution
{
public:
    void backtrack(int n, int k, int start, vector<int> &track, vector<vector<int> > &ret)
    {

        // 到達樹的底部
        if (k == track.size())
        {
            ret.push_back(track);
            return;
        }

        for (int i = start; i <= n; ++i)
        {
            // 做選擇
            track.push_back(i);
            // 進入下一層決策樹
            backtrack(n, k, i + 1, track, ret);
            // 撤消選擇
            track.pop_back();
        }
    }
    vector<vector<int> > combine(int n, int k)
    {
        vector<vector<int> > ret;
        if (k <= 0 || n <= 0)
            return ret;
        vector<int> track;
        backtrack(n, k, 1, track, ret);
        return ret;
    }
};