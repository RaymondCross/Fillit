/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 21:13:50 by rcross            #+#    #+#             */
/*   Updated: 2019/07/11 15:11:58 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void		trimstr(char *str, char *tmp)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] != '\n')
		{
			tmp[j] = str[i];
			j++;
		}
	}
	tmp[j] = '\0';
}

void		trimmer(char *str)
{
	if (ft_strstr(str, SQUARE) != NULL)
		(ft_strcpy(str, SQUARE2));
	else if (ft_strstr(str, LINE) != NULL)
		(ft_strcpy(str, LINE2));
	else if (ft_strstr(str, STR8) != NULL)
		(ft_strcpy(str, STR8));
	else if (ft_strstr(str, TUP) != NULL)
		(ft_strcpy(str, TUP2));
	else if (ft_strstr(str, TRIGHT) != NULL)
		(ft_strcpy(str, TRIGHT2));
	else if (ft_strstr(str, TDOWN) != NULL)
		(ft_strcpy(str, TDOWN2));
	else if (ft_strstr(str, TLEFT) != NULL)
		(ft_strcpy(str, TLEFT2));
	else if (ft_strstr(str, LUP) != NULL)
		(ft_strcpy(str, LUP2));
	else if (ft_strstr(str, LRIGHT) != NULL)
		(ft_strcpy(str, LRIGHT2));
	else if (ft_strstr(str, LDOWN) != NULL)
		(ft_strcpy(str, LDOWN2));
	else
		(trimmer2(str));
}

void		trimmer2(char *str)
{
	if (ft_strstr(str, LLEFT) != NULL)
		(ft_strcpy(str, LLEFT2));
	else if (ft_strstr(str, JUP) != NULL)
		(ft_strcpy(str, JUP2));
	else if (ft_strstr(str, JRIGHT) != NULL)
		(ft_strcpy(str, JRIGHT2));
	else if (ft_strstr(str, JDOWN) != NULL)
		(ft_strcpy(str, JDOWN2));
	else if (ft_strstr(str, JLEFT) != NULL)
		(ft_strcpy(str, JLEFT2));
	else if (ft_strstr(str, ZUP) != NULL)
		(ft_strcpy(str, ZUP2));
	else if (ft_strstr(str, ZSIDE) != NULL)
		(ft_strcpy(str, ZSIDE2));
	else if (ft_strstr(str, SUP) != NULL)
		(ft_strcpy(str, SUP2));
	else if (ft_strstr(str, SSIDE) != NULL)
		(ft_strcpy(str, SSIDE2));
}
