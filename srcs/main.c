/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 21:03:41 by rcross            #+#    #+#             */
/*   Updated: 2019/07/11 15:09:25 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int			ft_usage(void)
{
	ft_putstr("usage: ./fillit [input file]\n");
	exit(0);
}

int			ft_error(void)
{
	ft_putstr("error\n");
	exit(0);
}

void		fillit(t_etris *tetriminos)
{
	char	**map;
	int		size;

	size = get_size();
	map = create_map(size);
	while (solver(map, tetriminos) == 0)
	{
		ft_mapdel(map);
		size++;
		map = create_map(size);
	}
	print_solution(map);
	ft_mapdel(map);
}

int			main(int argc, char **argv)
{
	int			fd;
	t_etris		*tetriminos;

	tetriminos = NULL;
	if (argc != 2)
		return (ft_usage());
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (ft_error());
	if (read_file(fd, &tetriminos) == 0)
	{
		deletelist(&tetriminos);
		return (ft_error());
	}
	fillit(tetriminos);
	deletelist(&tetriminos);
	close(fd);
	return (0);
}
