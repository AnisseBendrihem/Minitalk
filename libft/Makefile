# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/30 20:38:49 by abendrih          #+#    #+#              #
#    Updated: 2025/07/29 05:42:18 by abendrih         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom du programme de test
EXEC = main

# Nom de la librairie
NAME = libft.a

# Fichiers source de ft_lib/
SRC_LIBFT = \
	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
	ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \
	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
	ft_strlcat.c ft_tolower.c ft_toupper.c ft_strchr.c ft_strrchr.c \
	ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_strdup.c \
	ft_calloc.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
	ft_strmapi.c ft_striteri.c ft_putnbr_fd.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c ft_strndup.c

SRC_LIBFT := $(addprefix ft_lib/, $(SRC_LIBFT))

# Fichiers source de ft_printf/
SRC_PRINTF := $(addprefix ft_printf/, \
	ft_printf.c ft_convertf.c ft_put_unsigned_nbrf.c ft_putnbrf.c \
	ft_putstrf.c ft_puthexaf.c ft_putcharf.c)

# Fichiers source de get_next_line/
SRC_GNL := $(addprefix get_next_line/, \
	get_next_line.c)

# Liste finale des sources
SRC = $(SRC_LIBFT) $(SRC_PRINTF) $(SRC_GNL)
OBJ = $(SRC:.c=.o)

# Compilateur & flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Couleurs personnalisées
NEON_GREEN = \033[38;2;57;255;20m
NEON_PINK = \033[38;2;255;20;147m
NEON_CYAN = \033[38;2;0;255;255m
NEON_PURPLE = \033[38;2;180;0;255m
RESET = \033[0m

# Règle par défaut
all: $(NAME)
	@echo "$(NEON_GREEN)💾 [SYSTEM] Compilation de LIBFT avec ft_printf... [OK]$(RESET)"

# Création de la librairie
$(NAME): $(OBJ)
	@echo "$(NEON_CYAN)🔧 Forge de la librairie $(NAME)...$(RESET)"
	@ar rcs $(NAME) $(OBJ)

# Compilation avec les bonus
bonus: $(OBJ) $(OBJ_BONUS)
	@echo "$(NEON_CYAN)🔧 Forge de la librairie $(NAME) avec les bonus...$(RESET)"
	@ar rcs $(NAME) $(OBJ) $(OBJ_BONUS)

# Nettoyage des fichiers objets
clean:
	@echo "$(NEON_PURPLE)🧽 Nettoyage des fichiers .o...$(RESET)"
	@rm -f $(OBJ) $(OBJ_BONUS)

# Nettoyage complet
fclean: clean
	@echo "$(NEON_PINK)💣 Destruction totale de LIBFT...$(RESET)"
	@rm -f $(NAME) $(EXEC)

# Recompilation from scratch
re: fclean all

# Exécution du programme de test
run: all
	@echo "$(NEON_GREEN)⚙️  Compilation de $(EXEC) avec LIBFT...$(RESET)"
	@$(CC) $(CFLAGS) main.c -L. -lft -o $(EXEC)
	@echo "$(NEON_CYAN)👾 Lancement de $(EXEC)...$(RESET)"
	@./$(EXEC)

.PHONY: all bonus clean fclean re run
