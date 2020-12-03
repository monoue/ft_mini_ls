# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: monoue <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/30 15:33:41 by monoue            #+#    #+#              #
#    Updated: 2020/12/03 11:53:46 by monoue           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_mini_ls
CC = gcc

# PATH
SRCS_PATH =			src/
LIBFT_PATH =		$(SRCS_PATH)libft/
PLAYGROUND_PATH =	playground/
OPTION_PATH = option/

LIBFT =				$(LIBFT_PATH)libft.a

SRCS_NAME =
CFLAGS = -Wall -Wextra -Werror

SRCS_NAME += main.c
SRCS_NAME += $(OPTION_PATH)put_name_with_option_gg.c
SRCS_NAME += $(OPTION_PATH)put_option_l.c
SRCS_NAME += $(OPTION_PATH)put_option_ff.c

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJS = $(SRCS:%.c=%.o)

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT_PATH);
	@$(CC) $^ -L$(LIBFT_PATH) -lft -o $@

all: $(NAME)

run: $(NAME)
	@cp -rf $(NAME) $(PLAYGROUND_PATH)
	@cd $(PLAYGROUND_PATH) && ./$(NAME)

bonus: $(NAME)

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re run
