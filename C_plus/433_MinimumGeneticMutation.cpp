class Solution
{
public:
    int minMutation(string start, string end, vector<string> &bank)
    {

        set<string> banks(bank.begin(), bank.end());
        set<string> visited;
        int step = 0;
        string b = "ACGT";
        queue<string> q;
        visited.insert(start);
        q.push(start);
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; ++i)
            {
                string p = q.front();
                q.pop();
                if (p == end)
                    return step;
                for (int j = 0; j < 8; ++j)
                {
                    for (char c : b)
                    {
                        string temp = p;
                        temp[j] = c;
                        if (banks.count(temp) && !visited.count(temp))
                        {
                            q.push(temp);
                            visited.insert(temp);
                        }
                    }
                }
            }
            step++;
        }

        return -1;
    }
};