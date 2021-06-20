class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        // option 1
        // use stack O(n) time O(n) space
        // stack<char> sta;
        // for(char t:s) sta.push(t);
        // string ret ="";
        // while(!sta.empty()){
        //     ret += sta.top();
        //     sta.pop();
        // }
        // for(int i=0;i<ret.size();++i){
        //     s[i]  = ret[i];
        // }

        // option 2
        // two pointer to swtich  in-place
        // O(n) time O(1) space
        int l = 0, r = s.size() - 1;
        while (l < r)
        {
            swap(s[l++], s[r--]);
        }
    }
};