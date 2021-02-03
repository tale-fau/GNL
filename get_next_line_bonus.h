/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 10:05:51 by tale-fau          #+#    #+#             */
/*   Updated: 2021/02/03 10:14:39 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# define MAX_FD 2147483647

int			get_next_line(int fd, char **line);
int			ft_strlen(char *str);
char		*ft_strcpy(char *dest, char *src);
char		*ft_strcat(char *dest, char *src);
int			ft_check(char *str);
void		ft_init(void *s, int c, size_t n);

#endif
