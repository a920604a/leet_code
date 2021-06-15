/*
 * @Author: yuan
 * @Date: 2021-05-12 20:27:58
 * @LastEditTime: 2021-05-12 20:27:58
 * @FilePath: /C_plus/71_SimplifyPath.cpp
 */
class Solution
{
public:
    string simplifyPath(string path)
    {
        string res, tmp;
        vector<string> stk;
        stringstream ss(path);
        while (getline(ss, tmp, '/'))
        {
            if (!tmp.empty())
            {
                if (tmp == ".")
                    continue;
                else if (tmp == "..")
                {
                    if (!stk.empty())
                        stk.pop_back();
                }
                else
                {
                    stk.push_back(tmp);
                }
            }
        }

        for (string c : stk)
            res += ('/' + c);

        return res.empty() ? "/" : res;
    }
};