/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:38:04 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/18 19:19:19 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "../../includes/messages.h"

void	clean_and_exit(t_game *game, char *error_msg)
{
	(void)error_msg;
	cleanup(game);
	exit(EXIT_FAILURE);
}

void	global_texture_check(t_game *game)
{
	check_pacman_texture_paths(game);
	check_map_texture_paths(game);
	check_prints_score_texture_path(game);
	check_move_title_texture_path(game);
	check_tocollect_texture_path(game);
}
