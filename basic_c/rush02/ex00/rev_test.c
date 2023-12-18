#include <stdio.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_atoi(char *str);

/*=============================================*/

int	open_file(char *path)
{
	int	fd;
	
	fd = open(path, O_RDONLY);
	return (fd);
}

/*=============================================*/

int	close_file(int fd)
{
	return (close(fd));
}

/*=============================================*/

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	*read_file(int fd)
{
	char	*buff;
	int		read_status;

	buff = malloc(1024);
	read_status = read(fd, buff, 1024);
	return(buff);
}

/*=============================================*/

int ft_strstr(char *buff, char *to_find, int start)
{
	int	i;
	int	j;

	i = 0;
	j = start;
	while(buff[j] == to_find[i])
	{
		if(buff[j + 1] == ':' || buff[j + 1] == ' ')
		{
			if(to_find[i + 1] == '\0')
				return (1);
		}
		i++;
		j++;
	}
	return (0);
}

/*=============================================*/

void	print_found(char *buff, int start)
{
	int	i;

	i = start;
	while(buff[i] != ':' && buff[i] != ' ')
		i++;
	i++;
	while(buff[i] == ' ')
		i++;
	while(buff[i] != '\n')
	{
		ft_putchar(buff[i]);
		i++;
	}
	ft_putchar(' ');
}

/*=============================================*/

int	search_file(char *buff, char *to_find)
{
	int 	i;
	int		start;

	i = 0;
	start = i;
	if(ft_strstr(buff, to_find, start) != 0)
		return (start);
	while (buff[i])
	{
		if (buff[i] == '\n')
		{
			if(ft_strstr(buff, to_find, start) != 0)
				return (start);
			start = i + 1;
		}
		i++;
	}
	return (0);
}
/*=============================================*/

void	ft_rev_char_tab(char *tab, int size)
{
	int	i;
	int	temp;

	i = 0;
	while (i < size)
	{
		temp = tab[i];
		tab[i] = tab[size - 1];
		tab[size - 1] = temp;
		i++;
		size--;
	}
}

/*=============================================*/

int ft_strlen(char *str)
{
	int i = 0;

	while(str[i] != '\0')
		i++;
	return (i);
}

/*=============================================*/

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

/*=============================================*/

char	*ft_strdup(char *src)
{
	int	i;
	int j;
	char	*dest;

	i = 0;
	j = 0;
	if (*src == '\0')
		return (0);
	while (src[i] != '\0')
		i++;
	if(!(dest = malloc(sizeof(src) * i)))
		return (0);
	while (j < i)
	{
		dest[j] = src[j];
		j++;
	}
	//dest[j] = '\0';
	return (dest);
}
/*=============================================*/

char	*append_zeros(int index)
{
	int		i;
	char	*resu;

	resu = malloc (index + 1);
	resu[0] = '1';
	i = 1;
	while (i <= index)
	{
		resu[i] = '0';
		i++;
	}
	return (resu);
}

/*=============================================*/

int zero(char *src, int fd, char *buff)
{
	int size;
	int i = 1;
	int pos;
	char *temp;
	long long nb;

	nb = ft_atoi(src);
	fd = open_file("numbers.dict");
	buff = read_file(fd);
	pos = search_file(buff, src);
	temp = malloc(size); 
	temp[0] = src[0];
	char *temp2;

	size = ft_strlen(src);
	if(nb < 20 || nb % 10 == 0)
		print_found(buff, pos);
	else if (nb < 100)
	{
		temp = ft_strcat(temp, "0");
		print_found(buff, search_file(buff, temp));
		print_found(buff, search_file(buff, &src[1]));
	}
	else if(nb > 100 && nb < 1000)
	{
		
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
	else if(nb > 999)
	{
		print_found(buff, search_file(buff, temp));
		print_found(buff, search_file(buff, "1000"));
		if(src[1] == '0' && src[2] == '0')
			print_found(buff, search_file(buff, &src[3]));
		if(src[1] == '0' && src[2] == '1')
		{	
			temp2 = malloc(size);
			temp2[0] = '1';
			temp2 = ft_strcat(temp2, &src[3]);
			print_found(buff, search_file(buff, temp2));
		}
		if(src[1] >= '1')
		{
			temp[0] = src[1];
			print_found(buff, search_file(buff, temp));
                 	print_found(buff, search_file(buff, "100"));
                 	if (src[2] == '0')
                		print_found(buff, search_file(buff, &src[2]));
                 	else if(src[2] == '1')
                 	{
                         	temp2 = malloc(size);
                         	temp2[0] = '1';
                         	temp2 = ft_strcat(temp2, &src[3]);
                        	print_found(buff, search_file(buff, temp2));
                 	}
                 	else
                  	{
                         	temp[0] = src[2];
                        	temp = ft_strcat(temp, "0");
                         	print_found(buff, search_file(buff, temp));
                         	print_found(buff, search_file(buff, &src[3]));
                 	}
		}	
			
	}

	return 0;
}



/*=============================================*/


int main(int argc, char **argv)
{
	if (argc < 1)
		return 0;
	else
	{
		int fd;
		char *buff;
		char *sto;
		//sto = ft_strdup();
		fd = open_file("numbers.dict");
		buff = read_file(fd);
		zero(argv[1], fd, buff);
		fd = open_file("numbers.dict");


		return (1);

		
	}
	return 0;
}

/*
//printf("%d", fd);
		char *temp1 = malloc(1);
			temp1[0] = argv[1][0];
		char *temp2 = malloc(1);
			temp2[0] = argv[1][1];

		char *temp3 = malloc(1);
			temp3[0] = argv[1][2];
		char *temp4 = malloc(1);
			temp4[0] = argv[1][3];
		char *temp5 = malloc(1);
			temp5[0] = argv[1][4];
		char *temp;

		if (size == 5)
			temp = ft_strcat(temp1, "0");
		search_file(fd, temp);
		write(1, "-", 1);
		fd = open_file("numbers.dict");
		search_file(fd, temp2);

		fd = open_file("numbers.dict");
		search_file(fd, "1000");

		fd = open_file("numbers.dict");
		search_file(fd, temp3);

		fd = open_file("numbers.dict");
		search_file(fd, "100");

		fd = open_file("numbers.dict");
		temp4 = ft_strcat(temp4, "0");
		search_file(fd, temp4);
		fd = open_file("numbers.dict");
		search_file(fd, temp5);

*/
