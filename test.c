# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> //remove
# include <fcntl.h> //remove

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

int ft_findchar(char *s1, char c)
{
	int	i;
	
	i = 0;
	while (s1[i] && s1[i] != c)
		i++;
	if (s1[i] != c)
		return(-1);
	return (i);
}

int	main(void)
{
	char	*line = "knudel";

	printf("ft_strlen:%d\n", ft_strlen(line));
	printf("ft_findnewline:%d\n", ft_findnewline(line));
	printf("ft_findchar 0:%d\n", ft_findchar(line, 0));
	printf("ft_findchar \\n:%d\n", ft_findchar(line, '\n'));
}