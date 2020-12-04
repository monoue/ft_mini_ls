/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_all_file_names_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 14:03:57 by monoue            #+#    #+#             */
/*   Updated: 2020/12/04 17:20:41 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls_bonus.h"

static void	put_padding_spaces(int total_name_len)
{
	int	len_to_fill;

	len_to_fill = g_file_name_plus_spaces_len - total_name_len;
	while (len_to_fill > 0)
	{
		ft_putchar(' ');
		len_to_fill--;
	}
}

void	put_file_name_with_color(const char *name, mode_t mode, bool link_ok)
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

static void	put_file_name(char *file_name, mode_t mode, bool is_last_file)
{
	int	total_name_len;

// TODO: LINKOK とは何者か調べる
	if (g_gg_flag == true)
		put_file_name_with_color(file_name, mode, true);
	else
		ft_putstr(file_name);
	total_name_len = (int)ft_strlen(file_name);
	if (g_ff_flag == true)
		total_name_len += put_type_specifier(mode);
	if (g_one_flag == true)
		ft_putchar('\n');
	else
	{
		if (is_last_file == false)
			put_padding_spaces(total_name_len);
	}
}

void		put_all_file_names(t_file_data *file_data_arr, int files_num)
{
	int		index;
	bool	is_last_file;

	is_last_file = false;
	if (g_r_flag == true)
	{
		index = files_num - 1;
		while (index >= 0)
		{
			if (index == 0)
				is_last_file = true;
			put_file_name(file_data_arr[index].name, file_data_arr[index].mode, is_last_file);
			index--;
		}
	}
	else
	{
		index = 0;
		while (index < files_num)
		{
			if (index == files_num - 1)
				is_last_file = true;
			put_file_name(file_data_arr[index].name, file_data_arr[index].mode, is_last_file);
			index++;
		}
	}
	if (g_one_flag == false)
		ft_putchar('\n');
}
