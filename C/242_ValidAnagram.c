

bool isAnagram(char *s, char *t)
{

    int *dict = calloc(26, sizeof(int));
    int m = strlen(t), n = strlen(s);
    for (int i = 0; i < m; ++i)
        dict[t[i] - 'a']++;
    for (int i = 0; i < n; ++i)
        dict[s[i] - 'a']--;
    for (int i = 0; i < 26; ++i)
    {
        if (dict[i] != 0)
            return false;
    }
    return true;
}