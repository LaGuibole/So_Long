/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_titles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:54:20 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/18 11:39:29 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"
#include "../../../includes/messages.h"

void	load_titles(t_game *game)
{
	int	w;
	int	h;

	game->pr_moves[0] = mlx_xpm_file_to_image(game->mlx, _M, &w, &h);
	game->pr_moves[1] = mlx_xpm_file_to_image(game->mlx, _O, &w, &h);
	game->pr_moves[2] = mlx_xpm_file_to_image(game->mlx, _V, &w, &h);
	game->pr_moves[3] = mlx_xpm_file_to_image(game->mlx, _E, &w, &h);
	game->pr_moves[4] = mlx_xpm_file_to_image(game->mlx, _S, &w, &h);
}

/// @brief
/// @param game
void	load_to_collect(t_game *game)
{
	int	w;
	int	h;

	game->pr_cols[0] = mlx_xpm_file_to_image(game->mlx, _T, &w, &h);
	game->pr_cols[1] = mlx_xpm_file_to_image(game->mlx, _O, &w, &h);
	game->pr_cols[2] = mlx_xpm_file_to_image(game->mlx, _C, &w, &h);
	game->pr_cols[3] = mlx_xpm_file_to_image(game->mlx, _O, &w, &h);
	game->pr_cols[4] = mlx_xpm_file_to_image(game->mlx, _L, &w, &h);
	game->pr_cols[5] = mlx_xpm_file_to_image(game->mlx, _L, &w, &h);
	game->pr_cols[6] = mlx_xpm_file_to_image(game->mlx, _E, &w, &h);
	game->pr_cols[7] = mlx_xpm_file_to_image(game->mlx, _C, &w, &h);
	game->pr_cols[8] = mlx_xpm_file_to_image(game->mlx, _T, &w, &h);
}

void	print_title(t_game *game)
{
	int	x_start;
	int	y_pos;
	int	i;

	x_start = (game->m_width + 4) * TILE_SIZE;
	y_pos = TILE_SIZE;
	i = 0;
	while (i < 5)
	{
		mlx_put_image_to_window(game->mlx,
			game->win,
			game->pr_moves[i],
			x_start + (i * TILE_SIZE),
			y_pos);
		i++;
	}
}

void	print_col_title(t_game *game)
{
	int	x_start;
	int	y_pos;
	int	i;

	x_start = (game->m_width + 1) * TILE_SIZE;
	y_pos = TILE_SIZE * 5;
	i = 0;
	while (i < 9)
	{
		if (i == 2)
			x_start += TILE_SIZE;
		mlx_put_image_to_window(game->mlx,
			game->win,
			game->pr_cols[i],
			x_start + (i * TILE_SIZE),
			y_pos);
		i++;
	}
}
