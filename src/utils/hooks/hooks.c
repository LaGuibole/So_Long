/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:15:43 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/11 16:28:39 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"
#include "../../../includes/messages.h"

int	close_win(t_game *game)
{
	cleanup(game);
	exit(EXIT_SUCCESS);
	return (0);
}

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
	mlx_clear_window(game->mlx, game->win);
	draw_map(game);
	return (0);
}
