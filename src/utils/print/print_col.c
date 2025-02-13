/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_col.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:35:25 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/13 17:50:31 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"
#include "../../../includes/messages.h"

int    _cols_len(int collectible)
{
    int        len;

    len = 0;
    while (collectible)
    {
        collectible /= 10;
        len++;
    }
    return (len);
}

void	draw_cols(t_game *game, int number, int len)
{
	void	*img;
	img = NULL;
	img = game->score[number];
	mlx_put_image_to_window(game->mlx, game->win, img, (TILE_SIZE + 5) * (game->m_width + len), TILE_SIZE * 6 + (TILE_SIZE / 2));
}

void    put_cols(t_game *game)
{
    int	len;
	int	i;
	int	number;

    len = _cols_len(game->col_count);
	i = 0;
	number = game->col_count;
	if (game->col_count == 0)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->score[0], (TILE_SIZE + 5) * (game->m_width + len + 1), TILE_SIZE * 6 + (TILE_SIZE / 2));
		return ;
	}
	while (number != 0)
	{
		draw_cols(game, number % 10, len - i);
		number /= 10;
		++i;
	}
}
