/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:47:08 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/13 17:47:43 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// INCLUDES

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <sys/time.h>
# include <time.h>

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
# define MAX_ENEMIES 4

// IMG DEFINE

# define WALL '1'
# define P_L_C "./sprites/pacman/pacman_left_closed.xpm"
# define P_L_S "./sprites/pacman/pacman_left_semi.xpm"
# define P_L_O "./sprites/pacman/pacman_left_open.xpm"
# define P_R_C "./sprites/pacman/pacman_right_closed.xpm"
# define P_R_S "./sprites/pacman/pacman_right_semi.xpm"
# define P_R_O "./sprites/pacman/pacman_right_open.xpm"
# define P_U_C "./sprites/pacman/pacman_up_closed.xpm"
# define P_U_S "./sprites/pacman/pacman_up_semi.xpm"
# define P_U_O "./sprites/pacman/pacman_up_open.xpm"
# define P_D_C "./sprites/pacman/pacman_down_closed.xpm"
# define P_D_S "./sprites/pacman/pacman_down_semi.xpm"
# define P_D_O "./sprites/pacman/pacman_down_open.xpm"
# define DOT	"./sprites/others/dot.xpm"
# define P1		"./sprites/portal/portal1.xpm"
# define P2		"./sprites/portal/portal2.xpm"
# define P3		"./sprites/portal/portal3.xpm"
# define P_0	"./sprites/others/0.xpm"
# define P_1	"./sprites/others/1.xpm"
# define P_2	"./sprites/others/2.xpm"
# define P_3	"./sprites/others/3.xpm"
# define P_4	"./sprites/others/4.xpm"
# define P_5	"./sprites/others/5.xpm"
# define P_6	"./sprites/others/6.xpm"
# define P_7	"./sprites/others/7.xpm"
# define P_8	"./sprites/others/8.xpm"
# define P_9	"./sprites/others/9.xpm"
# define _A		"./sprites/others/A.xpm"
# define _B		"./sprites/others/B.xpm"
# define _C		"./sprites/others/C.xpm"
# define _E		"./sprites/others/E.xpm"
# define _G		"./sprites/others/G.xpm"
# define _I		"./sprites/others/I.xpm"
# define _L		"./sprites/others/L.xpm"
# define _M		"./sprites/others/M.xpm"
# define _O		"./sprites/others/O.xpm"
# define _V		"./sprites/others/V.xpm"
# define _E		"./sprites/others/E.xpm"
# define _S		"./sprites/others/S.xpm"
# define _U		"./sprites/others/U.xpm"
# define _T		"./sprites/others/T.xpm"
# define GHOST	"./sprites/others/apple.xpm"




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
	int		exit_x;
	int		exit_y;
	int		moves;

	void	*mlx;
	void	*win;
	void	*img_wall;
	void	*img_collec;
	void	*score[10];
	void	*sprites[4][3];
	void	*p_sprites[3];
	void	*pr_moves[5];
	void	*cols[10];
	void	*pr_cols[9];
	void	*pr_name[9];
	int		img_width;
	int		img_height;

	int		current_dir;
	int		current_frame;

	int		moving;
	int		tick;
	int		new_x;
	int		new_y;

	int		print_x;
	int		print_y;

	int		enemy_x[MAX_ENEMIES];
	int		enemy_y[MAX_ENEMIES];
	int		enemy_count;
	void	*img_enemy;
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

int		animate_pacman(t_game *game);
void	load_sprites(t_game *game);

void	draw_pacman(t_game *game, int x, int y);
void	draw_tile(t_game *game, int i, int j);

void    put_score(t_game *game);
void	load_score(t_game *game);
void	load_titles(t_game *game);
void	print_title(t_game *game);

void    put_cols(t_game *game);

void	print_col_title(t_game *game);
void	load_to_collect(t_game *game);

void	load_name(t_game *game);
void	print_name(t_game *game);

void	draw_enemies(t_game *game);
void	spawn_enemies(t_game *game);

#endif
