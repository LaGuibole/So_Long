/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_enemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:45:05 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/14 17:37:28 by guphilip         ###   ########.fr       */
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
	while (i < game->enemy_count && game->spawn_space > 5)
	{
		x = rand() % game->m_width;
		y = rand() % game->m_height;
		if (game->grid[y][x] == FREESPACE)
		{
			game->enemy_x[i] = x;
			game->enemy_y[i] = y;
			game->old_e_x[i] = x;
			game->old_e_y[i] = y;
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

void	move_enemies(t_game *game)
{
	int	i;
	int	direction;
	int	new_x;
	int	new_y;

	i = 0;
	while (i < game->enemy_count)
	{
		game->old_e_x[i] = game->enemy_x[i];
		game->old_e_y[i] = game->enemy_y[i];
		direction = rand() % 4;
		new_x = game->enemy_x[i];
		new_y = game->enemy_y[i];
		if (direction == 0)
			new_y -= 1;
		else if (direction == 1)
			new_y += 1;
		else if (direction == 2)
			new_x -= 1;
		else if (direction == 3)
			new_x += 1;
		if (new_x >= 0 && new_x < game->m_width && new_y >= 0 && new_y < game->m_height && game->grid[new_y][new_x] != WALL && game->grid[new_y][new_x] != EXIT)
		{
			game->enemy_x[i] = new_x;
			game->enemy_y[i] = new_y;
		}
		i++;
	}
}

void	refresh_enemies(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->enemy_count)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_enemy, game->enemy_x[i] * TILE_SIZE, game->enemy_y[i] * TILE_SIZE);
		draw_tile(game, game->old_e_y[i], game->old_e_x[i]);
		game->old_e_x[i] = game->enemy_x[i];
		game->old_e_y[i] = game->enemy_y[i];
		i++;
	}
}
