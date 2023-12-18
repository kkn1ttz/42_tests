/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_error_check_min.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agizy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 21:04:25 by agizy             #+#    #+#             */
/*   Updated: 2023/12/10 21:22:54 by agizy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_input_numbers(char *input)
{
	int	i;

	if (input[0] < '1' || input[0] > '4')
		return (0);
	i = 2;
	while (input[i] != '\0')
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
	while (side[i] != '\0')
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

int	check_sides_num_repeat(int **input_int)
{
	int	side;
	int	i;

	side = 0;
	while (side < 4)
	{
		i = 0;
		while (input_int[side][i] != '\0')
		{
			if (input_int[side][i] != 2)
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

int	check_opposites(int **input_int)
{
	int	side;
	int	col;
	int	i;

	side = 0;
	i = 0;
	while (i < 2)
	{
		col = 0;
		while (col < 4)
		{
			if (input_int[side][col] == 4 && input_int[side + 1][col] != 1)
				return (0);
			if (input_int[side][col] == 3 && input_int[side + 1][col] > 2)
				return (0);
			if (input_int[side][col] == 2 && input_int[side + 1][col] > 3)
				return (0);
			if (input_int[side][col] == 1 && input_int[side + 1][col] < 2)
				return (0);
			col++;
		}
		i++;
		side = side + 2;
	}
	return (1);
}
