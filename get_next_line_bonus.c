/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 10:05:17 by tale-fau          #+#    #+#             */
/*   Updated: 2021/02/03 10:14:41 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_join_gnl(char *str, char *buffer)
{
	int		len_str;
	int		len_totale;
	char	*newline;

	if (!buffer)
		return (NULL);
	len_str = ft_strlen(str);
	len_totale = len_str + ft_strlen(buffer);
	if ((newline = (char *)malloc(sizeof(char) * (len_totale + 1))) == NULL)
		return (NULL);
	ft_init(newline, 0, (len_totale + 1));
	if (str)
		ft_strcpy(newline, str);
	ft_strcat(newline, buffer);
	free((char*)str);
	return (newline);
}

static char	*ft_get_first_line(char *str)
{
	int		i;
	char	*ret;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if ((ret = (char *)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

static char	*ft_get_remain(char *str)
{
	int		i;
	int		len;
	int		remain_len;
	char	*ret;

	if (!str)
		return (NULL);
	i = 0;
	len = 0;
	remain_len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	if (str[len] == '\0')
	{
		free(str);
		return (NULL);
	}
	remain_len = ft_strlen(str) - len;
	if ((ret = (char *)malloc(sizeof(char) * (remain_len + 1))) == NULL)
		return (NULL);
	while (str[++len])
		ret[i++] = str[len];
	ret[i] = '\0';
	free(str);
	return (ret);
}

int			get_next_line(int fd, char **line)
{
	int			ret_read;
	static char	*str[MAX_FD];
	char		*buffer;

	ret_read = 1;
	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	if ((buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))) == NULL)
		return (-1);
	while (!ft_check(str[fd]) && ret_read != 0)
	{
		if ((ret_read = read(fd, buffer, BUFFER_SIZE)) == -1)
		{
			free(buffer);
			return (-1);
		}
		buffer[ret_read] = '\0';
		str[fd] = ft_join_gnl(str[fd], buffer);
	}
	free(buffer);
	*line = ft_get_first_line(str[fd]);
	str[fd] = ft_get_remain(str[fd]);
	if (ret_read == 0)
		return (0);
	return (1);
}
