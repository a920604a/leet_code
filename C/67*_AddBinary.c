#define max(a, b) ((a > b) ? a : b)

char *addBinary(char *a, char *b)
{
    int carry = 0;
    int i = strlen(a), j = strlen(b);
    int k = max(i, j) + 2;
    char *ret = calloc(k, sizeof(char));
    i--;
    j--;
    ret[--k] = '\0';
    while (i >= 0 || j >= 0)
    {
        int sum = carry;
        if (i >= 0)
            sum += (a[i--] - '0');
        if (j >= 0)
            sum += (b[j--] - '0');

        carry = sum / 2;
        ret[--k] = sum % 2 + '0';
    }
    if (carry)
    {
        ret[0] = '1';
        return ret;
    }
    else
        return ret + 1;
}