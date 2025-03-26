/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aid-bray <aid-bray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:21:51 by aid-bray          #+#    #+#             */
/*   Updated: 2025/03/09 13:43:03 by aid-bray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_line(char *save_line)
{
	size_t	i;

	i = 0;
	if (!save_line)
		return (0);
	while (save_line[i])
		if (save_line[i++] == '\n')
			return (1);
	return (0);
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

char	*get_new_line(char **stock)
{
	size_t	i;
	size_t	len;
	char	*tmp;
	char	*line;

	i = 0;
	tmp = NULL;
	while ((*stock)[i] && (*stock)[i] != '\n')
		i++;
	if ((*stock)[i] == '\n')
		i++;
	len = i;
	line = malloc (i + 1);
	if (!line)
		return (NULL);
	line[i] = '\0';
	while (i--)
		line[i] = (*stock)[i];
	if ((*stock)[len])
		tmp = ft_strdup((*stock) + len);
	free((*stock));
	(*stock) = tmp;
	return (line);
}
