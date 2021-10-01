class Solution
{
public:
    int numUniqueEmails(vector<string> &emails)
    {
        unordered_set<string> dict;
        for (string email : emails)
        {

            int n = email.size();
            int sp = 0;
            while (sp < n && email[sp] != '@')
                sp++;
            if (email[sp] != '@')
            {
                break;
            }
            // convert
            string temp = "";

            for (int i = 0; i < sp; ++i)
            {
                if (email[i] == '+')
                    break;
                else if (email[i] == '.')
                    continue;
                else
                {
                    temp += email[i];
                }
            }
            temp += '@';
            for (int i = sp + 1; i < n; ++i)
            {
                temp += email[i];
            }
            if (!temp.empty())
            {
                dict.insert(temp);
            }
        }
        return dict.size();
    }
};