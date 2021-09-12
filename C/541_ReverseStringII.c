#define min(a, b) ((a < b) ? a : b)
void swap(char *s, char *t)
{
    char temp = *s;
    *s = *t;
    *t = temp;
}
void reverse(char *s, int l, int r)
{
    while (l < r)
    {
        swap(&s[l++], &s[r--]);
    }
}
char *reverseStr(char *s, int k)
{
    if (k == 1)
        return s;
    int len = strlen(s);
    for (int i = 0; i < len; i += 2 * k)
    {
        reverse(s, i, min(i + k - 1, len - 1));
    }
    return s;
}