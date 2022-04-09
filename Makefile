# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afaby <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/29 09:46:57 by afaby             #+#    #+#              #
#    Updated: 2022/04/09 11:43:53 by afaby            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =	ft_isalpha.c	ft_isdigit.c	ft_isalnum.c	ft_isascii.c \
		ft_isprint.c	ft_strlen.c		ft_memset.c		ft_bzero.c \
		ft_memcpy.c		ft_memmove.c	ft_strlcat.c	ft_toupper.c \
		ft_tolower.c	ft_strlcpy.c	ft_strdup.c		ft_atoi.c \
		ft_strchr.c		ft_strrchr.c	ft_calloc.c		ft_strncmp.c \
		ft_memchr.c		ft_memcmp.c		ft_strnstr.c	ft_putendl_fd.c \
		ft_putstr_fd.c	ft_putchar_fd.c	ft_putnbr_fd.c	ft_strjoin.c \
		ft_substr.c		ft_split.c		ft_strmapi.c	ft_itoa.c \
		ft_strtrim.c 	ft_striteri.c

SRCS_BONUS =	ft_lstnew.c		ft_lstlast.c	ft_lstsize.c \
			ft_lstadd_front.c	ft_lstadd_back.c	ft_lstiter.c \
			ft_lstdelone.c	ft_lstclear.c 	ft_lstmap.c \
	

FLAGS =	-Wall -Wextra -Werror

OBJS =	$(SRCS:.c=.o)

OBJS_BONUS = $(SRCS:.c=.o) $(SRCS_BONUS:.c=.o)

CC =	gcc

all: $(NAME)

clean:
	rm -f $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.c.o:
	$(CC) -g $(FLAGS) -c $<
 
$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

bonus: $(OBJS_BONUS)
	ar rc $(NAME) $(OBJS_BONUS)
	ranlib $(NAME)

.PHONY: all clean fclean re bonus
