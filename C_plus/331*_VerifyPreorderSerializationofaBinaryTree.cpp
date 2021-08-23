class Solution
{
public:
    bool isValidSerialization(string preorder)
    {

        // 數字個數一比 # 少一個
        // 最後一個一定是 #
        // 扣掉最後一個# 數字個數和# 個數應該相同

        istringstream in(preorder);
        vector<string> v;
        string t;
        int cnt = 0;
        while (getline(in, t, ','))
            v.push_back(t);
        for (int i = 0; i < v.size() - 1; ++i)
        {
            if (v[i] == "#")
            {
                if (cnt == 0)
                    return false;
                cnt--;
            }
            else
                cnt++;
        }

        return cnt == 0 && v.back() == "#";
    }
};