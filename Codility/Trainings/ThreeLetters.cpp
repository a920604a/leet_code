// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <algorithm>
#include <vector>
#include <map>
bool canAdd(string &str, char x)
{
    if (str.size() < 2)
        return true;
    if (str.back() != x)
        return true;
    if (str[str.size() - 2] != x)
        return true;
    return false;
}
string solution(int A, int B)
{
    // write your code in C++14 (g++ 6.2.0)

    // 在保证没有连续三个字符相等的情况下，不停地从 a, b 中优先使用剩余次数最多的那个字符添加到结果 res 中
    vector<pair<int, char> > f = {{A, 'a'}, {B, 'b'}};

    // int total = A+B;

    string ans;
    for (int _ = 0; _ < A + B; ++_)
    {
        //
        sort(f.begin(), f.end());
        reverse(f.begin(), f.end());
        for (auto &k : f)
        {
            char ch = k.second;
            // cout<<ch<<" ";
            if (k.first > 0 && canAdd(ans, ch))
            {
                ans += ch;
                // f[ch]--;
                k.first--;
                break;
            }
        }
    }
    // cout<<ans<<endl;
    return ans;
}
