
void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
bool isAlpha(char *c)
{
    if (*c - 'a' >= 0 && *c - 'a' < 26)
        return true;
    if (*c - 'A' >= 0 && *c - 'A' < 26)
        return true;
    return false;
}
char *reverseOnlyLetters(char *s)
{

    int l = 0, r = strlen(s) - 1;
    while (l < r)
    {

        while (l < r && !isAlpha(&s[l]))
            l++;
        while (l < r && !isAlpha(&s[r]))
            r--;
        if (isAlpha(&s[l]) && isAlpha(&s[r]))
        {
            swap(&s[l], &s[r]);
            l++;
            r--;
        }
    }
    return s;
}