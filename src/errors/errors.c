/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:00:46 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/18 19:16:35 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "../../includes/messages.h"

void	check_pacman_texture_paths(t_game *game)
{
	char	*textures[13];
	int	i;

	textures[0] = P_L_C;
	textures[1] = P_L_S;
	textures[2] = P_L_O;
	textures[3] = P_R_C;
	textures[4] = P_R_S;
	textures[5] = P_R_O;
	textures[6] = P_U_C;
	textures[7] = P_U_S;
	textures[8] = P_U_O;
	textures[9] = P_D_C;
	textures[10] = P_D_S;
	textures[11] = P_D_O;
	textures[12] = NULL;
	i = 0;
	while (textures[i] != NULL)
	{
		if (access(textures[i++], F_OK) != 0)
		{
			clean_and_exit(game, "Error :\nA pacman texture is missing");
		}
	}
}

void	check_map_texture_paths(t_game *game)
{
	char	*textures[8];
	int	i;

	textures[0] = WALL_IMG;
	textures[1] = GROUND;
	textures[2] = DOT;
	textures[3] = P1;
	textures[4] = P2;
	textures[5] = P3;
	textures[6] = GHOST;
	textures[7] = NULL;
	i = 0;
	while (textures[i] != NULL)
	{
		if (access(textures[i++], F_OK) != 0)
		{
			clean_and_exit(game, "Error :\n A map texture is missing");
		}
	}
}

void	check_prints_score_texture_path(t_game *game)
{
	char	*textures[11];
	int	i;

	textures[0] = P_0;
	textures[1] = P_1;
	textures[2] = P_2;
	textures[3] = P_3;
	textures[4] = P_4;
	textures[5] = P_5;
	textures[6] = P_6;
	textures[7] = P_7;
	textures[8] = P_8;
	textures[9] = P_9;
	textures[10] = NULL;
	while (textures[i] != NULL)
	{
		if (access(textures[i++], F_OK) != 0)
		{
			clean_and_exit(game, "Error :\nA score texture is missing");
		}
	}
}

void	check_move_title_texture_path(t_game *game)
{
	char	*textures[6];
	int	i;

	textures[0] = _M;
	textures[1] = _O;
	textures[2] = _V;
	textures[3] = _E;
	textures[4] = _S;
	textures[5] = NULL;
	while (textures[i] != NULL)
	{
		if (access(textures[i++], F_OK) != 0)
		{
			clean_and_exit(game, "Error :\nA move title texture is missing");
		}
	}
}

void	check_tocollect_texture_path(t_game *game)
{
	char	*textures[9];
	int	i;

	textures[0] = _A;
	textures[1] = _B;
	textures[2] = _C;
	textures[3] = _G;
	textures[4] = _I;
	textures[5] = _L;
	textures[6] = _U;
	textures[7] = _T;
	textures[8] = NULL;
	while (textures[i] != NULL)
	{
		if (access(textures[i++], F_OK) != 0)
		{
			clean_and_exit(game, "Error :\nA To Collect texture is missing");
		}
	}
}
