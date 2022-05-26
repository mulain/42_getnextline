/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 21:46:37 by wmardin           #+#    #+#             */
/*   Updated: 2022/05/26 19:23:25 by wmardin          ###   ########.fr       */
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
		if (ft_findnewline(line) != -1)
			return (ft_makeremainder_returnoutput(line, remainder, fd));
	}
	readeru = read(fd, readbuffer, BUFFER_SIZE);
	while (readeru > 0)
	{
		readbuffer[readeru] = 0;
		line = ft_appendbuffertoline(line, readbuffer);
		if (ft_findnewline(line) != -1)
			return (ft_makeremainder_returnoutput(line, remainder, fd));
		readeru = read(fd, readbuffer, BUFFER_SIZE);
	}
	return (line);
}

/*
- Searches for \n
- If found, returns index of \n
- If not found returns 0
*/

int	ft_findnewline(const char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

/*
just good ole ft_strlen
*/

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *source)
{
	int		i;
	char	*output;

	i = 0;
	output = malloc((ft_strlen(source) + 1) * sizeof(char));
	while (source[i])
	{
		output[i] = source[i];
		i++;
	}
	output[i] = 0;
	return (output);
}

/* int	main(void)
{
	int		fd;
	char	*str;
	int		i;

	i = 0;
	fd = open("test0.txt", O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		printf("i=%d, str:%s", i, str);
		free(str);
		str = get_next_line(fd);
		i++;
	}
	printf("'");
} */
