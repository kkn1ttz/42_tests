#include <stdio.h>
#include <stdlib.h>

int ft_str_is_alpha(char *str) {
    int i;

    if (str == NULL)
        return 1;
    i = 0;
    while (str[i] != '\0')
    {
        if ((str[i] < 'A' || str[i] > 'Z') && (str[i] < 'a' || str[i] > 'z'))
            return (0);
        i++;
    }
    return (1);
}

int main(void)
{
    char    *str = malloc(5);
    printf("%s", str);
    printf("\n");
    printf("%i", ft_str_is_alpha(str));
    printf("\n");

    int i = 9;
    // while (str[i] == '\0')
    // {
    //     printf("str[%i]: %c\n", i, str[i]);
    //     i++;
    // }{
        printf("%i", (int)str[i]);
    // }
    free(str);
}