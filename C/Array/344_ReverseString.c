
void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
void reverseString(char *s, int sSize)
{
    int l = 0, r = sSize - 1;
    while (l < r)
    {
        swap(&s[l++], &s[r--]);
    }
}