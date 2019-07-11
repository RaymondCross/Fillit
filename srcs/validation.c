/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 21:13:57 by rcross            #+#    #+#             */
/*   Updated: 2019/07/11 15:09:01 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void		make_piece(char *str, char letter, t_etris **tetriminos)
{
	char	tmp[20];

	trimstr(str, tmp);
	trimmer(tmp);
	add_tet(tmp, letter, tetriminos);
}

/*
** checks top, sides, and bottom of a hash for validity
*/

int			check_links(char *str)
{
	int link;
	int i;

	link = 0;
	i = -1;
	while (++i < 20)
	{
		if (str[i] == '#')
		{
			if ((i + 1) < 20 && str[i + 1] == '#')
				link++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				link++;
			if ((i + 5) < 20 && str[i + 5] == '#')
				link++;
			if ((i - 5) >= 0 && str[i - 5] == '#')
				link++;
		}
	}
	return (link == 6 || link == 8);
}

/*
**	checks for anything that shouldn't be in the file
**	and checks for proper formatting before checking
**	links of a piece, maximum number of pieces is 26
*/

int			check_file(char *str, int i, int hash, int count)
{
	while (++i < 20)
	{
		if (i % 5 < 4)
		{
			if (!(str[i] == '#' || str[i] == '.'))
				return (0);
			if (str[i] == '#' && ++hash > 4)
				return (0);
		}
		else if (str[i] != '\n')
			return (0);
	}
	if (count == 21 && str[20] != '\n')
		return (0);
	if (!check_links(str))
		return (0);
	if (++g_pcs > 26)
		return (0);
	return (1);
}

/*
**	reads a whole 21 byte chunk of the file into buf,
**	checks it, then adds it to the linked list
*/

int			read_file(int fd, t_etris **tetriminos)
{
	char	buf[22];
	int		count;
	char	cur;

	g_pcs = 0;
	cur = 'A';
	while ((count = read(fd, buf, 21)) >= 20)
	{
		buf[count] = '\0';
		if (check_file(buf, -1, 0, count) == 0)
			return (0);
		make_piece(buf, cur, tetriminos);
		cur++;
	}
	if (count == 0 && g_pcs == 0)
		return (0);
	if (count != 0)
		return (0);
	return (1);
}
