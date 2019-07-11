/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 21:03:35 by rcross            #+#    #+#             */
/*   Updated: 2019/07/11 15:11:49 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void		add_tet(char *buf, char letter, t_etris **tet)
{
	char	**ndata;
	t_etris	*new;

	ndata = ft_strsplit(buf, '\n');
	new = make_node(ndata, letter);
	add_node(tet, new);
}

t_etris		*make_node(char **ndata, char letter)
{
	t_etris		*new;

	if (!(new = (t_etris *)malloc(sizeof(t_etris))))
		return (NULL);
	new->letter = letter;
	new->piece = ndata;
	new->next = NULL;
	return (new);
}

void		add_node(t_etris **head, t_etris *new)
{
	t_etris		*current;

	current = *head;
	if (!(*head))
		*head = new;
	else
	{
		while (current->next)
			current = current->next;
		current->next = new;
	}
}

void		deletelist(t_etris **head)
{
	t_etris		*tmp;

	while (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		ft_mapdel(tmp->piece);
		free(tmp);
		tmp = NULL;
	}
	head = NULL;
}
