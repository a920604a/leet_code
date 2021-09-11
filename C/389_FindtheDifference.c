

char findTheDifference(char *s, char *t)
{

    // 每個字母代表一個數字
    int ret = 0;
    for (int i = 0; s[i] != '\0'; ++i)
    {
        ret ^= (s[i] - 'a');
    }

    for (int i = 0; t[i] != '\0'; ++i)
    {
        ret ^= (t[i] - 'a');
    }
    return (char)(ret + 'a');
}