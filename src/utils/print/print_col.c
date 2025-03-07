/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_col.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:35:25 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/19 17:52:02 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"
#include "../../../includes/messages.h"

/// @brief Calculate the digits to print
/// @param collectible Number of collectible
/// @return Digits len
int	_cols_len(int collectible)
{
	int	len;

	len = 0;
	while (collectible)
	{
		collectible /= 10;
		len++;
	}
	return (len);
}

/// @brief
/// @param game
/// @param number
/// @param len
void	draw_cols(t_game *game, int number, int len)
{
	void	*img;

	img = NULL;
	img = game->score[number];
	mlx_put_image_to_window(game->mlx,
		game->win, img,
		TILE_SIZE * (game->m_width + len + 5),
		TILE_SIZE * 6 + (TILE_SIZE / 2));
}

/// @brief Hide 0 o fputnbr
/// @param game A pointer to game struct
/// @param len Digit len of collectible count
void	clear_old_score(t_game *game, int len)
{
	int	i;

	i = 0;
	while (i < len + 1)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_ground,
			TILE_SIZE * (game->m_width + i + 7),
			TILE_SIZE * 6 + (TILE_SIZE / 2));
		i++;
	}
}

/// @brief Prints collectible
/// @param game A pointer to game struct
void	put_cols(t_game *game)
{
	int	len;
	int	i;
	int	number;

	len = _cols_len(game->col_count);
	number = game->col_count;
	clear_old_score(game, len);
	i = 0;
	if (number == 0)
	{
		mlx_put_image_to_window(game->mlx,
			game->win, game->score[0],
			TILE_SIZE * (game->m_width + len - 1 + 7),
			TILE_SIZE * 6 + (TILE_SIZE / 2));
		return ;
	}
	while (number != 0)
	{
		draw_cols(game, number % 10, len - i);
		number /= 10;
		++i;
	}
}
