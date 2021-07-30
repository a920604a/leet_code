class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        // ret 紀錄插入次數
        int ret = 0;
        // need 變數 紀錄右括號 的需求量
        int need = 0;

        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(')
            {
                // 對右括號的需求+1
                need++;
            }

            if (s[i] == ')')
            {
                // 對右括號的需求-1
                need--;
                if (need == -1)
                {
                    need = 0;
                    // 需要插入一個左括號
                    ret++;
                }
            }
        }

        return ret + need;
    }
};