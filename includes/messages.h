/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:33:39 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/10 11:48:08 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGES_H
# define MESSAGES_H

// COLORS

# define RED "\033[31m"
# define BLUE "\033[34m"
# define GREEN "\033[32m"
# define RESET "\033[0m"

// EN - MESSAGES

# define MSG_WELCOME "Welcome to So_Long\n"
# define MSG_ERROR_EXTENSION RED "Error: Map file must have .ber extension\n" RESET
# define MSG_ERROR_RECTANGLE RED "Error: Map must be rectangular\n" RESET
# define MSG_ERROR_WALLS RED "Error: Map must be fully surronded by walls\n" RESET
# define MSG_ERROR_INVALID RED "Error: Map contain invalid elements\n" RESET
# define MSG_ERROR_MISSING RED "Error: Map must have 1 player, at least 1 collectible and 1 exit\n" RESET
# define MSG_ERROR_UNSOLVABLE RED "Error: The map is unsolvable. Check the path to the exit and collectibles" RESET
# define MSG_MAP_SUCCESS GREEN "Success : Map is valid and playable\n" RESET
# define USAGE "Usage : ./so_long <file.ber>\n"
# define MAP_UNREADABLE RED "Map cannot be read\n" RESET
# define MSG_ERROR_COPY RED "Map cannot be copied\n" RESET

// FR - MESSAGES

# ifdef LANG_FR
#  undef MSG_WELCOME
#  undef MSG_ERROR_EXTENSION
#  undef MSG_ERROR_RECTANGLE
#  undef MSG_ERROR_WALLS
#  undef MSG_ERROR_INVALID
#  undef MSG_ERROR_MISSING
#  undef MSG_ERROR_UNSOLVABLE
#  undef MSG_MAP_SUCCESS
#  undef USAGE
#  undef MAP_UNREADABLE

#  define MSG_WELCOME RED "Bienvenue dans So_Long\n" RESET
# define MSG_ERROR_EXTENSION RED "Erreur : La map doit avoir l'extension .ber\n" RESET
# define MSG_ERROR_RECTANGLE RED "Erreur : La map n'est pas rectangulaire\n" RESET
# define MSG_ERROR_WALLS RED "Erreur : La map n'est pas entouree de murs\n" RESET
# define MSG_ERROR_INVALID RED "Erreur : La map contient des elements invalides\n" RESET
# define MSG_ERROR_MISSING RED "Erreur : La map doit avoir au moins 1 joueur, au moins 1 collectible, et 1 sortie\n" RESET
# define MSG_ERROR_UNSOLVABLE RED "Erreur : La map n'est pas solvable. Il faut checker le chemin vers l'exit et les collectibles\n" RESET
# define MSG_MAP_SUCCESS GREEN "Succes : La map est valide et jouable\n" RESET
# define USAGE "Utilisation : ./so_long <file.ber>\n"
# define MAP_UNREADABLE RED "La map ne peut pas etre lue\n" RESET
# endif
#endif
