/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:15:43 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/11 11:31:48 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"
#include "../../../includes/messages.h"

int	close_win(t_game *game)
{
	cleanup(game);
	exit(EXIT_SUCCESS);
	return (0);
}

int	key_hooks(int keycode, t_game *game)
{
	if (keycode == ESC)
		close_win(game);
	return (0);
}
