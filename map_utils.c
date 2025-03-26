/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aid-bray <aid-bray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 14:05:30 by aid-bray          #+#    #+#             */
/*   Updated: 2025/03/22 02:29:09 by aid-bray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_first_line(char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		if (src[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	check_last_line(char *src, int len)
{
	int		i;

	if ((int)ft_strlen(src) != len)
		return (0);
	i = 0;
	while (src[i])
	{
		if (src[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	check_line(char *src, int len, t_cart *cart)
{
	int		i;

	if ((int)ft_strlen(src) != len)
		return (0);
	else if (src[0] != '1' || src[ft_strlen(src) - 1] != '1')
		return (0);
	i = 1;
	while (src[i])
	{
		if (src[i] == 'P')
			cart->position++;
		else if (src[i] == 'C')
			cart->collecter++;
		else if (src[i] == 'E')
			cart->exit++;
		else if (src[i] != '1' && src[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

int	size_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return (0);
	while (map[i])
		i++;
	return (i);
}

void	check_map_lines(char **map)
{
	int		len;
	int		i;
	t_cart	cart;

	cart.collecter = 0;
	cart.position = 0;
	cart.exit = 0;
	if (!check_first_line(map[0]))
		exit_game(NULL, map, "Error\nInvalid first line in map.\n", 0);
	len = ft_strlen(map[0]);
	i = 1;
	while (map[i] && map[i + 1])
		if (!check_line(map[i++], len, &cart))
			exit_game(NULL, map, "Error\nInvalid midle line in map.\n", 0);
	if (!check_last_line(map[i], len))
		exit_game(NULL, map, "Error\nInvalid last line in map.\n", 0);
	if (cart.position != 1)
		exit_game(NULL, map, "Error\nInvalid number of characters.\n", 0);
	if (cart.exit != 1)
		exit_game(NULL, map, "Error\nInvalid number of exit.\n", 0);
	if (cart.collecter < 1)
		exit_game(NULL, map, "Error\nNo collectible in map.\n", 0);
}
