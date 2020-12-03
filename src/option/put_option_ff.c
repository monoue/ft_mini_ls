/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_option_ff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 11:35:08 by monoue            #+#    #+#             */
/*   Updated: 2020/12/03 11:36:45 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "put_option_ff.h"

void	put_ff_option(mode_t mode)
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
