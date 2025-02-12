/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:39:28 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/12 10:23:08 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"
#include "../../../includes/messages.h"

void	free_map(t_game *map)
{
	int	i;

	i = 0;
	if (map->grid != NULL)
	{
		while (i < map->m_height)
		{
			free(map->grid[i]);
			i++;
		}
		free(map->grid);
		map->grid = NULL;
	}
}

void	clean_lines(char **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		if (map[i])
			free(map[i]);
		i++;
	}
	free(map);
}

void	clean_sprites(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 3)
		{
			mlx_destroy_image(game->mlx, game->sprites[i][j]);
			j++;
		}
		i++;
	}
}

void	cleanup(t_game *game)
{
	clean_lines(game->grid, game->m_height);
	game->grid = NULL;
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->sprites)
		clean_sprites(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
}
