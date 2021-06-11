int	w2l(int fd, char *buf, char **line)
{
	int		rv;
	char	*lineleak;

	while (1)
	{
		rv = read(fd, buf, 1);
		if (rv < 0)
			return (-1);
		else if (rv == 0)
			return (0);
		else
		{
			if (*buf == '\n')
				return (1);
			else
			{
				lineleak = *line;
				*line = ft_strjoin(*line, buf);
				free(lineleak);
				lineleak = NULL;
			}
		}
	}
}

int	get_next_line(int fd, char **line)
{
	static char		buf;
	int				rv;

	*line = (char *)ft_calloc(1, sizeof(char *));
	// if (!(*line = malloc(1)))
	// 	return (-1);
	**line = 0;
	rv = w2l(fd, &buf, line);
	return (rv);
}
