/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_element_plus_spaces_len_bonus.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 21:15:40 by monoue            #+#    #+#             */
/*   Updated: 2020/12/04 21:56:43 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls_bonus.h"

static bool	file_has_type_indicator(mode_t mode)
{
	if (S_ISREG(mode))
		return (mode & S_IXUGO);
	else
	{
		return (S_ISDIR(mode)
				|| S_ISLNK(mode)
				|| S_ISFIFO(mode)
				|| S_ISSOCK(mode));
	}
}

void		set_element_plus_spaces_len(t_file_data *file_data_arr,
																int files_num)
{
	int		index;
	bool	file_has_type_indicator_flag;

	file_has_type_indicator_flag = false;
	index = 0;
	while (index < files_num)
	{
		g_file_name_plus_spaces_len = MAX(ft_strlen(file_data_arr[index].name)
											+ 1, g_file_name_plus_spaces_len);
		if (g_ff_flag == true && file_has_type_indicator_flag == false)
		{
			file_has_type_indicator_flag = file_has_type_indicator(
													file_data_arr[index].mode);
		}
		index++;
	}
	if (file_has_type_indicator_flag == true)
		g_file_name_plus_spaces_len++;
}
