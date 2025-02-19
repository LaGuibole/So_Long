/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:38:04 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/19 16:58:14 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "../../includes/messages.h"

/// @brief A function to explain program usage
/// @param
void	usage(void)
{
	ft_putendl_fd(MSG_USAGE, STDERR_FILENO);
}

/// @brief A function that clean all game assets and exit window
/// @param game Structure containing game infos
/// @param error_msg An error message to display
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

/// @brief A global textures check
/// @param game Structure containing game infos
void	global_texture_check(t_game *game)
{
	check_pacman_texture_paths(game);
	check_map_texture_paths(game);
	check_prints_score_texture_path(game);
	check_move_title_texture_path(game);
	check_tocollect_texture_path(game);
}
