/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:55:32 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/11 18:14:36 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"
#include "../../../includes/messages.h"

static void	draw_tile(t_game *game, int i, int j)
{
	void	*img;

	img = NULL;
	if (game->grid[i][j] == WALL)
		img = game->img_wall;
	if (game->grid[i][j] == PLAYER)
		img = game->img_pacman;
	if (img)
		mlx_put_image_to_window(game->mlx, game->win, img, j * TILE_SIZE, i * TILE_SIZE);
}

void draw_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->m_height)
	{
		j = 0;
		while (j < game->m_width)
		{
			draw_tile(game, i, j);
			j++;
		}
		i++;
	}
}

void	init_graphics(t_game *game)
{
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "./sprites/walls/wall.xpm", &game->img_width, &game->img_height);
	if (!game->img_wall)
		ft_printf("Fail to load img");
	load_sprites(game);
}
