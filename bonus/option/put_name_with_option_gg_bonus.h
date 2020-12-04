/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_name_with_option_gg_bonus.h                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 11:54:08 by monoue            #+#    #+#             */
/*   Updated: 2020/12/04 11:04:47 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUT_NAME_WITH_OPTION_GG_H
# define PUT_NAME_WITH_OPTION_GG_H

# include "sys/stat.h"
# include "../../libft/libft.h"

void	put_name_with_option_gg(const char *name, mode_t mode, bool link_ok);

# define S_IXUGO (S_IXUSR | S_IXGRP | S_IXOTH)

#endif
