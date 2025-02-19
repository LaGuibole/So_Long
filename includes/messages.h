/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:33:39 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/19 16:33:38 by guphilip         ###   ########.fr       */
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

# define MSG_WELCOME				"Welcome to So_Long\n"
# define MSG_ERROR_EXTENSION		"Error:\n Map file must have \
.ber extension\n"
# define MSG_ERROR_RECTANGLE		"Error:\n Map must be rectangular\n"
# define MSG_ERROR_WALLS			"Error:\n Map must be fully \
surronded by walls\n"
# define MSG_ERROR_INVALID			"Error:\n Map contain invalid elements\n"
# define MSG_ERROR_MISSING			"Error:\n Map must have 1 player, \
at least 1 collectible and 1 exit\n"
# define MSG_ERROR_UNSOLVABLE		"Error:\n The map is unsolvable. \
Check the path to the exit and collectibles"
# define MSG_MAP_SUCCESS			"Success : Map is valid and playable\n"
# define MSG_MAP_UNREADABLE			"Error :\nMap cannot be read\n"
# define MSG_ERROR_COPY				"Error :\nMap cannot be copied\n"
# define MSG_USAGE					"Error :\nUsage : ./so_long <map/map.ber>\n"
# define MSG_PAC_TEXTURE_ERR		"Error :\nA Pacman texture is missing\n"
# define MSG_MAP_TEXTURE_ERR		"Error :\nA map texture is missing\n"
# define MSG_SCORE_TEXTURE_ERR		"Error :\nA score texture is missing\n"
# define MSG_MOVE_TEXTURE_ERR		"Error :\nA move title texture is missing\n"
# define MSG_TO_COLL_TEXTURE_ERR	"Error :\nA to collect texture is missing\n"
# define MSG_GAME_OVER				"Game Over, Pacman got caught!\n"
# define MSG_GAME_WIN				"Success : You won with %d moves\n"
# define MSG_ERROR_LOAD_IMG			"Error :\nFailed to load img\n"
# define MSG_OPEN_ERROR				"Error :\nError while opening file\n"
# define MSG_ERROR_MEM_ALLOC		"Error :\nMemory allocation error\n"
# define MSG_ERROR_REOPEN			"Error :\nError while reopening file\n"

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
#  undef MSG_MAP_UNREADABLE
#  undef MSG_ERROR_COPY
#  undef MSG_USAGE
#  undef MSG_PAC_TEXTURE_ERR
#  undef MSG_MAP_TEXTURE_ERR
#  undef MSG_TO_COLL_TEXTURE_ERR
#  undef MSG_GAME_OVER
#  undef MSG_ERROR_LOAD_IMG
#  undef MSG_OPEN_ERROR
#  undef MSG_ERROR_MEM_ALLOC
#  undef MSG_ERROR_REOPEN
#  undef MSG_SCORE_TEXTURE_ERR
#  undef MSG_SCORE_TEXTURE_ERR
#  undef MSG_GAME_WIN
#  undef MSG_MOVE_TEXTURE_ERR

#  define MSG_WELCOME				"Bienvenue dans So_Long\n"
#  define MSG_ERROR_EXTENSION		"Erreur :\nLa map doit \
avoir l'extension .ber\n"
#  define MSG_ERROR_RECTANGLE		"Erreur :\nLa map n'est pas \
rectangulaire\n"
#  define MSG_ERROR_WALLS			"Erreur :\nLa map n'est pas \
entouree de murs\n"
#  define MSG_ERROR_INVALID			"Erreur :\nLa map contient des \
elements invalides\n"
#  define MSG_ERROR_MISSING			"Erreur :\nLa map doit avoir au moins \
1 joueur, au moins 1 collectible, et 1 sortie\n"
#  define MSG_ERROR_UNSOLVABLE		"Erreur :\nLa map n'est pas solvable. \
Il faut checker le chemin vers l'exit et les collectibles\n"
#  define MSG_MAP_SUCCESS			"Succes :\nLa map est valide et jouable\n"
#  define MSG_MAP_UNREADABLE		"Erreur :\nLa map ne peut pas etre lue\n"
#  define MSG_ERROR_COPY			"Error :\nMap cannot be copied\n"
#  define MSG_USAGE					"Erreur :\nUtilisation : \
./so_long <file.ber>\n"
#  define MSG_PAC_TEXTURE_ERR		"Erreur :\nUne texture Pacman \
est manquante\n"
#  define MSG_MAP_TEXTURE_ERR		"Erreur :\nUne texture de map \
est manquante\n"
#  define MSG_SCORE_TEXTURE_ERR		"Erreur :\nUne texture de score \
est manquante\n"
#  define MSG_MOVE_TEXTURE_ERR		"Erreur :\nUne texture du titre 'MOVES' \
est manquante\n"
#  define MSG_TO_COLL_TEXTURE_ERR	"Erreur :\nUne texture du titre 'TO COLLECT' \
est manquante\n"
#  define MSG_GAME_OVER				"C'est perdu : Pacman s'est fait \
attraper\n"
#  define MSG_GAME_WIN				"Succes : Vous avez gagne avec %d \
mouvements\n"
#  define MSG_ERROR_LOAD_IMG		"Erreur :\nErreur de chargement de \
l'image\n"
#  define MSG_OPEN_ERROR			"Erreur :\nUne erreur s'est produite a \
l'ouverture du fichier\n"
#  define MSG_ERROR_MEM_ALLOC		"Erreur :\nUne erreur d'allocation memoire \
s'est produite\n"
#  define MSG_ERROR_REOPEN			"Erreur :\nUne erreur est survenue lors de \
la seconde ouverture du fichier\n"
# endif
#endif
