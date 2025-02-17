/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:00:27 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/17 17:05:16 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"
#include "../../../includes/messages.h"

int	choose_enemy_direction(void)
{
	return (rand() % 4);
}

void	calculate_new_position(t_enemy *enemy)
{
	enemy->new_x = enemy->x;
	enemy->new_y = enemy->y;

	if (enemy->direction == 0)
		enemy->new_y -= 1;
	else if (enemy->direction == 1)
		enemy->new_y += 1;
	else if (enemy->direction == 2)
		enemy->new_x -= 1;
	else if (enemy->direction == 3)
		enemy->new_x += 1;
}
int	is_enemy_at_position(t_enemy *enemy, int count, int index, int x, int y)
{
	if (index >= count)
		return (0);
	if (enemy[index].x == x && enemy[index].y == y)
		return (1);
	return is_enemy_at_position(enemy, count, index + 1, x, y);
}

int is_valid_position(t_game *game, t_enemy *enemy, int index)
{
    if (game->grid == NULL || enemy->new_y < 0 || enemy->new_y >= game->m_height ||
        enemy->new_x < 0 || enemy->new_x >= game->m_width)
	{
        return (0);
	}
    if (game->grid[enemy->new_y][enemy->new_x] == WALL ||
        game->grid[enemy->new_y][enemy->new_x] == EXIT)
    {
        return (0);
	}
	if (is_enemy_at_position(game->enemies, game->enemy_count, index, enemy->new_x, enemy->new_y))
	{
        return (0);
	}
	return (1);
}

int attempt_move_enemy(t_game *game, t_enemy *enemy, int attempt_count)
{
	if (attempt_count > 10)
		return (0);
	enemy->direction = choose_enemy_direction();
	calculate_new_position(enemy);

	if (is_valid_position(game, enemy, 0))
		return (1);
	return attempt_move_enemy(game, enemy, attempt_count + 1);
}

// void	move_enemies(t_game *game)
// {
// 	int	i;

// 	i = 0;
// 	while (i < game->enemy_count)
// 	{
// 		t_enemy *enemy = &game->enemies[i];

// 		enemy->old_x = enemy->x;
// 		enemy->old_y = enemy->y;

// 		if (attempt_move_enemy(game, enemy, 0))
// 		{
// 			enemy->x = enemy->new_x;
// 			enemy->y = enemy->new_y;
// 		}
// 		i++;
// 	}
// }

void	move_enemies(t_game *game, int index)
{
	if (index >= game->enemy_count)
		return;

	t_enemy *enemy = &game->enemies[index];

	enemy->old_x = enemy->x;
	enemy->old_y = enemy->y;
	if (attempt_move_enemy(game, enemy, 0))
	{
		enemy->x = enemy->new_x;
		enemy->y = enemy->new_y;
		if (enemy->x == game->player_x && enemy->y == game->player_y)
		{
			ft_printf("Game Over, Pac-Man got caught!\n");
			close_win(game);
			exit(EXIT_SUCCESS);
		}
	}
	move_enemies(game, index + 1);
}
