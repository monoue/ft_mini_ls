/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_all_file_names_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 14:03:57 by monoue            #+#    #+#             */
/*   Updated: 2020/12/04 16:55:31 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls_bonus.h"

// static void	put_padding_spaces(char *file_name)
// {
// 	size_t	len_to_fill;

// 	len_to_fill = g_file_name_plus_spaces_len - ft_strlen(file_name);
// 	while (len_to_fill > 0)
// 	{
// 		ft_putchar(' ');
// 		len_to_fill--;
// 	}
// }
static void	put_padding_spaces(int total_name_len)
{
	size_t	len_to_fill;

	len_to_fill = g_file_name_plus_spaces_len - total_name_len;
	while (len_to_fill > 0)
	{
		ft_putchar(' ');
		len_to_fill--;
	}
}

static void	put_file_name(char *file_name, mode_t mode, bool is_last_file)
{
	int	total_name_len;

	total_name_len = ft_putstr(file_name);

	if (g_ff_flag == true) // こいつは色付けしないから、-G オプションの後
		total_name_len += put_type_specifier(mode);
	if (g_one_flag == true)
		ft_putchar('\n');
	else
	{
		if (is_last_file == false)
			put_padding_spaces(total_name_len);
			// put_padding_spaces(file_name);
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
