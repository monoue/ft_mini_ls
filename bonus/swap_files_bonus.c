/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_files_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 13:15:25 by monoue            #+#    #+#             */
/*   Updated: 2020/12/04 13:15:39 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls_bonus.h"

void	swap_files(t_file_data *file_data_arr, int left, int right)
{
	t_file_data tmp;

	tmp = file_data_arr[left];
	file_data_arr[left] = file_data_arr[right];
	file_data_arr[right] = tmp;
}
