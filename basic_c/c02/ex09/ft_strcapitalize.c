/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzahirho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:31:12 by zzahirho          #+#    #+#             */
/*   Updated: 2023/12/07 15:55:02 by zzahirho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_lowercase(char c)
{
	if (c < 'a' || c > 'z')
		return (0);
	return (1);
}

int	is_alpha_numeric(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	ft_strupcase(char c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 6 - 26;
	return (c);
}

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 6 + 26;
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	str = ft_strlowcase(str);
	i = 0;
	while (str[i] != '\0')
	{
		if (is_lowercase(str[i]) == 1)
		{
			if (is_alpha_numeric(str[i - 1]) == 0)
			{
				str[i] = ft_strupcase(str[i]);
			}
		}
		i++;
	}
	return (str);
}
/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	printf("%s\n", argv[1]);
	printf("%s", ft_strcapitalize(argv[1]));
}
*/