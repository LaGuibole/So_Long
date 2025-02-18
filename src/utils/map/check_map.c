/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:15:59 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/18 14:33:17 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"
#include "../../../includes/messages.h"

/// @brief A function to check if the map has .ber extension
/// @param map_file will be argv[1] so the map file
/// @return 0 if map has ber, 1 otherwise
int	has_ber_extension(t_game *map)
{
	char	*str_cpy;

	if (!map->map_file || ft_strlen(map->map_file) <= 4)
		return (1);
	str_cpy = map->map_file + ft_strlen(map->map_file) - 4;
	return (ft_strcmp(str_cpy, ".ber"));
}
/// @brief Check if the map is rectangular
/// @param map
/// @return 0 if rectangular 1 otherwise
int	is_rectangular(t_game *map)
{
	int	i;

	if (!map || !map->grid)
		return (RET_ERR);
	i = 0;
	while (i < map->m_height)
	{
		if ((int)ft_strlen(map->grid[i]) != map->m_width)
			return (RET_ERR);
		i++;
	}
	return (RET_OK);
}
/// @brief Check if the map is bordered with 1
/// @param map
/// @return return 0 if ok, 1 otherwise
int	is_bordered_with_walls(t_game *map)
{
	int	i;

	if (!map || !map->grid)
		return (RET_ERR);
	i = 0;
	while (i < map->m_width)
	{
		if (map->grid[0][i] != '1' || map->grid[map->m_height - 1][i] != '1')
			return (RET_ERR);
		i++;
	}
	i = 0;
	while (i < map->m_height)
	{
		if (map->grid[i][0] != '1' || map->grid[i][map->m_width - 1] != '1')
			return (RET_ERR);
		i++;
	}
	return (RET_OK);
}
/// @brief Check if the map has only valid elements (E, C, P, 0, 1)
/// @param map
/// @return 0 if ok, 1 on error
int	has_valid_elements(t_game *map)
{
	int	i;
	int	j;

	if (!map || !map->grid)
		return (RET_ERR);
	i = -1;
	while (++i < map->m_height)
	{
		j = -1;
		while (++j < map->m_width)
		{
			if (map->grid[i][j] != '1' && map->grid[i][j] != '0' &&
				map->grid[i][j] != 'E' && map->grid[i][j] != 'C' &&
				map->grid[i][j] != 'P')
				return (RET_ERR);
			else if (map->grid[i][j] == '0')
				map->spawn_space++;
		}
	}
	return (RET_OK);
}
/// @brief Check if the map has only one player, one exit and at least 1 collec
/// @param map
/// @return 0 if ok, 1 on error
int	has_required_elements(t_game *map)
{
	int	i;
	int	j;

	if (!map || !map->grid)
		return (RET_ERR);
	map->player_count = 0;
	map->col_count = 0;
	map->exit_count = 0;
	i = -1;
	while (++i < map->m_height)
	{
		j = -1;
		while (++j < map->m_width)
		{
			if (map->grid[i][j] == 'P')
				map->player_count++;
			else if (map->grid[i][j] == 'C')
				map->col_count++;
			else if (map->grid[i][j] == 'E')
				map->exit_count++;
		}
	}
	if (map->player_count != 1 || map->col_count < 1 || map->exit_count != 1)
		return (RET_ERR);
	return (RET_OK);
}
