# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmonkfis <lmonkfis@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/25 23:08:59 by lmonkfis          #+#    #+#              #
#    Updated: 2019/10/25 23:19:08 by lmonkfis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

CFLAGS = -Wall -Wextra -Werror

SRC		=   ./libftprintf/ft_printf/ft_accuracy_sdxo.c \
            ./libftprintf/ft_printf/ft_zero_pro_s_c.c \
            ./libftprintf/ft_printf/make_weight.c \
            ./libftprintf/ft_printf/ft_nul.c \
            ./libftprintf/ft_printf/ft_printf.c  \
            ./libftprintf/ft_printf/ft_arg_part_cdisp.c \
            ./libftprintf/ft_printf/ft_arg_part_ofpro.c \
            ./libftprintf/ft_printf/ft_arg_part_xubkw.c \
            ./libftprintf/ft_printf/round_double.c \
            ./libftprintf/ft_printf/make_str_sxo.c \
            ./libftprintf/ft_printf/ft_zero_pxo.c \
            ./libftprintf/ft_printf/check_flag.c \
            ./libftprintf/ft_printf/make_str_d.c \
            ./libftprintf/ft_printf/make_str_f.c \
            ./libftprintf/ft_printf/ft_check_letter.c \
            ./libftprintf/libft/ft_atoi.c \
             ./libftprintf/libft/ft_bzero.c \
             ./libftprintf/libft/ft_count_word.c \
             ./libftprintf/libft/ft_digit.c \
             ./libftprintf/libft/ft_double_array.c \
             ./libftprintf/libft/ft_error.c \
             ./libftprintf/libft/ft_factorial.c \
             ./libftprintf/libft/ft_free.c \
             ./libftprintf/libft/ft_isalnum.c \
            ./libftprintf/libft/ft_isalpha.c \
            ./libftprintf/libft/ft_isascii.c \
             ./libftprintf/libft/ft_isdigit.c \
             ./libftprintf/libft/ft_isprint.c \
             ./libftprintf/libft/ft_itoa.c \
             ./libftprintf/libft/ft_itoa_u.c \
             ./libftprintf/libft/ft_len_word.c \
             ./libftprintf/libft/ft_lstadd.c \
             ./libftprintf/libft/ft_lstdel.c \
             ./libftprintf/libft/ft_lstdelone.c \
              ./libftprintf/libft/ft_lstfree.c \
              ./libftprintf/libft/ft_lstiter.c \
              ./libftprintf/libft/ft_lstmap.c \
              ./libftprintf/libft/ft_lstnew.c \
              ./libftprintf/libft/ft_lstnew_data.c \
              ./libftprintf/libft/ft_lstnew_fd.c \
             ./libftprintf/libft/ft_memalloc.c \
             ./libftprintf/libft/ft_memccpy.c \
              ./libftprintf/libft/ft_memchr.c \
              ./libftprintf/libft/ft_memcmp.c \
              ./libftprintf/libft/ft_memcpy.c \
              ./libftprintf/libft/ft_memdel.c \
              ./libftprintf/libft/ft_memmove.c \
              ./libftprintf/libft/ft_memset.c \
              ./libftprintf/libft/ft_modul.c \
              ./libftprintf/libft/ft_print_list.c \
              ./libftprintf/libft/ft_putchar.c \
              ./libftprintf/libft/ft_putchar_fd.c \
              ./libftprintf/libft/ft_putendl.c \
             ./libftprintf/libft/ft_putendl_fd.c \
             ./libftprintf/libft/ft_putnbr.c \
              ./libftprintf/libft/ft_putnbr_fd.c \
              ./libftprintf/libft/ft_putstr.c \
             ./libftprintf/libft/ft_putstr_fd.c \
              ./libftprintf/libft/ft_reverse.c \
             ./libftprintf/libft/ft_schet.c \
              ./libftprintf/libft/ft_sqrt.c \
              ./libftprintf/libft/ft_strcat.c \
             ./libftprintf/libft/ft_strchr.c \
              ./libftprintf/libft/ft_strclr.c \
             ./libftprintf/libft/ft_strcmp.c \
              ./libftprintf/libft/ft_strcpy.c \
              ./libftprintf/libft/ft_strdel.c \
              ./libftprintf/libft/ft_strdup.c \
              ./libftprintf/libft/ft_strequ.c \
              ./libftprintf/libft/ft_strichr.c \
              ./libftprintf/libft/ft_striter.c \
              ./libftprintf/libft/ft_striteri.c \
              ./libftprintf/libft/ft_strjoin.c \
              ./libftprintf/libft/ft_strjoin_printf.c \
              ./libftprintf/libft/ft_strlcat.c \
              ./libftprintf/libft/ft_strlen.c \
              ./libftprintf/libft/ft_strmap.c \
              ./libftprintf/libft/ft_strmapi.c \
            ./libftprintf/libft/ft_strncat.c \
             ./libftprintf/libft/ft_strnchr.c \
              ./libftprintf/libft/ft_strncmp.c \
              ./libftprintf/libft/ft_strncpy.c \
              ./libftprintf/libft/ft_strnequ.c \
              ./libftprintf/libft/ft_strnew.c \
              ./libftprintf/libft/ft_strnstr.c \
              ./libftprintf/libft/ft_strrchr.c \
              ./libftprintf/libft/ft_strsplit.c \
              ./libftprintf/libft/ft_strstr.c \
              ./libftprintf/libft/ft_strsub.c \
              ./libftprintf/libft/ft_strtrim.c \
              ./libftprintf/libft/ft_tolower.c \
             ./libftprintf/libft/ft_toupper.c \
             ./libftprintf/libft/ft_qsort.c \
             ./libftprintf/libft/ft_atoi_long_long.c \
             ./libftprintf/libft/len_numer_arr.c \
             ./libftprintf/libft/get_next_line.c


OBJ	= $(SRC:.c=.o)

HEADER	= ./libftprintf/includes

.PHONY = all clean fclean clean re

all: $(NAME)

$(OBJ): %.o: %.c
	@gcc -c $(CFLAGS) -I$(HEADER) $< -o $@

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[32mCompiled Executable\033[0m"

clean:
	@rm -f $(OBJ)
	@echo "\033[32mRemoved Object Files\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[32mRemoved Executable\033[0m"

re: fclean all