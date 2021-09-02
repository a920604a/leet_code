class Solution
{
public:
    int maxProduct(vector<string> &words)
    {
        // option 1  O(n^3) maybe time out
        int n = words.size();
        vector<set<char> > wordSet(n);
        for (int i = 0; i < n; ++i)
        {
            for (char c : words[i])
                wordSet[i].insert(c);
        }
        int ret = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                bool f = true;
                for (char c : words[j])
                {
                    if (wordSet[i].count(c))
                    {
                        f = false;
                        break;
                    }
                }
                if (f)
                {
                    // cout<<words[i]<<" "<<words[j]<<endl;
                    int len = words[i].size() * words[j].size();
                    ret = max(len, ret);
                }
            }
        }
        return ret;
    }
};