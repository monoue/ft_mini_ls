# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: monoue <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/30 15:33:41 by monoue            #+#    #+#              #
#    Updated: 2020/12/04 21:20:28 by monoue           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_mini_ls
CC = gcc

# PATH
SRCS_PATH =			src/
BONUS_PATH =		bonus/
LIBFT_PATH =		libft/
PLAYGROUND_PATH =	playground/
OPTION_PATH =		option/
SORT_FILES_PATH =	sort_files/
PRINTER_PATH =		printer/

LIBFT =				$(LIBFT_PATH)libft.a

SRCS_NAME =
CFLAGS = -Wall -Wextra -Werror

SRCS_NAME += main.c
SRCS_NAME += list_dir.c
SRCS_NAME += sort_files.c

BSRCS_NAME += main_bonus.c
BSRCS_NAME += global_bonus.c
BSRCS_NAME += $(SORT_FILES_PATH)sort_files_bonus.c
BSRCS_NAME += $(SORT_FILES_PATH)sort_files_by_time_bonus.c
BSRCS_NAME += $(SORT_FILES_PATH)swap_files_bonus.c
BSRCS_NAME += parse_all_command_arguments_bonus.c
BSRCS_NAME += $(PRINTER_PATH)put_all_file_names_bonus.c
BSRCS_NAME += $(PRINTER_PATH)put_type_indicator_bonus.c
BSRCS_NAME += $(PRINTER_PATH)put_file_name_with_color_bonus.c
BSRCS_NAME += count_files_bonus.c
BSRCS_NAME += set_element_plus_spaces_len_bonus.c
BSRCS_NAME += is_current_or_parent_dir_bonus.c

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJS = $(SRCS:%.c=%.o)

BSRCS = $(addprefix $(BONUS_PATH), $(BSRCS_NAME))
BOBJS = $(BSRCS:%.c=%.o)

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT_PATH);
	@$(CC) $^ -L$(LIBFT_PATH) -lft -o $@

all: $(NAME)

bonus: $(BOBJS)
	@$(MAKE) -C $(LIBFT_PATH);
	@$(CC) $^ -L$(LIBFT_PATH) -lft -o $(NAME)

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	$(RM) $(OBJS) $(BOBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re run
