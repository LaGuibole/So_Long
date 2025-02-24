/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_score.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:30:03 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/19 17:54:19 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"
#include "../../../includes/messages.h"

/// @brief Load digits (0 - 9)
/// @param game A pointer to the game struct
void	load_score(t_game *game)
{
	int	w;
	int	h;

	game->score[0] = mlx_xpm_file_to_image(game->mlx, P_0, &w, &h);
	game->score[1] = mlx_xpm_file_to_image(game->mlx, P_1, &w, &h);
	game->score[2] = mlx_xpm_file_to_image(game->mlx, P_2, &w, &h);
	game->score[3] = mlx_xpm_file_to_image(game->mlx, P_3, &w, &h);
	game->score[4] = mlx_xpm_file_to_image(game->mlx, P_4, &w, &h);
	game->score[5] = mlx_xpm_file_to_image(game->mlx, P_5, &w, &h);
	game->score[6] = mlx_xpm_file_to_image(game->mlx, P_6, &w, &h);
	game->score[7] = mlx_xpm_file_to_image(game->mlx, P_7, &w, &h);
	game->score[8] = mlx_xpm_file_to_image(game->mlx, P_8, &w, &h);
	game->score[9] = mlx_xpm_file_to_image(game->mlx, P_9, &w, &h);
}

/// @brief Calculate moves count digit len
/// @param score game->moves_count
/// @return
int	_score_len(int score)
{
	int	len;

	len = 0;
	while (score)
	{
		score /= 10;
		len++;
	}
	return (len);
}

/// @brief Print score on screen
/// @param game A pointer to game struct
/// @param number game->moves_count
/// @param len Digits len
void	draw_score(t_game *game, int number, int len)
{
	void	*img;

	img = NULL;
	img = game->score[number];
	mlx_put_image_to_window(game->mlx, game->win,
		img, (TILE_SIZE + 6) * (game->m_width + len),
		TILE_SIZE * 3 - (TILE_SIZE / 2));
}

/// @brief Print score on screen dynamically
/// @param game A pointer to the game struct
void	put_score(t_game *game)
{
	int	len;
	int	i;
	int	number;

	len = _score_len(game->moves);
	i = 0;
	number = game->moves;
	while (number != 0)
	{
		draw_score(game, number % 10, len - i);
		number /= 10;
		++i;
	}
}
