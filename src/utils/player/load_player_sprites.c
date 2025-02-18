/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_player_sprites.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:55:14 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/18 13:57:09 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"
#include "../../../includes/messages.h"

void	load_sprites(t_game *game)
{
	int	w;
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

void	draw_pacman(t_game *game, int x, int y)
{
	void	*sprite;

	sprite = game->sprites[game->current_dir][game->current_frame];
	mlx_put_image_to_window(game->mlx, game->win, sprite,
		x * TILE_SIZE, y * TILE_SIZE);
}
