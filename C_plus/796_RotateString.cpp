class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        // option 1 O(len a + len b)
        // 將字串s1 = s1+s1 在判斷s2是否為s1子字串
        if (s.empty() && goal.empty())
            return true;
        int a = s.size();
        s = s + s;
        if (a > 0 && a == goal.size())
        {
            if (s.find(goal) != std::string::npos)
                return true;
        }
        return false;

        // option 1.1 improved
        if (s.size() != goal.size())
            return false;
        s = s + s;
        return (s.find(goal) != std::string::npos);
    }
}
}
;