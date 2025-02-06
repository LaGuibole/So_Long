/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:15:59 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/06 19:29:03 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/// @brief A function to check if the map has .ber extension
/// @param map_file will be argv[1] so the map file
/// @return 0 if map has ber, 1 otherwise
int	has_ber_extension(t_map *map)
{
	char	*str_cpy;

	if (!map->map_file || ft_strlen(map->map_file) <= 4)
		return (1);
	str_cpy = map->map_file + ft_strlen(map->map_file) - 4;
	return (ft_strcmp(str_cpy, ".ber"));
}

int	is_rectangular(t_map *map)
{
	int	i;

	if (!map || !map->grid)
		return (RET_ERR);
	i = 0;
	while (i < map->height)
	{
		if ((int)ft_strlen(map->grid[i]) != map->width)
			return (RET_ERR);
		i++;
	}
	return (RET_OK);
}

