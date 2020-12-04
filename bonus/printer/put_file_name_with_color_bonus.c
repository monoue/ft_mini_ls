/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_file_name_with_color_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 20:49:35 by monoue            #+#    #+#             */
/*   Updated: 2020/12/04 21:06:14 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_mini_ls_bonus.h"

static void	put_regular_file_color(mode_t mode)
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

static void	put_dir_color(mode_t mode)
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

void		put_file_name_with_color(const char *name, mode_t mode,
																bool link_ok)
{
	if (!link_ok)
		ft_putstr(ESC"[31m");
	else if (S_ISREG(mode))
		put_regular_file_color(mode);
	else if (S_ISDIR(mode))
		put_dir_color(mode);
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
