/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:16:29 by ncallie           #+#    #+#             */
/*   Updated: 2022/04/07 18:16:30 by ncallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void
	exit_error(char *err_msg)
{
	ft_putstr_fd(err_msg, 2);
	exit(EXIT_FAILURE);
}

void
	system_error(char *err_msg)
{
	perror(err_msg);
	exit(EXIT_FAILURE);
}

void
	free_exit_error(char **str, char *err_msg)
{
	int		i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	ft_putstr_fd(err_msg, 2);
	exit(EXIT_FAILURE);
}

int
	free_return_error(char **str)
{
	int		i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	return (RETURN_FAILURE);
}
