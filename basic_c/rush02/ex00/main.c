/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzahirho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 12:15:18 by zzahirho          #+#    #+#             */
/*   Updated: 2023/12/17 17:26:40 by zzahirho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int		open_file(char *path);
int     read_file(int fd, char *buff);
int		close_file(int fd);
int     check_error(char *str);
int     check_dicterror(char *buff, int error);
int		ft_strlen(char *str);
char	*rev_tab(char *nb);
char*   ft_strncpy(char* dest, char* src, int start, int n);
int     ft_strstr(char *buff, char *to_find, int start);
char	*append_zeros(int index);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	print_found(char *buff, int start)
{
	int	i;

    if (start == -1)
    {
        return (-1);
    }
	i = start;
	while (buff[i] != ':' && buff[i] != ' ')
		i++;
	i++;
	while (buff[i] == ' ')
		i++;
	while (buff[i] != '\n')
	{
		ft_putchar(buff[i]);
		i++;
	}
    return (1);
}

int	search_file(char *buff, char *to_find)
{
	int		i;
	int		start;

	i = 0;
	start = i;
	if (ft_strstr(buff, to_find, start) != 0)
		return (start);
	while (buff[i])
	{
		if (buff[i] == '\n')
		{
			if (ft_strstr(buff, to_find, start) != 0)
				return (start);
			start = i + 1;
		}
		i++;
	}
	return (-1);
}

int	ft_isnbr(char *c, int i, int j)
{
	int	res;
	int	test;

	res = 0;
	test = 0;
	while (c[i] >= '0' && c[i] <= '9')
	{
		res = (res * 10) + (c[i] - '0');
		i++;
	}
	test = j % 2;
	if (test != 0)
		res *= -1;
	return (res);
}

int	ft_atoi(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	return (ft_isnbr(str, i, j));
}

char	*ft_strcat(char *dest, char *src)
{
	int	size_dest;
	int	i;

	size_dest = ft_strlen(dest);
	i = 0;
	while (*(src + i) != '\0')
	{
		dest[size_dest + i] = src[i];
		i++;
	}
	dest[size_dest + i] = '\0';
	return (dest);
}

void handle_under_1000(char *src, char *buff)
{
	int     nb;
    int     size;
	char    *temp;
	char    *temp2;

	nb = ft_atoi(src);
	size = ft_strlen(src);
	temp = malloc(size);
	temp[0] = src[0];
    printf("nb: %i, src:%s\n", nb, src);
	if(nb < 20 || nb % 10 == 0)
		print_found(buff, search_file(buff, src));
	else if (nb < 100)
	{
		temp = ft_strcat(temp, "0");
		print_found(buff, search_file(buff, temp));
		print_found(buff, search_file(buff, &src[1]));
	}
	else if(nb >= 100 && nb < 1000)
	{
        printf("temp: %s\n",temp);
		print_found(buff, search_file(buff, temp));
		print_found(buff, search_file(buff, "100"));
		if (src[1] == '0')	
			print_found(buff, search_file(buff, &src[2]));
		else if(src[1] == '1')
		{
			temp2 = malloc(size);
			temp2[0] = '1';
			temp2 = ft_strcat(temp2, &src[2]);
			print_found(buff, search_file(buff, temp2));
		}
		else
		{
			temp[0] = src[1];
			temp = ft_strcat(temp, "0");
			print_found(buff, search_file(buff, temp));
			print_found(buff, search_file(buff, &src[2]));
		}
	}
}

int	rush02(char *buff, char *nb)
{
    int     i;
    int     j;
    int     len;
    char    *to_find;
    int     iteration;
    int     excess;

    len = ft_strlen(nb);
    excess = len % 3;
    iteration = len / 3;
    i = 3 * iteration;
    j = 0;
    if (excess > 0 && len > 3)
    {
        to_find = malloc(excess);
        ft_strncpy(to_find, nb, j, excess);
        handle_under_1000(to_find, buff);
        if (iteration > 0)
            print_found(buff, search_file(buff, append_zeros(i)));
        iteration--;
        i = i - 3;
        j = j + 3;
    }
    while (i >= 0)
    {
        to_find = malloc(3);
        ft_strncpy(to_find, nb, j, 3);
        handle_under_1000(to_find, buff);
        if (iteration > 0)
            print_found(buff, search_file(buff, append_zeros(i)));
        iteration--;
        i = i - 3;
        j = j + 3;
    }
    return (1);
}

int	main(int argc, char **argv)
{
	int     fd;
    char    *buff;

    if (argc == 2)
    {
        fd = open_file("numbers.dict");
        buff = malloc(1024);
        read(fd, buff, 1024);
        if(rush02(buff, argv[1]) == 1)
            return (1);
        free(buff);
        close(fd);
    }
    else if (argc == 3)
    {
        fd = open_file(argv[1]);
        buff = malloc(1024);
        read(fd, buff, 1024);
        if(rush02(buff, argv[2]) == 1)
            return (1);
        free(buff);
        close(fd);
    }
    write(1, "Error\n", 6);
}
