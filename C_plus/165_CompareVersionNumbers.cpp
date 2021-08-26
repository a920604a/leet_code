class Solution
{
public:
    vector<int> make(string version)
    {
        vector<int> ver;
        int l = 0;
        int ret = 0;
        while (l < version.size())
        {
            if (version[l] == '.')
            {
                ver.push_back(ret);

                ret = 0;
            }
            else
            {
                ret = 10 * ret + (version[l] - '0');
            }
            l++;
        }
        if (ret != 0)
            ver.push_back(ret);

        return ver;
    }
    int compareVersion(string version1, string version2)
    {
        //

        vector<int> ver1 = make(version1);
        vector<int> ver2 = make(version2);
        int l = 0, r = 0;
        while (l < ver1.size() && r < ver2.size())
        {

            if (ver1[l] == ver2[r])
            {
                l++;
                r++;
            }
            else if (ver1[l] > ver2[r])
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }

        while (l < ver1.size())
        {
            if (ver1[l] == 0)
                l++;
            else
                return 1;
        }
        while (r < ver2.size())
        {
            if (ver2[r] == 0)
                r++;
            else
                return -1;
        }
        return 0;
    }
};