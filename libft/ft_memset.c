/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 14:27:27 by rcross            #+#    #+#             */
/*   Updated: 2019/03/03 15:47:20 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	unsigned char	*w;
	size_t			x;

	x = 0;
	if (n == 0)
		return (b);
	w = (unsigned char *)b;
	while (x < n)
	{
		w[x] = (unsigned char)c;
		x++;
	}
	return (b);
}
