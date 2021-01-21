/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_type_indicator_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 11:35:08 by monoue            #+#    #+#             */
/*   Updated: 2020/12/04 21:06:02 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_mini_ls_bonus.h"

int	put_type_indicator(mode_t mode)
{
	if (S_ISREG(mode))
	{
		if (mode & S_IXUGO)
			return (ft_putchar('*'));
	}
	else
	{
		if (S_ISDIR(mode))
			return (ft_putchar('/'));
		else if (S_ISLNK(mode))
			return (ft_putchar('@'));
		else if (S_ISFIFO(mode))
			return (ft_putchar('|'));
		else if (S_ISSOCK(mode))
			return (ft_putchar('='));
	}
	return (0);
}
