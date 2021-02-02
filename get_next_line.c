/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 11:41:28 by tale-fau          #+#    #+#             */
/*   Updated: 2021/02/02 10:52:45 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

static char	*ft_join_gnl(char *str, char *buffer)
{
	int		len_str;
	int		len_totale;
	char	*newline;

	if (!buffer)
		return (NULL);
	len_str = ft_strlen(str);
	len_totale = len_str + ft_strlen(buffer);
//	printf("len totale = %i\n", len_totale);
	if ((newline = (char *)malloc(sizeof(char) * (len_totale + 1))) == NULL)
		return (NULL);
	ft_init(newline, 0, (len_totale + 1));
//	printf(" ***** newline avant cpy = %s\n", newline);
	if (str)
		ft_strcpy(newline, str);
//	printf(" ***** newline apres cpy= %s\n", newline);
	ft_strcat(newline, buffer);
//	printf("BUFFER = %s\n", buffer);
//	printf(" ///////// str apres cat = %s\n", newline);
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
	while (str[i] && str[i] != '\n')
	{
		len++;
		i++;
	}
	printf("len=%d\n", len);
	if (str[i] == '\0')
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
	static char	*str;
	char		*buffer;

	ret_read = 1;
	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	if ((buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))) == NULL)
		return (-1);
	while (!ft_check(str) && ret_read != 0)
	{
		if ((ret_read = read(fd, buffer, BUFFER_SIZE)) == -1)
		{
			free(buffer);
			return (-1);
		}
		buffer[ret_read] = '\0';
		str = ft_join_gnl(str, buffer);
	}
	free(buffer);
	*line = ft_get_first_line(str);
	str = ft_get_remain(str);
	if (ret_read == 0)
		return (0);
	return (1);
}
