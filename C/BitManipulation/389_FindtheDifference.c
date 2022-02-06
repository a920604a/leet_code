

char findTheDifference(char *s, char *t)
{
    int ret = 0;
    for (int i = 0; t[i] != '\0'; ++i)
        ret += (t[i] - 'a');
    for (int i = 0; s[i] != '\0'; ++i)
        ret -= (s[i] - 'a');
    return (char)(ret + 'a');
}