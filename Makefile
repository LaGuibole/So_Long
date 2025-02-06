# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/04 13:50:50 by guphilip          #+#    #+#              #
#    Updated: 2025/02/06 15:53:23 by guphilip         ###   ########.fr        #
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
IFLAGS = -I$(INC_DIR)

# DIRECTORIES

SRC_DIR 			=		src
INC_DIR				=		includes
LIB_DIR				=		libs
OBJ_DIR				= 		obj

# SO_LONG

SRC_FILES 			=		so_long map_check errors_so_long utils/free_map utils/read_map utils/copy_map
SRCS				=		$(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC_FILES)))
OBJS				=		$(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SRC_FILES)))

#TARGET

NAME				=		so_long

# LIBFT COMPILATION

LIBFT_GIT			= 		https://github.com/LaGuibole/Libft_Boosted.git
LIBFT_DIR			= 		Libft_Boosted
LIBFT_PATH			= 		$(LIB_DIR)/$(LIBFT_DIR)
LIBFT_H				= 		libft.h
LIBFT_H_PATH		= 		$(LIBFT_PATH)/includes/$(LIBFT_H)
LIBFT_INC_H			= 		$(INC_DIR)/$(LIBFT_H)
LIBFT_TARGET		= 		libft.a
LIBFT_TARGET_PATH	= 		$(LIBFT_PATH)/$(LIBFT_TARGET)

$(LIBFT_INC_H): $(LIBFT_TARGET)
							@cp $(LIBFT_H_PATH) $@

$(LIBFT_TARGET):
							@if [ ! -d "$(LIBFT_PATH)/.git" ]; then \
								printf "Cloning lib \"%s\" into \"%s\"..." $(LIBFT_GIT) $(LIBFT_PATH);\
								git clone $(LIBFT_GIT) $(LIBFT_PATH);\
							fi
							@printf "Making \"%s\"..." $@
							@$(MAKE) --no-print-directory -C $(LIBFT_PATH)
							@cp $(LIBFT_TARGET_PATH) ./
							@printf "✅ Done copying archive $(GREEN) \"%s\" $(RESET)... \n\n" $@

# SO_LONG TARGET

$(NAME): $(LIBFT_INC_H) $(OBJS)
							@$(CC) $(CFLAGS) $(IFLAGS) -o $(NAME) $(OBJS) $(LIBFT_TARGET)
							@echo "🎉 Executable$(BLUE) $(NAME) cree. $(RESET)\n"

# OBJ DIR

$(OBJ_DIR):
							@mkdir -p $(OBJ_DIR)

# .O FILE COMPILATION

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
							@echo "⚙️ Compiling $< into $@ ...\n"
							@${RM_LINE}
							@mkdir -p $(dir $@)
							@$(CC) $(CFLAGS) -c $< -o $@ -I$(IFLAGS)
							@${RM_LINE}

all:						$(NAME)

clean:
							@$(RM) -r $(OBJ_DIR)

fclean: clean
							@$(RM) $(NAME)
							@$(RM) $(LIBFT_TARGET)
							@$(RM) $(LIBFT_INC_H)

re: fclean all

cleanlibs:
							@$(MAKE) clean --no-print-directory -C $(LIBFT_PATH)

fcleanlibs:
							@$(RM) -r $(LIBFT_PATH)

relibs: fcleanlibs $(LIBFT_INC_H)

norminette:
							@norminette $(SRC_DIR) $(BONUS_SRC) $(INC_DIR) | grep -Ev '^Notice|OK!$$'	\
							&& $(ECHO) -e '\033[1;31mNorminette KO!'						\
							|| $(ECHO) -e '\033[1;32mNorminette OK!'

.PHONY: all re clean fclean cleanlibs fcleanlibs relibs norminette

