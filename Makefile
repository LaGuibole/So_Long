# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/04 13:50:50 by guphilip          #+#    #+#              #
#    Updated: 2025/02/19 16:42:17 by guphilip         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#COLORS

BLUE				= 		\033[1;34m
GREEN				= 		\033[1;32m
YELLOW				=		\033[1;33m
CYAN				=		\033[1;36m
RESET				= 		\033[0m

# COMMANDS

RM					=		/usr/bin/rm -fr
ECHO				=		/usr/bin/echo
RM_LINE 			= 		@tput cuu1 && tput el

# FLAGS && COMPIL

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
LIBFLAGS = -L/usr/lib -lX11 -lXext -lXrandr -lXi -lXinerama -lXcursor -lm
IFLAGS = -I$(INC_DIR)

# DIRECTORIES

SRC_DIR 			=		src
INC_DIR				=		includes
LIB_DIR				=		libs
OBJ_DIR				= 		obj

# SO_LONG

SRC_FILES 			=		so_long \
							utils/map/clean \
							utils/map/read_map \
							utils/map/copy_map \
							utils/map/check_map \
							utils/map/flood_fill \
							utils/hooks/hooks \
							utils/map/draw_map \
							utils/player/move_player \
							utils/print/print_score \
							utils/print/print_titles \
							utils/print/print_col \
							utils/print/print_name \
							utils/enemy/spawn_enemy \
							utils/enemy/move_enemies \
							utils/player/load_player_sprites \
							utils/game/game_init \
							errors/errors \
							errors/manage_errors 
SRCS				=		$(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC_FILES)))
OBJS				=		$(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SRC_FILES)))

# MINILIBX

MLX_DIR				=		minilibx-linux
MLX_PATH			=		$(LIB_DIR)/$(MLX_DIR)
MLX_H				=		mlx.h
MLX_INC_H			=		$(INC_DIR)/$(MLX_H)
MLX_H_PATH			=		$(MLX_PATH)/$(MLX_H)
MLX_TARGET			=		libmlx.a
MLX_GIT				=		https://github.com/42Paris/minilibx-linux.git
MLX_TARGET_PATH		=		$(MLX_PATH)/$(MLX_TARGET)

#TARGET

NAME				=		so_long
LIB_TARGET			=		$(LIBFT_TARGET) $(MLX_TARGET)

# LIBFT COMPILATION

LIBFT_GIT			= 		https://github.com/LaGuibole/Libft_Boosted.git
LIBFT_DIR			= 		Libft_Boosted
LIBFT_PATH			= 		$(LIB_DIR)/$(LIBFT_DIR)
LIBFT_H				= 		libft.h
LIBFT_H_PATH		= 		$(LIBFT_PATH)/includes/$(LIBFT_H)
LIBFT_INC_H			= 		$(INC_DIR)/$(LIBFT_H)
LIBFT_TARGET		= 		libft.a
LIBFT_TARGET_PATH	= 		$(LIBFT_PATH)/$(LIBFT_TARGET)

all:						$(NAME)

fr: CFLAGS += -DLANG_FR
fr: re

clean:
							@$(RM) -r $(OBJ_DIR)

fclean: clean
							@$(RM) $(NAME)
							@$(RM) $(LIBFT_TARGET)
							@$(RM) $(LIBFT_INC_H)
							@$(RM) $(MLX_TARGET)
							@$(RM) $(MLX_INC_H)

re: fclean all

cleanlibs:
							@$(MAKE) clean --no-print-directory -C $(LIBFT_PATH)
							@$(MAKE) clean --no-print-directory -C $(MLX_PATH)

fcleanlibs: fclean
							@$(RM) -r $(LIBFT_PATH)
							@$(RM) -r $(MLX_PATH)

relibs: fcleanlibs $(LIBFT_INC_H) $(MLX_INC_H)

norminette:
							@norminette $(SRC_DIR) $(BONUS_SRC) $(INC_DIR) | grep -Ev '^Notice|OK!$$'	\
							&& $(ECHO) -e '\033[1;31mNorminette KO!'						\
							|| $(ECHO) -e '\033[1;32mNorminette OK!'

.PHONY: all re clean fclean cleanlibs fcleanlibs relibs norminette fr

$(LIBFT_INC_H): $(LIBFT_TARGET)
							@cp $(LIBFT_H_PATH) $@

$(LIBFT_TARGET):
							@if [ ! -d "$(LIBFT_PATH)/.git" ]; then \
								printf "Cloning lib \"%s\" into \"%s\"..." $(LIBFT_GIT) $(LIBFT_PATH);\
								git clone $(LIBFT_GIT) $(LIBFT_PATH);\
							fi
							@printf "\nMaking \"%s\"..." $@
							@$(MAKE) --no-print-directory -C $(LIBFT_PATH)
							@cp $(LIBFT_TARGET_PATH) ./
							@printf "\n✅ Done copying archive $(GREEN) \"%s\" $(RESET)... \n\n" $@

# MINILIBX COMPILATION

$(MLX_INC_H): $(MLX_TARGET)
							@cp $(MLX_H_PATH) $@

$(MLX_TARGET):
							@if [ ! -d "$(MLX_PATH)/.git" ]; then \
								printf "Cloning lib \"%s\" into \"%s\"..." $(MLX_GIT) $(MLX_PATH);\
								git clone $(MLX_GIT) $(MLX_PATH);\
							fi
							@printf "Making \"%s\"..." $@
							@$(MAKE) --no-print-directory -C $(MLX_PATH) > /dev/null 2>&1
							@printf "\n\n"
							@cp $(MLX_TARGET_PATH) ./
							@printf "✅ Done copying archive $(GREEN) \"%s\" $(RESET)... \n\n" $@

# SO_LONG TARGET

$(NAME): $(LIBFT_INC_H) $(MLX_INC_H) $(OBJS)
							@$(CC) $(CFLAGS) $(IFLAGS) -o $(NAME) $(OBJS) $(LIBFT_TARGET) $(MLX_TARGET) $(LIBFLAGS)
							@echo "🎉 Executable$(BLUE) $(NAME) $(RESET)created. \n"

# OBJ DIR

$(OBJ_DIR):
							@mkdir -p $(OBJ_DIR)

# .O FILE COMPILATION

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
							@echo "⚙️ Compiling $< into $@ ...\n"
							@${RM_LINE}
							@mkdir -p $(dir $@)
							@$(CC) -I$(IFLAGS) $(CFLAGS) -c $< -o $@
							@${RM_LINE}

