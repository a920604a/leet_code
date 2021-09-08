class Solution
{
public:
    char slowestKey(vector<int> &releaseTimes, string keysPressed)
    {
        char ret;
        int val = 0;
        int n = releaseTimes.size();
        ret = keysPressed[0], val = releaseTimes[0];
        for (int i = 1; i < n; ++i)
        {
            int time = releaseTimes[i] - releaseTimes[i - 1];
            if (time > val)
            {
                val = time;
                ret = keysPressed[i];
            }
            else if (time == val)
            {
                if (ret - 'a' < keysPressed[i] - 'a')
                    ret = keysPressed[i];
            }
        }
        return ret;
    }
};