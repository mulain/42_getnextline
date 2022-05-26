/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 21:46:37 by wmardin           #+#    #+#             */
/*   Updated: 2022/05/26 15:31:42 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ssize_t read(int fildes, void *buf, size_t nbyte);
return of read
If the starting position is at or after the end-of-file, 0 shall be returned. 
Upon successful completion, read() and pread() shall return a
non-negative integer indicating the number of bytes actually read.
Otherwise, the functions shall return -1 and set errno to indicate the error.

*/
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*remainder[1024];
	char		readbuffer[BUFFER_SIZE + 1];
	char		*line;
	int			readeru;
	
	if (read(fd, NULL, 0) || BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	if (remainder[fd])
	{
		line = ft_remainderintoline(remainder, fd);
		if (ft_findnewline(line))
			return (ft_makeremainder_returnoutput(line, remainder, fd));
	}
	readeru = read(fd, readbuffer, BUFFER_SIZE);
	while (readeru > 0)
	{
		readbuffer[readeru] = 0;
		line = ft_appendbuffertoline(line, readbuffer);
		if (ft_findnewline(line))
			return (ft_makeremainder_returnoutput(line, remainder, fd));
		readeru = read(fd, readbuffer, BUFFER_SIZE);
	}
	return (line);
}
/* 
int	main(void)
{
	int		fd;
	char	*str;

	fd = open("test0.txt", O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		printf("%s", str);
		free(str);
		str = get_next_line(fd);
	}
	printf("'");
}
 */