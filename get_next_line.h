/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 21:48:03 by wmardin           #+#    #+#             */
/*   Updated: 2022/05/26 18:04:07 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> //remove
# include <fcntl.h> //remove

char	*get_next_line(int fd);
char	*ft_appendbuffertoline(char *line, char *readbuffer);
char	*ft_remainderintoline(char **remainder, int fd);
int		ft_findnewline(const char *line);
char	*ft_makeremainder_returnoutput(char *line, char **remainder, int fd);
int		ft_strlen(const char *s);
char	*ft_strdup(char *source);

#endif