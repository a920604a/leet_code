class Solution
{
public:
    string plusOne(string s, int j)
    {

        if (s[j] == '9')
            s[j] = '0';
        else
            s[j] = s[j] += 1;
        return s;
    }
    string minusOne(string s, int j)
    {
        if (s[j] == '0')
            s[j] = '9';
        else
            s[j] = s[j] -= 1;
        return s;
    }

    int openLock(vector<string> &deadends, string target)
    {
        // option BFS
        // 用集合代替，可減少搜尋時間
        //         set<string> deads ;
        //         for(string d:deadends) deads.insert(d);
        //         queue<string> q;
        //         q.push("0000");
        //         int step = 0;
        //         set<string> visited;
        //         visited.insert("0000");
        //         while(!q.empty()){
        //             int size = q.size();

        //             for(int i=0;i<size ;++i){
        //                 string cur = q.front();
        //                 q.pop();
        //                 // 判斷是否為deadend
        //                 if(deads.find(cur)!=deads.end()) continue;
        //                 //判斷是否到達終點
        //                 if(cur==target) return step;

        //                 // 四種位置都有可能+-1
        //                 for(int j=0;j<4;++j){
        //                     string up = plusOne(cur, j);
        //                     string down = minusOne(cur, j);
        //                     // 查詢是否遍歷過
        //                     if(visited.find(up)==visited.end()){
        //                         q.push(up);
        //                         visited.insert(up);
        //                     }
        //                     if(visited.find(down)==visited.end()){
        //                         q.push(down);
        //                         visited.insert(down);
        //                     }
        //                 }
        //             }
        //             step++;
        //         }
        //         return -1;

        // option 2  雙向BFS
        // 因為知道終點，所以可用雙向BFS
        set<string> deads, visited, q1, q2;
        for (string d : deadends)
            deads.insert(d);
        q1.insert("0000");
        q2.insert(target);
        visited.insert("0000");
        int step = 0;

        while (!q1.empty() && !q2.empty())
        {
            set<string> temp;

            for (string cur : q1)
            {
                if (deads.count(cur))
                    continue;
                if (q2.find(cur) != q2.end())
                    return step;

                visited.insert(cur);
                for (int j = 0; j < 4; ++j)
                {
                    string up = plusOne(cur, j);
                    string down = minusOne(cur, j);
                    if (visited.find(up) == visited.end())
                    {
                        temp.insert(up);
                    }
                    if (visited.find(down) == visited.end())
                    {
                        temp.insert(down);
                    }
                }
            }
            step++;
            q1 = q2;
            q2 = temp;
        }
        return -1;
    }
};