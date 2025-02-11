/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:05:46 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/11 16:43:56 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"
#include "../../../includes/messages.h"

static void	player(t_game *game, int new_x, int new_y)
{
	if (game->grid[game->player_y][game->player_x] == PLAYER_ON_EXIT)
		game->grid[game->player_y][game->player_x] = EXIT;
	else
		game->grid[game->player_y][game->player_x] = FREESPACE;
	if (game->grid[new_y][new_x] == EXIT)
		game->grid[new_y][new_x] = PLAYER_ON_EXIT;
	else
		game->grid[new_y][new_x] = PLAYER;
	game->player_y = new_y;
	game->player_x = new_x;
}

void	move_player(t_game *game, int gx, int gy)
{
	int	new_x;
	int	new_y;

	find_player(game);
	new_x = game->player_x + gx;
	new_y = game->player_y + gy;
	if (new_x < 0 || new_x >= game->m_width || new_y >= game->m_height
		|| game->grid[new_y][new_x] == WALL)
		return ;
	if (game->grid[new_y][new_x] == COLLECTIBLE)
	{
		game->grid[new_y][new_x] = FREESPACE;
		game->col_count -= 1;
	}
	game->moves++;
	ft_printf("moves : %d\n", game->moves);
	if (game->grid[new_y][new_x] == EXIT)
	{
		if (game->col_count == 0)
		{
			ft_printf("You won with %d moves\n", game->moves);
			close_win(game);
			exit(EXIT_SUCCESS);
		}
	}
	player(game, new_x, new_y);
}
