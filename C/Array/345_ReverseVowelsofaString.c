
void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
bool isVowel(char c)
{
    if ((c == 'A' || c == 'a') ||
        (c == 'E' || c == 'e') ||
        (c == 'I' || c == 'i') ||
        (c == 'O' || c == 'o') ||
        (c == 'U' || c == 'u'))
        return true;

    return false;
}

char *reverseVowels(char *s)
{
    int l = 0, r = 0;
    for (int i = 0; s[i] != '\0'; ++i)
        r++;
    r--;

    while (l < r)
    {
        while (l < r && !isVowel(s[l]))
            l++;
        while (l < r && !isVowel(s[r]))
            r--;
        swap(&s[l++], &s[r--]);
    }
    return s;
}