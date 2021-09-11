

int firstUniqChar(char *s)
{
    //
    int *ret = calloc(26, sizeof(int));
    ;
    for (int i = 0; *(s + i) != '\0'; ++i)
    {
        ret[s[i] - 'a']++;
    }
    for (int i = 0; *(s + i) != '\0'; ++i)
    {
        if (ret[s[i] - 'a'] == 1)
            return i;
    }
    return -1;
}