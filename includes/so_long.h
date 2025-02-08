/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:47:08 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/08 17:17:58 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// INCLUDES

# include "libft.h"
# include "fcntl.h"

// DEFINES

# define RET_OK	0
# define RET_ERR 1
# define RET_NEG_ERR -1
# define BAD_ARG_MSD "Error : Bad Argument\n"
# define USAGE "Usage : ./so_long <file.ber>\n"

// MAPS DEFINE

# define MAP_IS_OK 0
# define MAP_NOT_OK 1

// COLORS

# define RED "\033[31m"
# define BLUE "\033[34m"
# define GREEN "\033[32m"
# define RESET "\033[0m"

// STRUCTURES

typedef struct s_solong
{

}	t_solong;

typedef struct s_game
{
	char	*map_file;
	char	**grid;
	int		width;
	int		height;
	int		player_count;
	int		collectible_count;
	int		exit_count;
	int		player_x;
	int		player_y;
} t_game;



// FUNCTIONS

// ERRORS
void	usage(void);

// MAPS

int		check_first_last(char *line, int len);
int		check_middle(char *line, int len);
int		is_map_closed(char *map_file);

int		has_ber_extension(t_game *map_assets);
int		is_rectangular (t_game *map);
int		read_map(t_game *map);
void	free_map(t_game *map);
void	copy_map(t_game *original, t_game *copy);
int		is_bordered_with_walls(t_game *map);
int		has_required_elements(t_game *map);
int		is_path_valid(t_game *original);
void	find_player(t_game *map);

#endif
