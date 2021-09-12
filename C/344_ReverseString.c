
void swap(char *s, char *t)
{
    char temp = *s;
    *s = *t;
    *t = temp;
}
void reverseString(char *s, int sSize)
{
    int l = 0, r = sSize - 1;
    while (l < r)
    {
        swap(&s[l], &s[r]); //swap(&*(s+l), &*(s+r));
        l++;
        r--;
    }
}