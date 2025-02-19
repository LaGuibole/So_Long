/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:15:43 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/19 17:09:02 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"
#include "../../../includes/messages.h"

/// @brief Manage window closing
/// @param game A pointer to game struct
/// @return
int	close_win(t_game *game)
{
	cleanup(game);
	exit(EXIT_SUCCESS);
	return (RET_OK);
}

/// @brief Manage player inputs for movements
/// @param keycode Hold movement input key
/// @param game A pointer to game struct
/// @return
int	key_hooks(int keycode, t_game *game)
{
	if (keycode == ESC)
		close_win(game);
	else if (keycode == W || keycode == UP)
		move_player(game, 0, -1);
	else if (keycode == A || keycode == LEFT)
		move_player(game, -1, 0);
	else if (keycode == S || keycode == DOWN)
		move_player(game, 0, 1);
	else if (keycode == D || keycode == RIGHT)
		move_player(game, 1, 0);
	draw_map(game);
	put_score(game);
	put_cols(game);
	return (RET_OK);
}

/// @brief Main game loop, called into mlx_loop_hook()
/// @param param A pointer to game struct
/// @return
int	game_loop(void	*param)
{
	t_game	*game;

	game = (t_game *)param;
	animate_pacman(game);
	if (game->enemy_count != 0)
	{
		animate_ghosts(game);
		refresh_enemies(game);
	}
	return (RET_OK);
}
