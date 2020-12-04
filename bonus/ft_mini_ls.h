/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:13:39 by monoue            #+#    #+#             */
/*   Updated: 2020/12/03 11:55:15 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINI_LS_H
# define FT_MINI_LS_H

# include "defs.h"
# include "dirent.h"
# include "libft/libft.h"
// # include "sys/types.h"
# include "sys/stat.h"

# include "option/put_name_with_option_gg.h"
# include "option/put_option_ff.h"
# include "option/put_option_l.h"


# define S_IXUGO (S_IXUSR | S_IXGRP | S_IXOTH)

typedef struct stat t_stat;

#endif
