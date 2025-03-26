/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aid-bray <aid-bray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 21:17:37 by aid-bray          #+#    #+#             */
/*   Updated: 2025/03/09 13:34:20 by aid-bray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_file(int fd)
{
	char	*buff;
	ssize_t	len;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buff = malloc (BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	len = read(fd, buff, BUFFER_SIZE);
	if (len <= 0)
		return (free(buff), NULL);
	buff[len] = '\0';
	return (buff);
}

static size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*tab;

	i = 0;
	j = 0;
	tab = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!tab)
		return (NULL);
	while (s1 && s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		tab[i] = s2[j];
		i++;
		j++;
	}
	tab[i] = '\0';
	s2[0] = '\0';
	return (tab);
}

static char	*ft_strdup(char *s)
{
	ssize_t	len;
	ssize_t	i;
	char	*new;

	len = ft_strlen(s);
	if (!s)
		return (free(s), NULL);
	new = malloc (len + 1);
	if (!new)
		return (free(s), NULL);
	i = 0;
	while (i < len)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*stock = NULL;
	char		*tmp;
	char		*buff;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	tmp = NULL;
	while (!is_line(stock))
	{
		buff = read_file(fd);
		if (!buff)
			break ;
		tmp = ft_strjoin(stock, buff);
		free(stock);
		free(buff);
		stock = tmp;
	}
	if (is_line(stock))
		return (get_new_line(&stock));
	else if (ft_strlen(stock))
		tmp = ft_strdup(stock);
	free(stock);
	stock = NULL;
	return (tmp);
}
