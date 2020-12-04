/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_all_file_names_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 14:03:57 by monoue            #+#    #+#             */
/*   Updated: 2020/12/04 23:08:23 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_mini_ls_bonus.h"

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

static void	put_file_name(char *file_name, mode_t mode, bool link_is_ok,
															bool is_last_file)
{
	int	total_name_len;

	if (g_gg_flag == true)
		put_file_name_with_color(file_name, mode, link_is_ok);
	else
		ft_putstr(file_name);
	total_name_len = (int)ft_strlen(file_name);
	if (g_ff_flag == true)
		total_name_len += put_type_indicator(mode);
	if (g_one_flag == true)
		ft_putchar('\n');
	else
	{
		if (is_last_file == false)
			put_padding_spaces(total_name_len);
	}
}

static void	put_all_file_names_reversely(t_file_data *file_data_arr,
																int last_index)
{
	bool	is_last_file;
	int		index;

	is_last_file = false;
	index = last_index;
	while (index >= 0)
	{
		if (index == 0)
			is_last_file = true;
		put_file_name(file_data_arr[index].name, file_data_arr[index].mode,
							file_data_arr[index].link_is_ok, is_last_file);
		index--;
	}
}

static void	put_all_file_names_in_normal_order(t_file_data *file_data_arr,
																int files_num)
{
	int		index;
	bool	is_last_file;

	is_last_file = false;
	index = 0;
	while (index < files_num)
	{
		if (index == files_num - 1)
			is_last_file = true;
		put_file_name(file_data_arr[index].name, file_data_arr[index].mode,
							file_data_arr[index].link_is_ok, is_last_file);
		index++;
	}
}

void		put_all_file_names(t_file_data *file_data_arr, int files_num)
{
	if (g_r_flag == true)
		put_all_file_names_reversely(file_data_arr, files_num - 1);
	else
		put_all_file_names_in_normal_order(file_data_arr, files_num);
	if (g_one_flag == false)
		ft_putchar('\n');
}
