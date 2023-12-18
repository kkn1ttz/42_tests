/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_error_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agizy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 20:20:47 by agizy             #+#    #+#             */
/*   Updated: 2023/12/10 21:24:56 by agizy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_input_numbers(char *input);
int	check_sides_num_repeat(int **input_int);
int	check_opposites(int **input_int);
int	**initialize_sides(void)
{
	int	**sides;
	int	row;

	row = 0;
	sides = malloc(sizeof (int *) * 4);
	while (row < 4)
	{
		sides[row] = malloc (sizeof (int) * 4);
		row++;
	}
	return (sides);
}

int	**extrac_sides(char *input)
{
	int	i;
	int	u;
	int	row;
	int	**sides;

	i = 0;
	u = 0;
	row = 0;
	sides = initialize_sides();
	while (input[i] != '\0')
	{
		if (u == 4)
		{
			u = 0;
			row++;
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
	int	size;

	size = 0;
	while (str[size] != '\0')
	{
		size++;
	}
	return (size);
}

int	input_error_check(char *input)
{
	int	**input_int;

	input_int = extrac_sides(input);
	if (ft_strlen(input) != 31)
		return (0);
	if (check_input_numbers(input) == 0)
		return (0);
	if (check_sides_num_repeat(input_int) == 0)
		return (0);
	if (check_opposites(input_int) == 0)
	{
		return (0);
	}
	return (1);
}
