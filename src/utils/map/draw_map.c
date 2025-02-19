/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:55:32 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/19 11:56:06 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"
#include "../../../includes/messages.h"

void	*get_tile_image(t_game *game, int i, int j)
{
	int		compare;
	void	*img;

	compare = 0;
	img = NULL;
	while (compare < game->enemy_count && game->spawn_space > 5 && game->m_height > 3)
	{
		if (game->enemies[compare].x == j && game->enemies[compare].y == i)
			return (game->img_enemy);
		compare++;
	}
	if (game->grid[i][j] == FREESPACE)
		img = game->img_ground;
	if (game->grid[i][j] == WALL)
		img = game->img_wall;
	if (game->grid[i][j] == PLAYER)
		img = game->sprites[game->current_dir][game->current_frame];
	if (game->grid[i][j] == COLLECTIBLE)
		img = game->img_collec;
	if (game->grid[i][j] == EXIT)
		img = game->p_sprites[game->current_frame];
	if (game->grid[i][j] == PLAYER_ON_EXIT)
		img = game->sprites[game->current_dir][game->current_frame];
	return (img);
}

void	draw_tile(t_game *game, int i, int j)
{
	void	*img;

	img = get_tile_image(game, i, j);
	if (img)
		mlx_put_image_to_window(game->mlx, game->win, img,
			j * TILE_SIZE, i * TILE_SIZE);
}

void	draw_map(t_game *game)
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
	print_title(game);
	print_col_title(game);
	print_name(game);
}

void	load_images(t_game *game)
{
	game->img_wall = mlx_xpm_file_to_image(game->mlx, WALL_IMG,
			&game->img_width, &game->img_height);
	if (!game->img_wall)
		ft_printf("Fail to load img\n");
	game->img_collec = mlx_xpm_file_to_image(game->mlx, DOT,
			&game->img_width, &game->img_height);
	if (!game->img_collec)
		ft_printf("Fail to load img\n");
	game->img_enemy = mlx_xpm_file_to_image(game->mlx, GHOST,
			&game->img_width, &game->img_height);
	game->img_ground = mlx_xpm_file_to_image(game->mlx, GROUND,
			&game->img_width, &game->img_height);
}


// void	draw_tile(t_game *game, int i, int j)
// {
// 	void	*img;
// 	int		compare;

// 	compare = 0;
// 	img = NULL;
// 	while (compare < game->enemy_count)
// 	{
// 		if (game->enemies[compare].x == j && game->enemies[compare].y == i)
// 			img = game->img_enemy;
// 		compare++;
// 	}
// 	if (game->grid[i][j] == FREESPACE)
// 		img = game->img_ground;
// 	if (game->grid[i][j] == WALL)
// 		img = game->img_wall;
// 	if (game->grid[i][j] == PLAYER)
// 		img = game->sprites[game->current_dir][game->current_frame];
// 	if (game->grid[i][j] == COLLECTIBLE)
// 		img = game->img_collec;
// 	if (game->grid[i][j] == EXIT)
// 		img = game->p_sprites[game->current_frame];
// 	if (game->grid[i][j] == PLAYER_ON_EXIT)
// 		img = game->sprites[game->current_dir][game->current_frame];
// 	if (img)
// 		mlx_put_image_to_window(game->mlx, game->win, img,
// 			j * TILE_SIZE, i * TILE_SIZE);
// }
