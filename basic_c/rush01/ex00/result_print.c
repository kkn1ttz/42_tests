/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agizy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 22:22:50 by agizy             #+#    #+#             */
/*   Updated: 2023/12/10 22:27:48 by agizy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	**initialize_results(void)
{
	int	**results;
	int	row;
	int	col;

	row = 0;
	results = malloc(sizeof (int *) * 4);
	while (row < 4)
	{
		results[row] = malloc(sizeof(int) * 4);
		col = 0;
		while (col < 4)
		{
			results[row][col] = 0;
			col ++;
		}
		row ++;
	}
	return (results);
}

void	result_print(int **tab)
{
	int	row;
	int	col;
	char	temp;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			temp = tab[row][col] + '0';
			write(1, &temp, 1);
			if (col < 3)
				write(1, " ", 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}
