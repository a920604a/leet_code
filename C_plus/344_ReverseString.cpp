class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        // option 1 stack support   not in-place
        //         stack<char> sta;
        //         vector<char> ret;
        //         for(char c:s) sta.push(c);

        //         while(!sta.empty()){
        //             ret.push_back(sta.top());
        //             sta.pop();
        //         }
        //         s = ret;

        // option 1.1 stack support  in-place
        // stack<char> sta;
        // vector<char> ret;
        // for(char c:s) sta.push(c);
        // int i=0;
        // while(!sta.empty()){
        //     s[i++] = sta.top();
        //     sta.pop();
        // }

        // option 2 two point and swap
        int l = 0, r = s.size() - 1;
        while (l < r)
        {
            swap(s[l++], s[r--]);
        }
    }
};