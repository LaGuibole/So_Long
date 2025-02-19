/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:56:09 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/19 12:32:16 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"
#include "../../../includes/messages.h"

void	init_null_enemy(t_enemy *data)
{
	data->new_x = 0;
	data->new_y = 0;
	data->x = 0;
	data->y = 0;
}
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
	init_null_enemy(data->enemies);
}

int	init_map_rules(t_game *game, char *map_file)
{
	game->map_file = map_file;
	if (read_map(game) == RET_ERR)
	{
		ft_putstr_fd(RED MAP_UNREADABLE RESET, STDERR_FILENO);
		return (RET_ERR);
	}
	if (map_check(game) == RET_ERR)
	{
		free_map(game);
		return (RET_ERR);
	}
	return (RET_OK);
}

int	init_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		clean_lines(game->grid, game->m_height);
		return (EXIT_FAILURE);
	}
	game->win = mlx_new_window(game->mlx,
		game->m_width * TILE_SIZE + (TILE_SIZE * 12),
		game->m_height * TILE_SIZE,
		"PacMan So_Long");
	if (!game->win)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		clean_lines(game->grid, game->m_height);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

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
