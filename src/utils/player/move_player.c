/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:05:46 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/13 17:26:06 by guphilip         ###   ########.fr       */
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
	if (game->grid[game->new_y][game->new_x] == EXIT)
	{
		if (game->col_count == 0)
		{
			ft_printf("You won with %d moves\n", game->moves);
			close_win(game);
			exit(EXIT_SUCCESS);
		}
	}
}
// void	move_player(t_game *game, int gx, int gy)
// {
// 	find_player(game);
// 	game->new_x = game->player_x + gx;
// 	game->new_y = game->player_y + gy;
// 	if (game->new_x < 0 || game->new_x >= game->m_width || game->new_y < 0
// 		|| game->new_y >= game->m_height || game->grid[game->new_y][game->new_x] == WALL)
// 		return ;
// 	if (gx < 0)
// 		game->current_dir = 0;
// 	if (gx > 0)
// 		game->current_dir = 1;
// 	if (gy < 0)
// 		game->current_dir = 2;
// 	if (gy > 0)
// 		game->current_dir = 3;
// 	if (game->grid[game->new_y][game->new_x] == COLLECTIBLE)
// 	{
// 		game->grid[game->new_y][game->new_x] = FREESPACE;
// 		game->col_count--;
// 	}
// 	game->moves++; // creer une fonction pour afficher dans le terminal
// 	game->moving = 1;
// 	end_game(game);
// 	player(game, game->new_x, game->new_y);
// 	draw_map(game);
// 	game->moving = 0;
// }
void	move_player(t_game *game, int gx, int gy)
{
	game->new_x = game->player_x + gx;
	game->new_y = game->player_y + gy;
	if (game->new_x < 0 || game->new_x >= game->m_width || game->new_y < 0
		|| game->new_y >= game->m_height || game->grid[game->new_y][game->new_x] == WALL)
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
	game->moves++; // creer une fonction pour afficher dans le terminal
	game->moving = 1;
	end_game(game);
	draw_tile(game, game->player_y, game->player_x);
	player(game, game->new_x, game->new_y);
	draw_tile(game, game->new_y, game->new_x);
	game->moving = 0;
}
void	load_sprites(t_game *game)
{
	int w;
	int	h;

	game->sprites[0][0] = mlx_xpm_file_to_image(game->mlx, P_L_C, &w, &h);
	game->sprites[0][1] = mlx_xpm_file_to_image(game->mlx, P_L_S, &w, &h);
	game->sprites[0][2] = mlx_xpm_file_to_image(game->mlx, P_L_O, &w, &h);
	game->sprites[1][0] = mlx_xpm_file_to_image(game->mlx, P_R_C, &w, &h);
	game->sprites[1][1] = mlx_xpm_file_to_image(game->mlx, P_R_S, &w, &h);
	game->sprites[1][2] = mlx_xpm_file_to_image(game->mlx, P_R_O, &w, &h);
	game->sprites[2][0] = mlx_xpm_file_to_image(game->mlx, P_U_C, &w, &h);
	game->sprites[2][1] = mlx_xpm_file_to_image(game->mlx, P_U_S, &w, &h);
	game->sprites[2][2] = mlx_xpm_file_to_image(game->mlx, P_U_O, &w, &h);
	game->sprites[3][0] = mlx_xpm_file_to_image(game->mlx, P_D_C, &w, &h);
	game->sprites[3][1] = mlx_xpm_file_to_image(game->mlx, P_D_S, &w, &h);
	game->sprites[3][2] = mlx_xpm_file_to_image(game->mlx, P_D_O, &w, &h);
	game->p_sprites[0] = mlx_xpm_file_to_image(game->mlx, P1, &w, &h);
	game->p_sprites[1] = mlx_xpm_file_to_image(game->mlx, P2, &w, &h);
	game->p_sprites[2] = mlx_xpm_file_to_image(game->mlx, P3, &w, &h);
}

// void	draw_pacman(t_game *game, int x, int y)
// {
// 	void	*sprite;

// 	sprite = game->sprites[game->current_dir][game->current_frame];
// 	mlx_put_image_to_window(game->mlx, game->win, sprite, x * TILE_SIZE, y * TILE_SIZE);
// }

// int	animate_pacman(t_game *game)
// {
// 	static int	frame;

// 	if (game->tick % 5000 == 0)
// 	{
// 		if (game->tick % 12 == 0)
// 		{
// 			frame++;
// 			if (frame > 2)
// 				frame = 0;
// 			game->current_frame = frame;
// 			draw_map(game);
// 		}
// 		game->tick++;
// 		if (!game->moving)
// 			game->current_frame = (game->tick / 12) % 3;
// 	}
// 	else
// 		game->tick++;
// 	return (0);
// }

unsigned long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	draw_pacman(t_game *game, int x, int y)
{
	void	*sprite;

	sprite = game->sprites[game->current_dir][game->current_frame];
	mlx_put_image_to_window(game->mlx, game->win, sprite, x * TILE_SIZE, y * TILE_SIZE);
}

// int	animate_pacman(t_game *game)
// {
// 	static unsigned long	last_frame_time = 0;
// 	unsigned long		current_time;
// 	unsigned long		elapsed_time;

// 	current_time = get_time_ms();
// 	elapsed_time = current_time - last_frame_time;

// 	if (elapsed_time > 150)
// 	{
// 		game->current_frame = (game->current_frame + 1) % 3;
// 		last_frame_time = current_time;
// 		draw_map(game);
// 	}
// 	return (0);
// }

int	animate_pacman(t_game *game)
{
	static unsigned long	last_frame_time;
	unsigned long		current_time;
	unsigned long		elapsed_time;
	
	if (last_frame_time == 0)
		last_frame_time = (long)get_time_ms;
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

// void	move_player(t_game *game, int gx, int gy)
// {
// 	int	new_x;
// 	int	new_y;

// 	find_player(game);
// 	new_x = game->player_x + gx;
// 	new_y = game->player_y + gy;
// 	if (new_x < 0 || new_x >= game->m_width || new_y >= game->m_height
// 		|| game->grid[new_y][new_x] == WALL)
// 		return ;
// 	if (game->grid[new_y][new_x] == COLLECTIBLE)
// 	{
// 		game->grid[new_y][new_x] = FREESPACE;
// 		game->col_count -= 1;
// 	}
// 	game->moves++;
// 	ft_printf("moves : %d\n", game->moves);
// 	if (game->grid[new_y][new_x] == EXIT)
// 	{
// 		if (game->col_count == 0)
// 		{
// 			ft_printf("You won with %d moves\n", game->moves);
// 			close_win(game);
// 			exit(EXIT_SUCCESS);
// 		}
// 	}
// 	player(game, new_x, new_y);
// }
