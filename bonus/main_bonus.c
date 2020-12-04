/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:33:20 by monoue            #+#    #+#             */
/*   Updated: 2020/12/04 21:55:41 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls_bonus.h"

static void	perror_with_error_flag(void)
{
	perror("opendir");
	g_error_flag = true;
}

static int	set_file_data(t_file_data *file_data, char *file_name)
{
	t_stat	dent_stat;

	if (g_a_flag == true)
		;
	else if (g_aa_flag == true)
	{
		if (is_current_or_parent_dir(file_name))
			return (CONTINUE);
	}
	else if (file_name[0] == '.')
		return (CONTINUE);
	if (lstat(file_name, &dent_stat) != SUCCESS)
	{
		perror(file_name);
		return (CONTINUE);
	}
	file_data->name = file_name;
	file_data->tv_sec = dent_stat.st_mtimespec.tv_sec;
	file_data->tv_nsec = dent_stat.st_mtimespec.tv_nsec;
	file_data->mode = dent_stat.st_mode;
	return (NO_CONTINUE);
}

static void	set_all_files_data(t_file_data *file_data_arr, DIR *dir)
{
	size_t			index;
	struct dirent	*dir_ent;

	index = 0;
	while ((dir_ent = readdir(dir)) != NULL)
	{
		if (set_file_data(&file_data_arr[index], dir_ent->d_name) == CONTINUE)
			continue ;
		index++;
	}
}

static void	list_dir(void)
{
	DIR			*dir;
	t_file_data	*file_data_arr;
	int			files_num;

	dir = opendir(CURRENT_DIR_PATH);
	if (dir == NULL)
		return (perror_with_error_flag());
	files_num = count_files();
	if (files_num == ERROR)
		return (perror_with_error_flag());
	file_data_arr = malloc(sizeof(t_file_data) * (files_num + 1));
	set_all_files_data(file_data_arr, dir);
	closedir(dir);
	set_element_plus_spaces_len(file_data_arr, files_num);
	sort_files(file_data_arr, files_num);
	put_all_file_names(file_data_arr, files_num);
	SAFE_FREE(file_data_arr);
}

int			main(int argc, char *argv[])
{
	if (parse_all_command_arguments(argc, argv) == ERROR)
	{
		ft_putstr_fd(ILL_OPT_MSG, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	list_dir();
	if (g_error_flag == true)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
