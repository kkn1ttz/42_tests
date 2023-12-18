/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzahirho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 12:19:37 by zzahirho          #+#    #+#             */
/*   Updated: 2023/12/17 12:30:40 by zzahirho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int	open_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	return (fd);
}

int	read_file(int fd, char *buff)
{
	int		read_status;

	buff = malloc(1024);
	read_status = read(fd, buff, 1024);
	return (read_status);
}

int	close_file(int fd)
{
	return (close(fd));
}
