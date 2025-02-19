/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:38:04 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/19 12:57:18 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "../../includes/messages.h"

void	usage(void)
{
	ft_putendl_fd(MSG_USAGE, STDERR_FILENO);
}

/// @brief
/// @param game
/// @param error_msg
void	clean_and_exit(t_game *game, char *error_msg)
{
	if (!error_msg)
	{
		cleanup(game);
		ft_putstr_fd("Error :\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	cleanup(game);
	ft_putstr_fd(error_msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

/// @brief
/// @param game
void	global_texture_check(t_game *game)
{
	check_pacman_texture_paths(game);
	check_map_texture_paths(game);
	check_prints_score_texture_path(game);
	check_move_title_texture_path(game);
	check_tocollect_texture_path(game);
}
