# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/04 19:08:22 by ahmez-za          #+#    #+#              #
#    Updated: 2022/09/06 20:33:26 by ahmez-za         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

RM = rm -f
NAME = cub3D
LIBFT = ./libft/libft.a
FILES = CubInit/_mlx_init.c             libft/ft_isalpha.c              libft/ft_strjoin.c \
		CubInit/get_len_of_map.c        libft/ft_isascii.c              libft/ft_strlcat.c \
		CubInit/player_pos.c            libft/ft_isdigit.c              libft/ft_strlcpy.c \
		GetNextLine/get_next_line.c     libft/ft_isprint.c              libft/ft_strlen_lib.c \
		RayCasting/collisions_ray_len.c libft/ft_itoa.c                 libft/ft_strmapi.c \
		RayCasting/draw_mini_map.c      libft/ft_memchr.c               libft/ft_strncmp.c \
		RayCasting/engine.c             libft/ft_memcmp.c               libft/ft_strnstr.c \
		RayCasting/events.c             libft/ft_memcpy.c               libft/ft_strrchr.c \
		RayCasting/img_pixel_put.c      libft/ft_memmove.c              libft/ft_strtrim.c \
		RayCasting/ray_collision.c      libft/ft_memset.c               libft/ft_substr.c \
		RayCasting/ray_len.c            libft/ft_putchar_fd.c           libft/ft_tolower.c \
		RayCasting/rays_firing.c        libft/ft_putendl_fd.c           libft/ft_toupper.c \
		Utilis/utiltis.c                libft/ft_putnbr_fd.c            parsing/parser_utils.c \
		Utilis/utiltis_II.c             libft/ft_putstr_fd.c            parsing/parser_utils2.c \
		libft/ft_atoi.c                 libft/ft_split.c                parsing/parser_utils3.c \
		libft/ft_bzero.c                libft/ft_strchr.c               parsing/parser_utils4.c \
		libft/ft_calloc.c               libft/ft_strdup.c               parsing/validate_map.c \
		libft/ft_isalnum.c              libft/ft_striteri.c				cub3d.c

all:  $(NAME)

$(NAME): $(FILES)
	cd libft && make && cd ..
	$(CC) $(FILES)  -o $(NAME) $(LIBFT)
	

clean:
	cd libft && make clean && cd ..
	$(RM) $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re bonus
