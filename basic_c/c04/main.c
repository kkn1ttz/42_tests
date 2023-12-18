#include <stdio.h>

int		ft_strlen(char *str);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
int		ft_atoi(char *str);

int	main(int argc, char **argv)
{
	if (argc < 1 && !argv[0])
		return (0);

	// printf("ft_strlen: %i\n", ft_strlen(argv[1]));
	
	// ft_putstr(argv[1]);

	//int	nb = -2147483648;
	//ft_putnbr(nb);

	printf("str: %s, ft_atoi: %i\n", argv[1], ft_atoi(argv[1]));
	return (1);
}
