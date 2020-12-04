/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:13:39 by monoue            #+#    #+#             */
/*   Updated: 2020/12/04 17:14:49 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINI_LS_H
# define FT_MINI_LS_H

# include "defs_bonus.h"
# include <dirent.h>
# include "../libft/libft.h"
// # include "sys/types.h"
# include "sys/stat.h"

# define S_IXUGO (S_IXUSR | S_IXGRP | S_IXOTH)

typedef struct stat t_stat;

extern bool		g_error_flag;
extern bool		g_a_flag;
extern bool		g_aa_flag;
extern bool		g_r_flag;
extern bool		g_one_flag;
extern bool		g_ff_flag;
extern bool		g_gg_flag;
extern bool		g_t_flag;
extern size_t	g_file_name_plus_spaces_len;

typedef struct	s_file_data {
	char	*name;
	time_t	tv_sec;
	long	tv_nsec;
	mode_t	mode;
}				t_file_data;

void	swap_files(t_file_data *file_data_arr, int left, int right);
void	sort_files(t_file_data *file_data_arr, int files_num);
void	sort_files_by_time(t_file_data *file_data_arr, int files_num);
int		parse_all_command_arguments(int argc, char *argv[]);
void	put_all_file_names(t_file_data *file_data_arr, int files_num);
int		put_type_specifier(mode_t mode);


#endif
