/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:40:55 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/11 16:20:50 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"
#include "../../../includes/messages.h"

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

static void	flood_fill(t_game *map, int x, int y)
{
	if (y < 0 || y >= map->m_height || x < 0 || x >= map->m_width)
		return ;
	if (map->grid[y][x] == '1' || map->grid[y][x] == 'V')
		return ;
	if (map->grid[y][x] == 'E' || map->grid[y][x] == 'C')
		map->grid[y][x] = 'V';
	map->grid[y][x] = 'V';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

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
	t_game	copy;

	copy = (t_game){};
	copy_map(original, &copy);
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
