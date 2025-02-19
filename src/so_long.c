/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:56:32 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/19 12:52:23 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"
# include "../includes/messages.h"

int	main(int argc, char **argv)
{
	t_game game;

	if (argc != 2)
	{
		usage();
		return (1);
	}
	init_null(&game);
	game.map_file = argv[1];
	if (init_map_rules(&game, argv[1]) == RET_ERR)
		return (RET_ERR);
	if (init_window(&game) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	init_graphics(&game);
	draw_map(&game);
	mlx_key_hook(game.win, key_hooks, &game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_hook(game.win, 17, 0, close_win, &game);
	mlx_loop(game.mlx);
	free_map(&game);
	return (0);
}

