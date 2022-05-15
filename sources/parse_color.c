/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:20:49 by ncallie           #+#    #+#             */
/*   Updated: 2022/04/07 18:20:50 by ncallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int
	is_valid_string(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (RETURN_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int
	parse_color(char *str, int *rgb, int *count)
{
	char	**split;
	int		i;
	int		color;

	split = ft_split(str, ',');
	if (!split)
		system_error("Malloc Error");
	i = 0;
	while (split[i])
	{
		color = -1;
		if (is_valid_string(split[i]))
			return (free_return_error(split));
		color = ft_atoi(split[i]);
		if ((color < 0 || color > 255) || *count > 2)
			return (free_return_error(split));
		rgb[*count] = color;
		*count += 1;
		i++;
	}
	free_double_char(split);
	return (RETURN_SUCCESS);
}

int
	get_comma(char *line)
{
	int		i;
	int		comma;

	i = 0;
	comma = 0;
	while (line[i])
	{
		if (line[i] == ',')
			comma++;
		i++;
	}
	return (comma);
}

void
	floor_ceiling(t_info *info, int *rgb, int flag)
{
	if (flag == FLOOR)
		info->floor = (0 << 24 | rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
	else
		info->ceiling = (0 << 24 | rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

void
	get_background_color(char *line, t_info *info, int flag)
{
	char	**split;
	int		rgb[3];
	int		i;
	int		count;

	i = 1;
	count = 0;
	if (get_comma(line) != 2)
		exit_error("Map: Invalid Color Value\n");
	split = ft_split(line, ' ');
	if (!split)
		system_error("Malloc Error");
	if (ft_splitlen(split) < 2)
		free_exit_error(split, "Map: Invalid Color Value\n");
	while (split[i])
	{
		if (parse_color(split[i], rgb, &count))
			free_exit_error(split, "Map: Invalid Color Value\n");
		i++;
	}
	floor_ceiling(info, rgb, flag);
	info->color_flag++;
	free_double_char(split);
}
