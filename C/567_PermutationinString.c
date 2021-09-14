

bool checkInclusion(char *s1, char *s2)
{

    int *window = calloc(26, sizeof(int));
    int *dict = calloc(26, sizeof(int));
    int n = strlen(s2), m = strlen(s1);
    for (int i = 0; i < m; ++i)
        dict[s1[i] - 'a']++;
    for (int i = 0; i < n; ++i)
    {
        window[s2[i] - 'a']++;
        if (i >= m)
            window[s2[i - m] - 'a']--;

        bool ret = true;
        for (int j = 0; j < 26; ++j)
        {
            if (window[j] != dict[j])
            {
                ret = false;
                break;
            }
        }
        if (ret)
            return true;
    }
    return false;
}