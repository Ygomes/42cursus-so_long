/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 08:44:55 by ygomes-d          #+#    #+#             */
/*   Updated: 2021/12/09 16:29:16 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*make_next_str(char *str, int i)
{
	char	*next_str;

	if (!str[i])
	{
		free (str);
		return (NULL);
	}
	next_str = ft_strdup(str + i);
	free (str);
	return (next_str);
}

static char	*make_line(int fd, char *str, char *buff)
{
	int		r;
	char	*tmp;

	r = 1;
	while (r != 0)
	{
		r = read(fd, buff, BUFFER_SIZE);
		if (r < 0)
		{
			free (buff);
			return (NULL);
		}
		buff[r] = '\0';
		if (!str)
			str = ft_strdup("");
		tmp = str;
		str = ft_strjoin(tmp, buff);
		free (tmp);
		if (ft_strchr(str, '\n'))
			break ;
	}
	free (buff);
	return (str);
}

static char	*cpyline(char *str, int i)
{
	char	*line;

	line = ft_substr(str, 0, i);
	if (!line[0])
	{
		free (line);
		return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buff;
	char		*line;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
	{
		free (buff);
		return (NULL);
	}
	str = make_line(fd, str, buff);
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = cpyline(str, i);
	str = make_next_str(str, i);
	return (line);
}
