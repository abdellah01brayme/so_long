/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aid-bray <aid-bray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:00:22 by aid-bray          #+#    #+#             */
/*   Updated: 2025/03/22 17:22:02 by aid-bray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	is_valide_extend_file(char *src)
{
	char	*tmp;
	int		len_src;
	int		i;

	len_src = ft_strlen(src);
	if (len_src <= 4)
		return (0);
	i = ft_strlen(".ber");
	tmp = ft_strrchr(src, '/');
	if (tmp && ft_strlen(tmp) <= 5)
		return (0);
	else if (!ft_strncmp(src + (len_src - i), ".ber", i))
		return (1);
	return (0);
}

static int	count_char(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (count);
}

static char	*read_file(int fd)
{
	char	*line;
	char	*swap;
	char	*tmp;

	tmp = NULL;
	line = get_next_line(fd);
	while (line)
	{
		swap = tmp;
		tmp = ft_strjoin(tmp, line);
		free(swap);
		free(line);
		if (!tmp)
			break ;
		line = get_next_line(fd);
	}
	if (!tmp)
	{
		perror("Error\nMemoire");
		exit(0);
	}
	return (tmp);
}

static char	**file_to_map(char *file)
{
	char	**map;

	if (file[ft_strlen(file) - 1] == '\n')
	{
		free(file);
		ft_putstr_fd("Error\nInvalid map lines\n", 2);
		exit(0);
	}
	map = ft_split(file, '\n');
	if (!map)
	{
		perror("Error\nMemoire");
		free(file);
		exit(0);
	}
	if (size_map(map) - 1 != count_char(file, '\n'))
	{
		free_map(map);
		free(file);
		ft_putstr_fd("Error\nInvalid map lines\n", 2);
		exit(0);
	}
	return (map);
}

char	**handl_map(char *name)
{
	char	**map;
	char	**cp_map;
	int		fd;
	char	*file;

	fd = open(name, O_RDONLY);
	if (fd < 0)
		exit_game(NULL, NULL, name, 2);
	file = read_file(fd);
	close(fd);
	map = file_to_map(file);
	free(file);
	check_map_lines(map);
	cp_map = copy_map(map);
	if (!cp_map)
		exit_game(NULL, map, "Memoire", 2);
	if (!check_map_valide(cp_map))
		exit_game(NULL, map,
			"Error\nThe way to exit or colletibles	is close!!!\n", 0);
	return (map);
}
