/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agizy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 00:02:53 by agizy             #+#    #+#             */
/*   Updated: 2023/12/10 20:18:53 by agizy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	left_to_right_check(int *line, int nbr_buildings);
int	right_to_left_check(int *line, int nbr_buildings);
int	up_to_down_check(int **results, int col, int nbr_buildings);
int	down_to_up_check(int **results, int col, int nbr_buildings);
int	lines_check(int **results, int **inputs)
{
	int	row;
	int	side;

	row = 0;
	side = 2;
	while (row < 4)
	{
		if (left_to_right_check(results[row], inputs[side][row]) == 0)
			return (0);
		else if (right_to_left_check(results[row], inputs[side + 1][row]) == 0)
			return (0);
		row++;
	}
	return (1);
}

int	cols_check(int **results, int **inputs)
{
	int	col;
	int	side;

	col = 0;
	side = 0;
	while (col < 4)
	{
		if (up_to_down_check(results, col, inputs[side][col]) == 0)
			return (0);
		else if (down_to_up_check(results, col, inputs[side + 1][col]) == 0)
			return (0);
		col++;
	}
	return (1);
}

int	result_check(int **results, int **inputs)
{
	if (cols_check(results, inputs) == 0)
		return (0);
	else if (lines_check(results, inputs) == 0)
		return (0);
	return (1);
}
