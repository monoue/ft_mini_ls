/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:13:39 by monoue            #+#    #+#             */
/*   Updated: 2020/12/04 09:10:21 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINI_LS_H
# define FT_MINI_LS_H

# include "defs.h"
# include "dirent.h"
# include "libft/libft.h"
# include "sys/stat.h"

# include "option/put_name_with_option_gg.h"
# include "option/put_option_ff.h"
# include "option/put_option_l.h"

# define S_IXUGO (S_IXUSR | S_IXGRP | S_IXOTH)

typedef struct	s_file_data {
	char	*name;
	time_t	tv_sec;
	long	tv_nsec;
}				t_file_data;

typedef struct stat	t_stat;

extern bool		g_error_flag;

void			sort_files(t_file_data *file_data_arr, int files_num);
void			list_dir(void);

#endif
