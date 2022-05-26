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
REMOVE OUTPUT AND LINE FREE TRY________________________________________
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
		return (ft_strdup(readbuffer));
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
	char	*output;

	output = ft_strdup(remainder[fd]);
	free(remainder[fd]);
	remainder[fd] = NULL;
	return (output);
}

/*
- Measures length of line and position of \n
- If \n is at the last position of the line, then remainder
	should be empty:
	- Nulls remainder and frees
	- returns line
- If there remains content after \n, this is saved in remainder
	- strdup beginning with the position after the first \n
		in line.
- 0 terminates line after the first \n
- this means line is bigger than the contained string but I didn't want to 
	make a new malloc and free the old line.
*/

char	*ft_makeremainder_returnoutput(char *line, char **remainder, int fd)
{
	int		ind_newline;
	int		len_line;

	ind_newline = ft_findnewline(line);
	len_line = ft_strlen(line);
	if (ind_newline == len_line - 1)
	{
		free(remainder[fd]);
		remainder[fd] = NULL;
		return (line);
	}
	remainder[fd] = ft_strdup(line + ind_newline + 1);
	line[ind_newline + 1] = 0;
	return (line);
}
