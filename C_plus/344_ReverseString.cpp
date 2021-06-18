class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        // option 1
        // stack<int> sta;
        // for(char c:s){
        //     sta.push(c);
        // }
        // s.clear();
        // while(!sta.empty()){
        //     char c = sta.top();
        //     s.push_back(c);
        //     sta.pop();
        // }
        //option 2  雙指針
        int l = 0, r = s.size() - 1;
        while (l < r)
        {
            //switch
            char tmp = s[l];
            s[l] = s[r];
            s[r] = tmp;
            l++;
            r--;
        }
    }
};