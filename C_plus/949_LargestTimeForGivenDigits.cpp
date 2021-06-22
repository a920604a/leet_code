class Solution
{
public:
    string largestTimeFromDigits(vector<int> &arr)
    {
        string ret = "";
        for (int i = 0; i < arr.size(); ++i)
        {
            for (int j = 0; j < arr.size(); j++)
            {
                for (int k = 0; k < arr.size(); ++k)
                {
                    if (i == j || j == k || k == i)
                        continue;
                    string h = to_string(arr[i]) + to_string(arr[j]);
                    string m = to_string(arr[k]) + to_string(arr[6 - i - j - k]);
                    if (stoi(h) < 24 && stoi(m) < 60 && (h + ":" + m) > ret)
                        ret = h + ':' + m;w
                }
            }
        }
        return ret;
    }
};