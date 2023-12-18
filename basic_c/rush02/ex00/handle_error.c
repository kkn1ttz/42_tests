#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *str);

int is_numeric(char *str)
{
    int i;

    i = 0;
    while (str[i])
	{
		if (str[i] < '0' && str[i] > '9')
			return (0);
		i++;
	}
    return (1);
}

int check_dicterror(char *buff, int error)
{
    if (error == -1)
    {
        write(1, "Dict Error\n", 11);
        free(buff);
        return (-1);
    }
    free(buff);
    return (1);
}

int	check_input_error(char *str)
{
	if (is_numeric(str) == 0)
	{
        return (0);
    }
    else if (ft_strlen(str) > 1 && str[0] == '0')
    {
        return (0);
    }
	return (1);
}

void    check_error_code(int error_code)
{
    if (error_code == -1)
        write(1, "Error\n", 6);
    else if (error_code == -2)
        write(1, "Dict Error\n", 11);
}