

char *toHex(int num)
{
    char dec2hex[] = "0123456789abcdef";
    char *ret = calloc(9, sizeof(char));
    char *p = ret + 8;
    unsigned int x = num;
    while (ret != p)
    {
        *(--p) = (dec2hex[x % 16]);
        x >>= 4;
    }
    while (*p == '0' && *(p + 1) != '\0')
        p++;
    return p;
}