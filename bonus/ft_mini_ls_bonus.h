/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:13:39 by monoue            #+#    #+#             */
/*   Updated: 2020/12/04 22:15:17 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINI_LS_BONUS_H
# define FT_MINI_LS_BONUS_H

# include "defs_bonus.h"
# include <dirent.h>
# include "../libft/libft.h"
# include <sys/stat.h>

# define S_IXUGO (S_IXUSR | S_IXGRP | S_IXOTH)

typedef struct stat	t_stat;

typedef struct		s_file_data {
	char	*name;
	time_t	tv_sec;
	long	tv_nsec;
	mode_t	mode;
	bool	link_is_ok;
}					t_file_data;

void				swap_files(t_file_data *file_data_arr, int left, int right);
void				sort_files(t_file_data *file_data_arr, int files_num);
void				sort_files_by_time(t_file_data *file_data_arr,
																int files_num);
int					parse_all_command_arguments(int argc, char *argv[]);
void				put_all_file_names(t_file_data *file_data_arr,
																int files_num);
int					put_type_indicator(mode_t mode);
void				put_file_name_with_color(const char *name, mode_t mode,
																bool link_ok);
int					count_files(void);
void				set_element_plus_spaces_len(t_file_data *file_data_arr,
																int files_num);
bool				is_current_or_parent_dir(char *file_name);

extern bool			g_error_flag;
extern bool			g_a_flag;
extern bool			g_aa_flag;
extern bool			g_r_flag;
extern bool			g_one_flag;
extern bool			g_ff_flag;
extern bool			g_gg_flag;
extern bool			g_t_flag;
extern size_t		g_file_name_plus_spaces_len;

#endif
