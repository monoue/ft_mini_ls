/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_current_or_parent_dir_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 21:18:54 by monoue            #+#    #+#             */
/*   Updated: 2020/12/04 21:19:41 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls_bonus.h"

bool	is_current_or_parent_dir(char *file_name)
{
	const size_t	file_name_len = ft_strlen(file_name);
	size_t			index;

	if (file_name_len > 2)
		return (false);
	index = 0;
	while (index < file_name_len)
	{
		if (file_name[index] != '.')
			return (false);
		index++;
	}
	return (true);
}
