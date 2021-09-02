class Solution
{
public:
    vector<string> readBinaryWatch(int turnedOn)
    {

        // 用bitset 將任意進制數轉換為二進制，coun統計 1 的個數
        vector<string> ret;
        for (int h = 0; h < 12; ++h)
        {
            for (int m = 0; m < 60; ++m)
            {
                // (h<<6 ) avoid minute , so hour shift 64 = 2^6
                if (bitset<10>((h << 6) + m).count() == turnedOn)
                {
                    string cand = to_string(h);
                    if (m < 10)
                        cand += ":0";
                    else
                        cand += ":";
                    cand += to_string(m);
                    ret.push_back(cand);
                }
            }
        }
        return ret;
    }
};