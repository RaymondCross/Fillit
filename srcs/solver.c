/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 21:13:42 by rcross            #+#    #+#             */
/*   Updated: 2019/07/11 15:11:53 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		solver(char **map, t_etris *node)
{
	int		i;
	int		j;

	i = 0;
	if (!node)
		return (1);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_placeable(map, node, i, j) == 1)
			{
				map = place(map, node, i, j);
				if (solver(map, node->next) == 0)
					map = clean_map(map, node);
				else
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		is_placeable(char **map, t_etris *node, int i, int j)
{
	int		x;
	int		y;

	x = 0;
	while (node->piece[x])
	{
		if (map[i + x] == 0)
			return (-1);
		y = 0;
		while (node->piece[x][y])
		{
			if (map[i + x][j + y] == 0)
				return (-1);
			if (node->piece[x][y] != '.' && map[i + x][j + y] != '.')
				return (-1);
			y++;
		}
		x++;
	}
	return (1);
}

char	**place(char **map, t_etris *node, int i, int j)
{
	int		x;
	int		y;

	x = 0;
	while (node->piece[x])
	{
		y = 0;
		while (node->piece[x][y])
		{
			if (node->piece[x][y] != '.')
				map[i + x][j + y] = node->letter;
			y++;
		}
		x++;
	}
	return (map);
}

char	**clean_map(char **map, t_etris *node)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == node->letter)
				map[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}
