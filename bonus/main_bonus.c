/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:33:20 by monoue            #+#    #+#             */
/*   Updated: 2020/12/04 16:11:31 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls_bonus.h"

// -1
// -r
// -F
// -G
// -a
// -t

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

bool	file_has_type_specifier(mode_t mode)
{
	if (S_ISREG(mode))
		return (mode & S_IXUGO);
	else
		return (S_ISDIR(mode) || S_ISLNK(mode) || S_ISFIFO(mode) || S_ISSOCK(mode));
}

void	set_element_plus_spaces_len(t_file_data *file_data_arr, int files_num)
{
	int		index;
	bool	file_has_type_specifier_flag;

	file_has_type_specifier_flag = false;
	index = 0;
	while (index < files_num)
	{
		g_file_name_plus_spaces_len = MAX(ft_strlen(file_data_arr[index].name) + 1, g_file_name_plus_spaces_len);
		if (g_ff_flag == true && file_has_type_specifier_flag == false)
		{
			file_has_type_specifier_flag = file_has_type_specifier(file_data_arr[index].mode);
		}
		index++;
	}
	if (file_has_type_specifier_flag == true)
		g_file_name_plus_spaces_len++;
}

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


static void			perror_with_error_flag(void)
{
	perror("opendir");
	g_error_flag = true;
}

static void	list_dir(void)
{
	DIR				*dir;
	struct dirent	*dir_ent;
	t_file_data		*file_data_arr;

	dir = opendir(CURRENT_DIR_PATH);
	if (dir == NULL)
		return (perror_with_error_flag());
	int files_num = count_files();
	if (files_num == ERROR)
		return (perror_with_error_flag());
	file_data_arr = malloc(sizeof(t_file_data) * (files_num + 1));

	size_t	index = 0;
	while ((dir_ent = readdir(dir)) != NULL)
	{
		t_stat	dent_stat;
		if (g_a_flag == true)
			;
		else if (g_aa_flag == true)
		{
			if (is_current_or_parent_dir(dir_ent->d_name))
				continue ;
		}
		else if (dir_ent->d_name[0] == '.')
			continue ;
		if (lstat(dir_ent->d_name, &dent_stat) != SUCCESS)
		{
			perror(dir_ent->d_name);
			continue ;
		}
		file_data_arr[index].name = dir_ent->d_name;
		file_data_arr[index].tv_sec = dent_stat.st_mtimespec.tv_sec;
		file_data_arr[index].tv_nsec = dent_stat.st_mtimespec.tv_nsec;
		file_data_arr[index].mode = dent_stat.st_mode;

		// bool color = true;
		// bool link_ok = true;

		// if (g_gg_flag == true)
		// 	put_name_with_option_gg(dir_ent->d_name, dent_stat.st_mode, link_ok);
		// put_ff_option(dent_stat.st_mode)	;
		index++;
	}
	closedir(dir);
	set_element_plus_spaces_len(file_data_arr, files_num);
	sort_files(file_data_arr, files_num);
	put_all_file_names(file_data_arr, files_num);
	SAFE_FREE(file_data_arr);
}

int	main(int argc, char *argv[])
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
