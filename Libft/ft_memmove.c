/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 15:27:21 by ncallie           #+#    #+#             */
/*   Updated: 2021/10/10 14:55:07 by ncallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (src == NULL && dest == NULL)
		return (NULL);
	if (src < dest)
	{
		while (n--)
		{
			*(unsigned char *)(dest + n) = *(unsigned char *)(src + n);
		}
	}
	else if (src > dest)
		ft_memcpy (dest, src, n);
	return (dest);
}
