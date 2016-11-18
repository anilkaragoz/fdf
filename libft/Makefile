# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akaragoz <akaragoz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/14 18:08:40 by akaragoz          #+#    #+#              #
#    Updated: 2016/05/30 17:49:29 by akaragoz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OPATH = obj
CPATH = srcs
HPATH = includes

CC = /usr/bin/gcc
MKDIR = /bin/mkdir
RM = /bin/rm
CFLAGS = -Wall -Wextra -Werror -I $(HPATH)
NAME = libft.a

HEADER = ft_printf.h \
	libft.h\
	get_next_line.h

SRC = ft_atoi.c \
	ft_bzero.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_islower.c \
	ft_isprint.c \
	ft_isupper.c \
	ft_memalloc.c \
	ft_memccpy.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memdel.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar.c \
	ft_putchar_fd.c \
	ft_putendl.c \
	ft_putendl_fd.c \
	ft_putnbr.c \
	ft_putnbr_fd.c \
	ft_putstr.c \
	ft_putstr_fd.c \
	ft_strcat.c \
	ft_strchr.c \
	ft_strclr.c \
	ft_strcmp.c \
	ft_strcpy.c \
	ft_strdel.c \
	ft_strcpychr.c \
	ft_strdup.c \
	ft_strequ.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlen.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strncat.c \
	ft_strncmp.c \
	ft_strncpy.c \
	ft_strnequ.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strnew.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strsplit.c \
	ft_strstr.c \
	ft_strsub.c \
	ft_strtrim.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_lstlen.c \
	ft_lstnew.c \
	ft_lstdelone.c \
	ft_lstdel.c \
	ft_lstadd.c \
	ft_lstiter.c \
	ft_lstmap.c \
	ft_itoa.c \
	ft_isspace.c \
	ft_handle_char.c \
	ft_parse_flag.c \
	ft_llitoi.c \
	ft_printf.c \
	ft_ullitoi.c \
	ft_handle_int.c \
	ft_handle_str.c \
	ft_handle_uint.c \
	ft_strjoin_f3.c \
	ft_strjoin_f2.c \
	ft_strjoin_f1.c \
	ft_handle_ptr.c\
	ft_handle_wchar.c \
	ft_handle_wstr.c \
	ft_justify.c \
	ft_handle_wstr2.c \
	ft_to_lower.c \
	ft_add_pfx.c \
	get_next_line.c \
	ft_quicksort.c \
	ft_bubblesort.c \
	ft_latoi.c \
	ft_str_is_number.c

OFILES = $(patsubst %.c,$(OPATH)/%.o, $(SRC))

all:$(OPATH) $(NAME)

$(NAME): $(OFILES)
	@ar rc $(NAME) $(OFILES)
	@ranlib $(NAME)
	@echo "\x1b[32;01m[Libft has been created with success !]"


$(OPATH)/%.o: $(CPATH)/%.c $(HFILES)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo $<

clean:
	@$(RM) -rf $(OPATH)

fclean: clean
	@$(RM) -f $(NAME)

re: fclean all

$(OPATH):
	@$(MKDIR) $(OPATH)
