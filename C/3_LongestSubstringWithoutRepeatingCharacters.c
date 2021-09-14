#define max(a, b) ((a > b) ? a : b)

int lengthOfLongestSubstring(char *s)
{
    int *window = calloc(128, sizeof(int));
    int n = strlen(s);
    int l = 0, r = 0, ret = 0;
    while (r < n)
    {
        char c = s[r++];
        window[c]++;

        while (window[c] > 1)
        {
            char d = s[l++];
            window[d]--;
        }
        ret = max(r - l, ret);
    }
    return ret;
}