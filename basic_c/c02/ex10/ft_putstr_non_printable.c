int    ft_strlen(char *str)
{
    int i;

    i = 0;
    while(str[i] != '\0')
    {
        i++;
    }
    return i;
}

void ft_putstr_non_printable(char *str)
{
    char    *hex_map[] = "0123456789ABCDEF";
    char    *hex_value[] = "\\";
    hex_value[1] = hex_map[str[0]];
    hex_value[2] = '\0';

    hex_value[1] = hex_map[str[0]];
    hex_value[1] = hex_map[str[0]];
    hex_value[2] = '\0';
    return (hex_value);
}