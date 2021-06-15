/*
 * @Author: yuan
 * @Date: 2021-05-05 16:02:09
 * @LastEditTime: 2021-05-05 16:02:16
 * @FilePath: /C_plus/1046_LastStoneWeight.cpp
 */
class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {

        priority_queue<int> q;
        for (int i : stones)
            q.push(i);
        while (!q.empty())
        {
            //             cout<<q.top()<<" ";
            //             q.pop();
            int top = q.top();
            q.pop();
            if (!q.empty())
            {
                int sec = q.top();
                q.pop();
                top = top - sec;
                q.push(top);
            }
            else
            {
                return top;
            }
        }
        return 1;
    }
};