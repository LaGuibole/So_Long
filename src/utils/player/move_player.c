/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:05:46 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/18 13:57:06 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"
#include "../../../includes/messages.h"

static void	player(t_game *game, int new_x, int new_y)
{
	if (game->grid[game->player_y][game->player_x] == PLAYER_ON_EXIT)
		game->grid[game->player_y][game->player_x] = EXIT;
	else
		game->grid[game->player_y][game->player_x] = FREESPACE;
	if (game->grid[new_y][new_x] == EXIT)
		game->grid[new_y][new_x] = PLAYER_ON_EXIT;
	else
		game->grid[new_y][new_x] = PLAYER;
	game->player_y = new_y;
	game->player_x = new_x;
}

static void	end_game(t_game *game)
{
	int	i;

	if (game->grid[game->new_y][game->new_x] == EXIT)
	{
		if (game->col_count == 0)
		{
			ft_printf("You won with %d moves\n", game->moves);
			close_win(game);
			exit(EXIT_SUCCESS);
		}
	}
	i = 0;
	while (i < game->enemy_count && game->spawn_space > 5)
	{
		if (game->new_x == game->enemies[i].x
			&& game->new_y == game->enemies[i].y)
		{
			ft_printf("Game Over, Pac-Man got caught!\n");
			close_win(game);
		}
		i++;
	}
}

void	move_player(t_game *game, int gx, int gy)
{
	game->new_x = game->player_x + gx;
	game->new_y = game->player_y + gy;
	if (game->new_x < 0 || game->new_x >= game->m_width || game->new_y < 0
		|| game->new_y >= game->m_height
		|| game->grid[game->new_y][game->new_x] == WALL)
		return ;
	if (gx < 0)
		game->current_dir = 0;
	if (gx > 0)
		game->current_dir = 1;
	if (gy < 0)
		game->current_dir = 2;
	if (gy > 0)
		game->current_dir = 3;
	if (game->grid[game->new_y][game->new_x] == COLLECTIBLE)
	{
		game->grid[game->new_y][game->new_x] = FREESPACE;
		game->col_count--;
	}
	game->moves++;
	end_game(game);
	draw_tile(game, game->player_y, game->player_x);
	player(game, game->new_x, game->new_y);
	draw_tile(game, game->new_y, game->new_x);
}

unsigned long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int	animate_pacman(t_game *game)
{
	static unsigned long	last_frame_time;
	unsigned long			current_time;
	unsigned long			elapsed_time;

	if (last_frame_time == 0)
		last_frame_time = (long)get_time_ms();
	current_time = get_time_ms();
	elapsed_time = current_time - last_frame_time;
	if (elapsed_time > 150)
	{
		draw_tile(game, game->player_y, game->player_x);
		draw_tile(game, game->exit_y, game->exit_x);
		game->current_frame = (game->current_frame + 1) % 3;
		last_frame_time = current_time;
		draw_tile(game, game->player_y, game->player_x);
		draw_tile(game, game->exit_y, game->exit_x);
	}
	return (0);
}
