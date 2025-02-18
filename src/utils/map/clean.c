/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:39:28 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/18 18:17:47 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"
#include "../../../includes/messages.h"

/// @brief Free the memory allocated for the game map grid
/// @param map Pointer to the game structure containing the map
void	free_map(t_game *map)
{
	int	i;

	i = 0;
	if (map->grid != NULL)
	{
		while (i < map->m_height)
		{
			free(map->grid[i]);
			i++;
		}
		free(map->grid);
		map->grid = NULL;
	}
}

/// @brief Frees memory allocated for 2D map array
/// @param map Pointer to the 2D array of strings
/// @param height Number of rows in the map
void	clean_lines(char **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		if (map[i])
			free(map[i]);
		i++;
	}
	free(map);
}

/// @brief Destroy int tabs that contain multiple sprites
/// @param game
void	clean_sprites(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 3)
		{
			if (game->sprites[i][j])
				mlx_destroy_image(game->mlx, game->sprites[i][j]);
			j++;
		}
		i++;
	}
}

/// @brief Destroy int tab that contain sprites
/// @param game
void	clean_single_sprite(t_game *game)
{
	int	i;

	i = 0;
	while (i < 3)
		mlx_destroy_image(game->mlx, game->p_sprites[i++]);
	i = 0;
	while (i < 5)
		mlx_destroy_image(game->mlx, game->pr_moves[i++]);
	i = 0;
	while (i < 9)
	{
		mlx_destroy_image(game->mlx, game->pr_cols[i]);
		mlx_destroy_image(game->mlx, game->pr_name[i++]);
	}
	i = 0;
	while (i < 10)
		mlx_destroy_image(game->mlx, game->score[i++]);
}

/// @brief Main cleanup function to free all assets before exit
/// @param game
void	cleanup(t_game *game)
{
	clean_lines(game->grid, game->m_height);
	game->grid = NULL;
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_collec)
		mlx_destroy_image(game->mlx, game->img_collec);
	if (game->img_ground)
		mlx_destroy_image(game->mlx, game->img_ground);
	if (game->img_enemy)
		mlx_destroy_image(game->mlx, game->img_enemy);
	if (game->sprites)
		clean_sprites(game);
	if (game->p_sprites || game->pr_moves || game->score || game->pr_cols)
		clean_single_sprite(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
}
