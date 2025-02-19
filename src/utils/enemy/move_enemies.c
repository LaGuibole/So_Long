/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:00:27 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/19 17:02:44 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"
#include "../../../includes/messages.h"

/// @brief Calculate enemy's position before moving
/// @param enemy A pointer to enemy struct
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

/// @brief Check if an enemy is already on the calculated tile
/// @param enemy A pointer to enemy struct
/// @param count Enemy count
/// @param x x axis on map
/// @param y y axis on map
/// @return 0 if no enemy was found 1 otherwise
int	is_enemy_at_position(t_enemy *enemy, int count, int x, int y)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (enemy[i].x == x && enemy[i].y == y)
			return (RET_ERR);
		i++;
	}
	return (RET_OK);
}

/// @brief Check if the enemy position is valid on the map
/// @param game A pointer to game structure
/// @param enemy A pointer to enemy structure
/// @return
int	is_valid_position(t_game *game, t_enemy *enemy)
{
	if (game->grid == NULL || enemy->new_y < 0 || enemy->new_y >= game->m_height
		|| enemy->new_x < 0 || enemy->new_x >= game->m_width)
	{
		return (RET_OK);
	}
	if (game->grid[enemy->new_y][enemy->new_x] == WALL
		|| game->grid[enemy->new_y][enemy->new_x] == EXIT)
	{
		return (RET_OK);
	}
	if (is_enemy_at_position(game->enemies,
			game->enemy_count, enemy->new_x, enemy->new_y))
	{
		return (RET_OK);
	}
	return (RET_ERR);
}

/// @brief A function to attempt an enemy move
/// @param game A pointer to game struct
/// @param enemy A pointer to enemy struct
/// @param attempt_count An attempt count to avoid overflows
/// @return
int	attempt_move_enemy(t_game *game, t_enemy *enemy, int attempt_count)
{
	if (attempt_count > 10)
		return (RET_OK);
	enemy->direction = choose_enemy_direction();
	calculate_new_position(enemy);
	if (is_valid_position(game, enemy))
		return (RET_ERR);
	return (attempt_move_enemy(game, enemy, attempt_count + 1));
}

/// @brief A function that moves the enemy
/// @param game A pointer to game struct
/// @param index An iterator to apply moves to all enemies
void	move_enemies(t_game *game, int index)
{
	t_enemy	*enemy;

	if (index >= game->enemy_count)
		return ;
	enemy = &game->enemies[index];
	enemy->old_x = enemy->x;
	enemy->old_y = enemy->y;
	if (attempt_move_enemy(game, enemy, 0))
	{
		enemy->x = enemy->new_x;
		enemy->y = enemy->new_y;
		if (enemy->x == game->player_x && enemy->y == game->player_y)
		{
			ft_putstr_fd(MSG_GAME_OVER, STDOUT_FILENO);
			close_win(game);
			exit(EXIT_SUCCESS);
		}
	}
	move_enemies(game, index + 1);
}
