/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:40:55 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/19 17:15:23 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"
#include "../../../includes/messages.h"

/// @brief Store x and y player position
/// @param map A pointer to game struct
void	find_player(t_game *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->m_height)
	{
		x = 0;
		while (x < map->m_width)
		{
			if (map->grid[y][x] == EXIT)
			{
				map->exit_x = x;
				map->exit_y = y;
			}
			if (map->grid[y][x] == PLAYER)
			{
				map->player_x = x;
				map->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

/// @brief FloodFill Algorithm, replace chars with 'V'
/// @param map A pointer to the game struct
/// @param x y axis
/// @param y x axis (unlogic i see it now T_T)
static void	flood_fill(t_game *map, int x, int y)
{
	if (y < 0 || y >= map->m_height || x < 0 || x >= map->m_width)
		return ;
	if (map->grid[y][x] == WALL || map->grid[y][x] == FLOOD_VALID)
		return ;
	if (map->grid[y][x] == EXIT || map->grid[y][x] == COLLECTIBLE)
		map->grid[y][x] = FLOOD_VALID;
	map->grid[y][x] = FLOOD_VALID;
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

/// @brief Method to check if the map could be finished or not
/// @param map A pointer to game struct
/// @return
static int	is_map_solvable(t_game *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->m_height)
	{
		j = 0;
		while (j < map->m_width)
		{
			if (map->grid[i][j] == COLLECTIBLE || map->grid[i][j] == EXIT)
				return (RET_ERR);
			j++;
		}
		i++;
	}
	return (RET_OK);
}

/// @brief Could the player finish the game ?
/// @param original A pointer to the original map
/// @return
int	is_path_valid(t_game *original)
{
	t_game	copy;

	copy = (t_game){};
	copy_map(original, &copy);
	find_player(original);
	find_player(&copy);
	flood_fill(&copy, copy.player_x, copy.player_y);
	if (is_map_solvable(&copy) == RET_ERR)
	{
		free_map(&copy);
		return (RET_ERR);
	}
	free_map(&copy);
	return (RET_OK);
}
