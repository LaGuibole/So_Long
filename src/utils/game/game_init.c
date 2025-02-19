/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:56:09 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/19 17:56:06 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"
#include "../../../includes/messages.h"

/// @brief Init enemy struct to NULL or 0 before using variables
/// @param data a pointer to Enemy struct
void	init_null_enemy(t_enemy *data)
{
	data->new_x = 0;
	data->new_y = 0;
	data->x = 0;
	data->y = 0;
}

/// @brief Init game struct variables to NULL or 0
/// @param data A pointer to Game struct
void	init_null(t_game *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->grid = NULL;
	data->m_width = 0;
	data->m_height = 0;
	data->img_wall = NULL;
	data->moves = 0;
	data->tick = 0;
	data->current_dir = 0;
	data->current_frame = 0;
	data->moving = 1;
	data->spawn_space = 0;
	data->w_height = 0;
	data->w_width = 0;
	data->enemy_count = 0;
	init_null_enemy(data->enemies);
}

/// @brief Calls read_map() and check_map() to insure all is ok
/// @param game A pointer to game struct
/// @param map_file A pointer to argv[1]
/// @return
int	init_map_rules(t_game *game, char *map_file)
{
	game->map_file = map_file;
	if (read_map(game) == RET_ERR)
	{
		ft_putstr_fd(RED MSG_MAP_UNREADABLE RESET, STDERR_FILENO);
		return (RET_ERR);
	}
	if (map_check(game) == RET_ERR)
	{
		free_map(game);
		return (RET_ERR);
	}
	return (RET_OK);
}

/// @brief Init game window, managing different map sizes
/// @param game A pointer to game struct
/// @return
int	init_window(t_game *game)
{
	game->mlx = mlx_init();
	game->w_height = game->m_height * TILE_SIZE + (TILE_SIZE * 10);
	game->w_width = game->m_width * TILE_SIZE + (TILE_SIZE * 12);
	if (!game->mlx)
		return (clean_lines(game->grid, game->m_height), EXIT_FAILURE);
	if (game->m_height < 10)
	{
		game->win = mlx_new_window(game->mlx, game->w_width, game->w_height,
				"PacMan So_Long");
	}
	else
	{
		game->win = mlx_new_window(game->mlx,
				game->m_width * TILE_SIZE + (TILE_SIZE * 12),
				game->m_height * TILE_SIZE, "PacMan So_Long");
	}
	if (!game->win)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		clean_lines(game->grid, game->m_height);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/// @brief Global graphic init method
/// @param game A pointer to Game struct
void	init_graphics(t_game *game)
{
	load_images(game);
	load_score(game);
	load_sprites(game);
	load_titles(game);
	load_to_collect(game);
	load_name(game);
	global_texture_check(game);
	spawn_enemies(game);
	draw_enemies(game);
	draw_map(game);
}
