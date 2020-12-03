/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_name_with_option_gg.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 11:53:04 by monoue            #+#    #+#             */
/*   Updated: 2020/12/03 12:40:46 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "put_name_with_option_gg.h"

#define ESC "\033"

void	put_name_with_option_gg(const char *name, mode_t mode, bool link_ok)
{
	if (!link_ok)
		ft_putstr(ESC"[31m");
	else if (S_ISREG(mode))
	{
		if (mode & S_ISUID)
			ft_putstr(ESC"[37;41m");
		else if (mode & S_ISGID)
			ft_putstr(ESC"[30;43m");
		else if (mode & S_IXUGO)
			ft_putstr(ESC"[31m");
		else
			ft_putstr(ESC"[0m");
	}
	else if (S_ISDIR(mode))
	{
		if ((mode & S_ISVTX) && (mode & S_IWOTH))
			ft_putstr(ESC"[30;42m");
		else if (mode & S_IWOTH)
			ft_putstr(ESC"[34;42m");
		else if (mode & S_ISVTX)
			ft_putstr(ESC"[37;44m");
		else
			ft_putstr(ESC"[34m");
	}
	else if (S_ISLNK(mode))
		ft_putstr(ESC"[01;36m");
	else if (S_ISFIFO(mode))
		ft_putstr(ESC"[33m");
	else if (S_ISSOCK(mode))
		ft_putstr(ESC"[01;35m");
	else if (S_ISBLK(mode))
		ft_putstr(ESC"[01;33m");
	else if (S_ISCHR(mode))
		ft_putstr(ESC"[01;33m");
	ft_putstr((char *)name);
	ft_putstr(ESC"[0m");
}
