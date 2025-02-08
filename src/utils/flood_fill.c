/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:40:55 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/08 17:19:49 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	find_player(t_game *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->grid[i][j] == 'P')
			{
				map->player_x = i;
				map->player_y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

static void	flood_fill(t_game *map, int x, int y)
{
	if (x < 0 || x >= map->height || y < 0 || y >= map->width)
		return ;
	if (map->grid[x][y] == '1' || map->grid[x][y] == 'V')
		return ;
	map->grid[x][y] = 'V';

	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

static int is_map_solvable(t_game *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->grid[i][j] == 'C' || map->grid[i][j] == 'E')
				return (RET_ERR);
			j++;
		}
		i++;
	}
	return (RET_OK);
}

int	is_path_valid(t_game *original)
{
	t_game copy;

	copy = (t_game){};
	copy_map(original, &copy);
	flood_fill(&copy, copy.player_x, copy.player_y);
	if (is_map_solvable(&copy) == RET_ERR)
	{
		free_map(&copy);
		return (RET_ERR);
	}
	free_map(&copy);
	return (RET_OK);
}
