#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	**extrac_sides(char *input)
{
	int	i;
	int	u;
	int row;
	int	**sides;

	i = 0;
	u = 0;
	row = 0;
	sides = malloc(sizeof(int*) * 4);
	sides[row] = malloc(sizeof(int) * 4);
	while (input[i] != '\0')
	{
		if (u == 4)
		{
			u = 0;
			row++;
			sides[row] = malloc(sizeof(int) * 4);
		}
		if (input[i] != ' ')
		{
			sides[row][u] = input[i] - '0';
			u++;
		}
		i++;
	}
	return (sides);
}

int	ft_strlen(char *str)
{
	int size;

	size = 0;
	while(str[size] != '\0')
	{
		size++;
	}
	return size;
}

int	check_input_numbers(char *input)
{
	int	i;

	if (input[0] < '1' || input[0] > '4')
		return (0);
	i = 2;
	while(input[i] != '\0')
	{
		if (input[i] < '1' || input[i] > '4')
		{
			return (0);
		}
		if (input[i - 1] != ' ')
			return (0);
		i = i + 2;
	}
	return (1);
}

int	count_num_repeat(int *side, int num)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while(side[i] != '\0')
	{
		if (side[i] == num && side[i] != 2)
		{
			count ++;
		}
		i++;
	}
	if (num == 3 && count < 3)
		return (1);
	return (count);
}

int	check_sides_num_repeat(char *input)
{
	int	side;
	int	i;
	int **input_int;

	input_int = extrac_sides(input);
	side = 0;
	while(side < 4)
	{
		i = 0;
		while (input_int[side][i] != '\0')
		{
			if(input_int[side][i] != 2)
			{
				if (count_num_repeat(input_int[side], input_int[side][i]) > 1)
					return (0);
			}
			i++;
		}
		side++;
	}
	return (1);
}

int check_input_error(char *input)
{
	if (ft_strlen(input) != 31)
		return (0);
	if (check_input_numbers(input) == 0)
		return (0);
	if (check_sides_num_repeat(input) == 0)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc < 1 || check_input_error(argv[1]) == 0)
	{
		write(1, "Error\n", 6);
	}
	// for(int i=0;i<4;i++)
	// {
	// 	for(int u=0;u<4;u++)
	// 	{
			// printf("\n%i ", check_input_error(input));
	// 	}
	// 	printf("\n");
	// }
	return 0;
}
