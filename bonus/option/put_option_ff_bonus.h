/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_option_ff_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 11:35:23 by monoue            #+#    #+#             */
/*   Updated: 2020/12/04 15:24:46 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUT_OPTION_FF_BONUS_H
# define PUT_OPTION_FF_BONUS_H

# include "sys/stat.h"
# include "../../libft/libft.h"

/*
** executable for User, Group and Other
*/

# define S_IXUGO (S_IXUSR | S_IXGRP | S_IXOTH)

void	put_type_specifier(mode_t mode);

#endif
