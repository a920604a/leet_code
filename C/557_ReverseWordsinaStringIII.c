void swap(char *s, char *t)
{
    char temp = *s;
    *s = *t;
    *t = temp;
}
void reverse(char *s, int l, int r)
{
    while (l < r)
        swap(&s[l++], &s[r--]);
}

char *reverseWords(char *s)
{

    int len = strlen(s);
    int p = 0;
    while (*(s + p) == ' ')
        p++;
    for (int i = 0; i < len; ++i)
    {
        if (*(s + i) == ' ')
        {
            reverse(s, p, i - 1);
            while (*(s + i) == ' ')
                i++;
            p = i;
        }
    }
    reverse(s, p, len - 1);
    return s;
}