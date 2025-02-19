/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_enemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:45:05 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/19 16:00:26 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"
#include "../../../includes/messages.h"

void	spawn_enemies(t_game *game)
{
	int	x;
	int	y;
	int	i;

	if (game->m_height > 3 && game->spawn_space > 5)
		game->enemy_count = MAX_ENEMIES;
	i = 0;
	while (i < game->enemy_count && game->spawn_space > 5 && game->m_height > 3)
	{
		x = rand() % game->m_width;
		y = rand() % game->m_height;
		if (game->grid[y][x] == FREESPACE)
		{
			if ((y > 0 && game->grid[y - 1][x] == WALL) &&
				(y < game->m_height - 1 && game->grid[y + 1][x] == WALL) &&
				(x > 0 && game->grid[y][x - 1] == WALL) &&
				(x < game->m_width - 1 && game->grid[y][x + 1] == WALL))
				continue ;
			game->enemies[i].x = x;
			game->enemies[i].y = y;
			game->enemies[i].old_x = x;
			game->enemies[i].old_y = y;
			i++;
		}
	}
}

void	draw_enemies(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->enemy_count && game->spawn_space > 5 && game->m_height > 3)
	{
		mlx_put_image_to_window(game->mlx,
			game->win,
			game->img_enemy,
			game->enemies[i].x * TILE_SIZE,
			game->enemies[i].y * TILE_SIZE);
		i++;
	}
}

int	choose_enemy_direction(void)
{
	return (rand() % 4);
}

void	refresh_enemies(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->enemy_count && game->spawn_space > 5 && game->m_height > 3)
	{
		if (game->enemies[i].old_x != game->enemies[i].x
			|| game->enemies[i].old_y != game->enemies[i].y)
			draw_tile(game, game->enemies[i].old_y, game->enemies[i].old_x);
		mlx_put_image_to_window(game->mlx,
			game->win,
			game->img_enemy,
			game->enemies[i].x * TILE_SIZE,
			game->enemies[i].y * TILE_SIZE);
		game->enemies[i].old_x = game->enemies[i].x;
		game->enemies[i].old_y = game->enemies[i].y;
		i++;
	}
}

/// @brief
/// @param game
/// @return
int	animate_ghosts(t_game *game)
{
	static unsigned long	last_ghost_time;
	unsigned long			current_time;
	unsigned long			elapsed_time;

	if (last_ghost_time == 0)
		last_ghost_time = get_time_ms();
	current_time = get_time_ms();
	elapsed_time = current_time - last_ghost_time;
	if (elapsed_time > 500)
	{
		move_enemies(game, 0);
		refresh_enemies(game);
		last_ghost_time = current_time;
	}
	return (RET_OK);
}
