char    *ft_strncpy(char *dest, char *src, unsigned int n)
{
    int i;

    i = 0;
    while (src[i] != '\0' || (unsigned int)i < n)
    {
        dest[i] = src[i];
        i++;
    }
    while ((unsigned int)i < n)
    {
        dest[i] = '\0';
        i++;
    }
    return (dest);
}