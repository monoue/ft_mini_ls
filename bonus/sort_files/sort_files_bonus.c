/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_files_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 13:13:33 by monoue            #+#    #+#             */
/*   Updated: 2020/12/04 20:36:56 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_mini_ls_bonus.h"

static void	sort_files_by_name(t_file_data *file_data_arr, int files_num)
{
	int			l_index;
	int			r_index;
	t_file_data left;
	t_file_data right;

	l_index = 0;
	while (l_index + 1 < files_num)
	{
		r_index = l_index + 1;
		while (r_index < files_num)
		{
			left = file_data_arr[l_index];
			right = file_data_arr[r_index];
			if (ft_strcmp(left.name, right.name) > 0)
				swap_files(file_data_arr, l_index, r_index);
			r_index++;
		}
		l_index++;
	}
}

void		sort_files(t_file_data *file_data_arr, int files_num)
{
	sort_files_by_name(file_data_arr, files_num);
	if (g_t_flag == true)
		sort_files_by_time(file_data_arr, files_num);
}
