

bool canConstruct(char *ransomNote, char *magazine)
{

    int *dict = calloc(26, sizeof(int));
    for (int i = 0; magazine[i] != '\0'; ++i)
    {
        dict[magazine[i] - 'a']++;
    }
    for (int i = 0; ransomNote[i] != '\0'; ++i)
    {
        if (dict[ransomNote[i] - 'a'] == 0)
            return false;
        dict[ransomNote[i] - 'a']--;
    }
    return true;
}