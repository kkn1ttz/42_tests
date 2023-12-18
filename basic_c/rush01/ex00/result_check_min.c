/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result_check_min.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agizy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 20:47:54 by agizy             #+#    #+#             */
/*   Updated: 2023/12/10 20:47:57 by agizy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*rev_int_tab(int *tab_rev_right_to_left)
{
	int	*tab_rev;

	tab_rev = malloc(sizeof(int) * 4);
	tab_rev[0] = tab_rev_right_to_left[3];
	tab_rev[1] = tab_rev_right_to_left[2];
	tab_rev[2] = tab_rev_right_to_left[1];
	tab_rev[3] = tab_rev_right_to_left[0];
	return (tab_rev);
}

int	left_to_right_check(int *line, int nbr_buildings)
{
	int	count;
	int	i;
	int	ref;

	count = 1;
	i = 0;
	ref = line[i];
	while (i < 3)
	{
		if (line[i + 1] - line[i] > 0)
		{
			if (ref != 4)
			{
				count++;
				ref = line[i + 1];
			}
		}
		i++;
	}
	if (count == nbr_buildings)
		return (1);
	else
		return (0);
}

int	right_to_left_check(int *line, int nbr_buildings)
{
	int	*rev_line;
	int	check;

	rev_line = rev_int_tab(line);
	check = left_to_right_check(rev_line, nbr_buildings);
	return (check);
}

int	up_to_down_check(int **results, int col, int nbr_buildings)
{
	int	count;
	int	i;
	int	ref;

	count = 1;
	i = 0;
	ref = results[i][col];
	while (i < 3)
	{
		if (results[i + 1][col] - results[i][col] > 0)
		{
			if (ref != 4)
			{
				count++;
				ref = results[i + 1][col];
			}
		}
		i++;
	}
	if (count == nbr_buildings)
		return (1);
	return (0);
}

int	down_to_up_check(int **results, int col, int nbr_buildings)
{
	int	count;
	int	i;
	int	ref;

	count = 1;
	i = 3;
	ref = results[i][col];
	while (i > 0)
	{
		if (results[i - 1][col] - results[i][col] > 0)
		{
			if (ref != 4)
			{
				count++;
				ref = results[i - 1][col];
			}
		}
		i--;
	}
	if (count == nbr_buildings)
		return (1);
	return (0);
}