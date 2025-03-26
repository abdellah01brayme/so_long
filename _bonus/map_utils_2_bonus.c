/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aid-bray <aid-bray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:58:51 by aid-bray          #+#    #+#             */
/*   Updated: 2025/03/22 03:36:51 by aid-bray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	find_line_position(char **map, char c)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

int	find_position(char *line, char c)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == c)
			return (i);
		i++;
	}
	return (0);
}

int	get_nbr_coins(char **map)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

static void	make_all_p(char **map, int y, int x)
{
	if (ft_strchr("0CE", map[y][x]))
	{
		map[y][x] = 'P';
		make_all_p(map, y, x + 1);
		make_all_p(map, y, x - 1);
		make_all_p(map, y + 1, x);
		make_all_p(map, y - 1, x);
	}
}

int	check_map_valide(char **map)
{
	int	x;
	int	y;

	y = find_line_position(map, 'P');
	x = find_position(map[y], 'P');
	make_all_p(map, y, x - 1);
	make_all_p(map, y, x + 1);
	make_all_p(map, y - 1, x);
	make_all_p(map, y + 1, x);
	y = 0;
	while (map[y])
	{
		x = -1;
		while (map[y][++x])
			if (map[y][x] == 'E' || map[y][x] == 'C')
				return (free_map(map), 0);
		y++;
	}
	free_map(map);
	return (1);
}
