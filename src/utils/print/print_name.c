/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:46:08 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/19 17:52:42 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"
#include "../../../includes/messages.h"

/// @brief Load xpm for DevName
/// @param game A pointer to the game struct
void	load_name(t_game *game)
{
	int	w;
	int	h;

	game->pr_name[0] = mlx_xpm_file_to_image(game->mlx, _L, &w, &h);
	game->pr_name[1] = mlx_xpm_file_to_image(game->mlx, _A, &w, &h);
	game->pr_name[2] = mlx_xpm_file_to_image(game->mlx, _G, &w, &h);
	game->pr_name[3] = mlx_xpm_file_to_image(game->mlx, _U, &w, &h);
	game->pr_name[4] = mlx_xpm_file_to_image(game->mlx, _I, &w, &h);
	game->pr_name[5] = mlx_xpm_file_to_image(game->mlx, _B, &w, &h);
	game->pr_name[6] = mlx_xpm_file_to_image(game->mlx, _O, &w, &h);
	game->pr_name[7] = mlx_xpm_file_to_image(game->mlx, _L, &w, &h);
	game->pr_name[8] = mlx_xpm_file_to_image(game->mlx, _E, &w, &h);
}

/// @brief Print the DevName on screen
/// @param game A pointer to the game struct
void	print_name(t_game *game)
{
	int	x_start;
	int	y_pos;
	int	i;

	x_start = (game->m_width + 1) * TILE_SIZE;
	y_pos = TILE_SIZE * 10;
	i = 0;
	while (i < 9)
	{
		if (i == 2)
			x_start += TILE_SIZE;
		mlx_put_image_to_window(game->mlx,
			game->win,
			game->pr_name[i],
			x_start + (i * TILE_SIZE),
			y_pos);
		i++;
	}
}
