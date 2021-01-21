/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:34:12 by monoue            #+#    #+#             */
/*   Updated: 2020/12/04 23:09:42 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_BONUS_H
# define DEFS_BONUS_H

# define CURRENT_DIR_PATH	"."
# define ARG_ERR "Arg not permitted\n"
# define ILL_OPT_MSG "ls: illegal option\nusage: -[AFGart1]"
# define SUCCESS 0
# define OPTIONS "AFGart1"
# define ESC "\033"

typedef struct stat	t_stat;

typedef enum		e_continue
{
	CONTINUE,
	NO_CONTINUE
}					t_continue;

#endif
