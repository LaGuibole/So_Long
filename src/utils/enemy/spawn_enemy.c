/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_enemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:45:05 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/13 17:43:56 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"
#include "../../../includes/messages.h"

void	spawn_enemies(t_game *game)
{
	int	x;
	int	y;
	int	i;

	game->enemy_count = MAX_ENEMIES;
	i = 0;
	while (i < game->enemy_count)
	{
		x = rand() % game->m_width;
		y = rand() % game->m_height;
		if (game->grid[y][x] == FREESPACE)
		{
			game->enemy_x[i] = x;
			game->enemy_y[i] = y;
			i++;
		}
	}
}

void	draw_enemies(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->enemy_count)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_enemy, game->enemy_x[i] * TILE_SIZE, game->enemy_y[i] * TILE_SIZE);
		i++;
	}
}
