class Solution
{
public:
    string frequencySort(string s)
    {

        // option 1
        //         string ret="";
        //         priority_queue<pair<int, char>> q;
        //         map<char,int> m;
        //         for(char c:s) m[c]++;
        //         for(pair p :m)
        //         {
        //             q.push({p.second, p.first});  // logn
        //         }
        //         while(!q.empty()){
        //             pair p = q.top();
        //             q.pop();
        //             ret += string(p.first,p.second); //res.append(p.first, p.second);
        //         }

        //         return ret;

        // option 2
        string ret = "";
        map<char, int> m;
        vector<string> v(s.size() + 1);
        for (char c : s)
            m[c]++;
        for (auto a : m)
        {
            v[a.second].append(a.second, a.first);
        }
        for (int i = s.size(); i > 0; --i)
        { // 因為單詞出現次數不會超過字串長度
            if (!v[i].empty())
                ret.append(v[i]);
        }
        return ret;
    }
};