/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_files_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 21:14:03 by monoue            #+#    #+#             */
/*   Updated: 2020/12/04 21:19:50 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls_bonus.h"

int	count_files(void)
{
	DIR				*dir;
	size_t			files_num;
	struct dirent	*dir_ent;

	dir = opendir(CURRENT_DIR_PATH);
	if (dir == NULL)
		return (ERROR);
	files_num = 0;
	while ((dir_ent = readdir(dir)) != NULL)
	{
		if (g_a_flag == true)
			;
		else if (g_aa_flag == true)
		{
			if (is_current_or_parent_dir(dir_ent->d_name))
				continue ;
		}
		else if (dir_ent->d_name[0] == '.')
			continue ;
		files_num++;
	}
	closedir(dir);
	return (files_num);
}
