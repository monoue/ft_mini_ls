/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_files_by_time_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 13:18:34 by monoue            #+#    #+#             */
/*   Updated: 2020/12/04 20:40:16 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_mini_ls_bonus.h"

static void	sort_time_ordered_files_by_name(t_file_data *file_data_arr,
																int files_num)
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
			if ((left.tv_sec == right.tv_sec)
					&& (left.tv_nsec == right.tv_nsec)
					&& (ft_strcmp(left.name, right.name) > 0))
				swap_files(file_data_arr, l_index, r_index);
			r_index++;
		}
		l_index++;
	}
}

static void	sort_files_by_tv_nsec(t_file_data *file_data_arr, int files_num)
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
			if ((left.tv_sec == right.tv_sec) && (left.tv_nsec < right.tv_nsec))
				swap_files(file_data_arr, l_index, r_index);
			r_index++;
		}
		l_index++;
	}
}

static void	sort_files_by_tv_sec(t_file_data *file_data_arr, int files_num)
{
	int left;
	int	right;

	left = 0;
	while (left + 1 < files_num)
	{
		right = left + 1;
		while (right < files_num)
		{
			if (file_data_arr[left].tv_sec < file_data_arr[right].tv_sec)
				swap_files(file_data_arr, left, right);
			right++;
		}
		left++;
	}
}

void		sort_files_by_time(t_file_data *file_data_arr, int files_num)
{
	sort_files_by_tv_sec(file_data_arr, files_num);
	sort_files_by_tv_nsec(file_data_arr, files_num);
	sort_time_ordered_files_by_name(file_data_arr, files_num);
}
