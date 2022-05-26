/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 08:24:53 by wmardin           #+#    #+#             */
/*   Updated: 2022/05/22 08:24:53 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
- Appends the readbuffer to line
- If line is NULL, returns only the content of the readbuffer.
- Readbuffer is not directly returned, because the return might
	later be freed which would not work with the non-heap
	allocated readbuffer address
Free line if line NULL case? use line instead of output?
*/

char	*ft_appendbuffertoline(char *line, char *readbuffer)
{
	int		i;
	int		len_readbuffer;
	int		len_line;
	char	*output;

	i = 0;
	len_readbuffer = ft_strlen(readbuffer);
	if (!line)
	{
		output = malloc((len_readbuffer + 1) * sizeof(char));
		while (readbuffer[i])
		{
			output[i] = readbuffer[i];
			i++;
		}
		output[i] = 0;
		return (output);
	}
	len_line = ft_strlen(line);
	output = malloc((len_line + len_readbuffer + 1) * sizeof(char));
	while (line[i])
	{
		output[i] = line[i];
		i++;
	}
	while (readbuffer[i - len_line])
	{
		output[i] = readbuffer[i - len_line];
		i++;
	}
	output[i] = 0;
	free(line);
	return (output);
}

/*
- Transfers the remainder into line
- NULLs the remainder so it won't trigger main function start-if
- Frees the remainder
*/

char	*ft_remainderintoline(char **remainder, int fd)
{
	int		i;
	int		len_remainder;
	char	*output;

	i = 0;
	len_remainder = ft_strlen(remainder[fd]);
	output = malloc((len_remainder + 1) * sizeof(char));
	if (!output)
		return (NULL);
	while (remainder[fd][i])
	{	
		output[i] = remainder[fd][i];
		i++;
	}
	output[i] = 0;
	free(remainder[fd]);
	remainder[fd] = NULL;
	return (output);
}

/*
- Searches for \n
- If found, returns index of \n
- If not found returns 0
*/

int	ft_findnewline(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*
- Measures length of line and position of \n
- If \n is at the last position of the line, then remainder
	should be empty:
	- Nulls remainder and frees
	- returns line
- Mallocs for remainder: the size of line minus the length of the output
	(which corresponds to the index of the first \n in line) + 1 for 0 byte
- Increments i_newline (see next points why)
- Copies from line into remainder, starting at \n + 1
- 0 terminates remainder
- 0 terminates line after the first \n
- this means line is bigger than the contained string but I didn't want to 
	make a new malloc and free the old line.
*/

char	*ft_makeremainder_returnoutput(char *line, char **remainder, int fd)
{
	int		i;
	int		i_newline;
	int		len_line;

	i = 0;
	i_newline = ft_findnewline(line);
	len_line = ft_strlen(line);
	if (i_newline == len_line - 1)
	{
		free(remainder[fd]);
		remainder[fd] = NULL;
		return (line);
	}
	remainder[fd] = malloc((len_line - i_newline + 1) * sizeof(char));
	i_newline++;
	while (line[i_newline + i])
	{
		remainder[fd][i] = line[i_newline + i];
		++i;
	}		
	remainder[fd][i] = 0;
	line[i_newline] = 0;
	return (line);
}
