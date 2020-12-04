/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_type_specifier_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 11:35:08 by monoue            #+#    #+#             */
/*   Updated: 2020/12/04 16:03:44 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls_bonus.h"

void	put_type_specifier(mode_t mode)
{
	if (S_ISREG(mode))
	{
		if (mode & S_IXUGO)
			ft_putchar('*');
	}
	else
	{
		if (S_ISDIR(mode))
			ft_putchar('/');
		else if (S_ISLNK(mode))
			ft_putchar('@');
		else if (S_ISFIFO(mode))
			ft_putchar('|');
		else if (S_ISSOCK(mode))
			ft_putchar('=');
	}
}
