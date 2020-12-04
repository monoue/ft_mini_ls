/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 11:56:31 by monoue            #+#    #+#             */
/*   Updated: 2020/11/30 14:07:03 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_H
# define DEFS_H

# include <stdbool.h>

typedef struct	s_format_info
{
	int		min_width;
	int		precision;
	char	conv_c;
	bool	minus;
	bool	zero;
	bool	c_null;
	void	*value;
}				t_format_info;

#endif
