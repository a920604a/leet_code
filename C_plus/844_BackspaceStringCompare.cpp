class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {

        // option 1 O(n) time, O(n) space
        //         stack<char> sta, sta2;

        //         for(char c:s){
        //             if(c=='#' && !sta.empty()){
        //                 sta.pop();
        //             }
        //             else if(c!='#') sta.push(c);
        //         }

        //         for(char c:t){
        //             if(c=='#' && !sta2.empty()){
        //                 sta2.pop();
        //             }
        //             else if(c!='#') sta2.push(c);
        //         }

        //         // check two stack is th same

        //         if(sta.size()!=sta2.size()) return false;
        //         while(!sta.empty() && !sta2.empty()){
        //             if(sta.top()!= sta2.top()) return false;
        //             sta.pop();
        //             sta2.pop();
        //         }
        //         return (sta.empty()&&sta2.empty())?true:false;

        // option 2
        // O(n) time and O(1) space

        return text(s) == text(t);

        // option 3
        // O(n) time and O(1) space
        string S = "", T = "";
        for (char c : s)
            c == '#' ? S.size() > 0 ? S.pop_back() : void() : S.push_back(c);
        for (char c : t)
            c == '#' ? T.size() > 0 ? T.pop_back() : void() : T.push_back(c);
        return S == T;
    }
    string text(string s)
    {
        string ret = "";
        for (char c : s)
        {
            if (c == '#' && !ret.empty())
                ret.pop_back();
            else if (c != '#')
                ret.push_back(c);
        }

        return ret;
    }
};