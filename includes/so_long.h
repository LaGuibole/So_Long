/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:47:08 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/11 16:34:00 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// INCLUDES

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>

// DEFINES

# define RET_OK	0
# define RET_ERR 1
# define RET_NEG_ERR -1
# define BAD_ARG_MSD "Error : Bad Argument\n"
# define TILE_SIZE 32
# define PLAYER 'P'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER_ON_EXIT 'X'
# define FREESPACE '0'

// IMG DEFINE

# define WALL '1'

// HOOKS DEFINE

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define UP 65362
# define LEFT 65361
# define RIGHT 65363
# define DOWN 65364

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
	int		m_width;
	int		m_height;
	int		player_count;
	int		col_count;
	int		exit_count;
	int		player_x;
	int		player_y;
	int		moves;

	void	*mlx;
	void	*win;
	void	*img_wall;
	void	*img_pacman;
	int		img_width;
	int		img_height;
} t_game;

// typedef enum s_state
// {
// 	FOPEN,
// 	OPEN,
// 	CLOSE
// }	t_state;

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
int		has_valid_elements(t_game *map);
int		has_required_elements(t_game *map);
int		is_path_valid(t_game *original);
void	find_player(t_game *map);
int		map_check(t_game *map);

void	clean_lines(char **map, int height);
void	cleanup(t_game *game);

int		key_hooks(int keycode, t_game *game);
int		close_win(t_game *game);

void 	draw_map(t_game *game);
void	init_graphics(t_game *game);

void	move_player(t_game *game, int gx, int gy);

#endif
