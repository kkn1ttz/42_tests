/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_nb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzahirho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:57:28 by zzahirho          #+#    #+#             */
/*   Updated: 2023/12/17 15:02:56 by zzahirho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*rev_tab(char *nb)
{
	int		i;
	int		j;
	int		len;
	char	*result;

	len = ft_strlen(nb);
	result = malloc(len);
	i = 0;
	j = len - 1;
	while (i < len)
	{
		result[i] = nb[j];
		i++;
		j--;
	}
	result[len] = '\0';
	return (result);
}

char* ft_strncpy(char* dest, char* src, int start, int n)
{
	int		i;
	int		j;
    char	*originalDest;

	originalDest = dest;
	i = 0;
	j = start;
    while (i < n && src[j] != '\0')
	{
		dest[i] = src[j];
        i++;
		j++;
    }
    while (i < n) {
        dest[i] = '\0';
		i++;
    }
	dest[n] = '\0';
    return originalDest;
}

char	*append_zeros(int index)
{
	int		i;
	char	*result;

	result = malloc (index + 1);
	result[0] = '1';
	i = 1;
	while (i <= index)
	{
		result[i] = '0';
		i++;
	}
	result[index + 1] = '\0';
	return (result);
}

int	ft_strstr(char *buff, char *to_find, int start)
{
	int	i;
	int	j;

	i = 0;
	j = start;
	while (buff[j] == to_find[i])
	{
		if (buff[j + 1] == ':' || buff[j + 1] == ' ')
		{
			if (to_find[i + 1] == '\0')
				return (1);
		}
		i++;
		j++;
	}
	return (0);
}