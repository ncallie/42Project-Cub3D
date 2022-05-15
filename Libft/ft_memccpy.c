/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:14:46 by ncallie           #+#    #+#             */
/*   Updated: 2022/04/07 18:14:47 by ncallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*uc_src;
	unsigned char	stop;

	uc_src = (unsigned char *)src;
	stop = (char)c;
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = uc_src[i];
		if (uc_src[i] == stop)
			return (dst + (i + 1));
		i++;
	}
	return (0);
}
