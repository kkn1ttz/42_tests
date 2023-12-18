/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result_errors_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frazafin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 10:28:56 by frazafin          #+#    #+#             */
/*   Updated: 2023/12/10 20:14:48 by agizy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	line_error_check(int *tab)
{
	int	count;
	int	nbr;
	int	i;
	int	u;

	i = 0;
	while (i < 4)
	{
		nbr = tab[i];
		count = 0;
		u = 0;
		while (u < 4)
		{
			if (tab[u] == nbr)
			{
				count++;
				if (count > 1)
					return (0);
			}
			u++;
		}
		i++;
	}
	return (1);
}

int	col_error_check(int **results, int col)
{
	int	count;
	int	nbr;
	int	i;
	int	row;

	i = 0;
	while (i < 4)
	{
		nbr = results[i][col];
		count = 0;
		row = 0;
		while (row < 4)
		{
			if (results[row][col] == nbr)
			{
				count++;
				if (count > 1)
					return (0);
			}
			row++;
		}
		i++;
	}
	return (1);
}

int	lines_error_check(int **results)
{
	int	row;

	row = 0;
	while (row < 4)
	{
		if (line_error_check(results[row]) == 0)
			return (0);
		row++;
	}
	return (1);
}

int	cols_error_check(int **results)
{
	int	col;

	col = 0;
	while (col < 4)
	{
		if (col_error_check(results, col) == 0)
			return (0);
		col++;
	}
	return (1);
}

int	result_errors_check(int **results)
{
	if (cols_error_check(results) == 0 || lines_error_check(results) == 0)
		return (0);
	return (1);
}
