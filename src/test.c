/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:56:32 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/17 16:09:48 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"
# include "../includes/messages.h"

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
int	main(int argc, char **argv)
{
	t_game game;

	if (argc != 2)
		return 1;
	init_null(&game);
	game.map_file = argv[1];
	if (read_map(&game) == RET_ERR)
	{
		ft_printf(RED MAP_UNREADABLE RESET);
		return (RET_ERR);
	}
	if (map_check(&game) == RET_ERR)
	{
		free_map(&game);
		return (RET_ERR);
	}
	game.mlx = mlx_init();
	if (!game.mlx)
	{
		clean_lines(game.grid, game.m_height);
		return(EXIT_FAILURE);
	}
	game.win = mlx_new_window(game.mlx, game.m_width * TILE_SIZE + (TILE_SIZE * 12), game.m_height * TILE_SIZE, "solong");
	init_graphics(&game);
	draw_map(&game);
	mlx_key_hook(game.win, key_hooks, &game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_hook(game.win, 17, 0, close_win, &game);
	mlx_loop(game.mlx);
	free_map(&game);
	return (0);
}

