/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 09:07:50 by monoue            #+#    #+#             */
/*   Updated: 2021/01/19 07:04:23 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"

static int			count_files(void)
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
		if (dir_ent->d_name[0] == '.')
			continue ;
		files_num++;
	}
	closedir(dir);
	return (files_num);
}

static void			put_all_file_names(t_file_data *file_data_arr,
																int files_num)
{
	int	index;

	index = files_num - 1;
	while (index >= 0)
	{
		ft_putendl(file_data_arr[index].name);
		index--;
	}
}

static void			perror_with_error_flag(void)
{
	perror("opendir");
	g_error_flag = true;
}

static t_file_data	*get_all_files_data(DIR *dir, const int files_num)
{
	size_t			index;
	struct dirent	*dir_ent;
	t_file_data		*file_data_arr;
	t_stat			dent_stat;

	file_data_arr = malloc(sizeof(t_file_data) * (files_num + 1));
	if (file_data_arr == NULL)
		g_error_flag = true;
	index = 0;
	while ((dir_ent = readdir(dir)) != NULL)
	{
		if (dir_ent->d_name[0] == '.')
			continue ;
		if (lstat(dir_ent->d_name, &dent_stat) != SUCCESS)
		{
			perror(dir_ent->d_name);
			continue ;
		}
		file_data_arr[index].name = ft_strdup(dir_ent->d_name);
		file_data_arr[index].tv_sec = dent_stat.st_mtimespec.tv_sec;
		file_data_arr[index].tv_nsec = dent_stat.st_mtimespec.tv_nsec;
		index++;
	}
	return (file_data_arr);
}

void				list_dir(void)
{
	DIR			*dir;
	t_file_data	*file_data_arr;
	const int	files_num = count_files();

	dir = opendir(CURRENT_DIR_PATH);
	if (dir == NULL)
		return (perror_with_error_flag());
	if (files_num == ERROR)
		return (perror_with_error_flag());
	file_data_arr = get_all_files_data(dir, files_num);
	closedir(dir);
	sort_files_by_time(file_data_arr, files_num);
	if (g_error_flag == true)
		return ;
	put_all_file_names(file_data_arr, files_num);
	SAFE_FREE(file_data_arr);
}
