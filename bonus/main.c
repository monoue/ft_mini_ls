/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:33:20 by monoue            #+#    #+#             */
/*   Updated: 2020/12/04 08:15:01 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"

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
		if (dir_ent->d_name[0] == '.')
			continue ;
		files_num++;
	}
	closedir(dir);
	return (files_num);
}

// void	put_file_names(t_stat *dent_stats_arr, int files_num)
// {
// 	int	index;

// 	index = 0;
// 	while (index < files_num)
// 	{
// 		// ft_putendl();
// 		index++;
// 	}
// }

typedef struct	s_file_data {
	char	*name;
	time_t	tv_sec;

	long	tv_nsec;
	// long	tv_nsec;
}				t_file_data;
#include <stdio.h>


void	put_file_data_arr(t_file_data *file_data_arr, int files_num)
{
	int	index;

	// t_file_data file_data;

	// index = 0;
	index = files_num - 1;
	while (index >= 0)
	{
		ft_putendl(file_data_arr[index].name);
		// file_data = file_data_arr[index];
		// printf("name: %s, sec: %ld\n", file_data.name, file_data.tv_sec);
		// DS(file_data.name);
		// DL(file_data.tv_sec);
		// DL(file_data.tv_nsec);
		index--;
	}
}

void	swap_files(t_file_data *file_data_arr, int left, int right)
{
	t_file_data tmp;

	tmp = file_data_arr[left];
	file_data_arr[left] = file_data_arr[right];
	file_data_arr[right] = tmp;
}

void	sort_files_by_name(t_file_data *file_data_arr, int files_num)
{
	int l_index;
	int	r_index;
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
			if ((left.tv_sec == right.tv_sec) && (left.tv_nsec == right.tv_nsec) && (ft_strcmp(left.name, right.name) > 0))
				swap_files(file_data_arr, l_index, r_index);
			r_index++;
		}
		l_index++;
	}
}

void	sort_files_by_tv_nsec(t_file_data *file_data_arr, int files_num)
{
	int l_index;
	int	r_index;
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

void	sort_files_by_tv_sec(t_file_data *file_data_arr, int files_num)
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

void	sort_files(t_file_data *file_data_arr, int files_num)
{
	sort_files_by_tv_sec(file_data_arr, files_num);
	sort_files_by_tv_nsec(file_data_arr, files_num);
	sort_files_by_name(file_data_arr, files_num);
}

static void	list_dir(void)
{
	DIR				*dir;
	struct dirent	*dir_ent;

	dir = opendir(CURRENT_DIR_PATH);
	if (dir == NULL)
	{
		perror("opendir");
		return ;
	}
	// dent_stat の配列用意
	// 開き直して、数の分 malloc ?

	// t_stat	*dent_stats_arr;
	t_file_data *file_data_arr;

	int files_num = count_files();
	if (files_num == ERROR)
	{
		perror("opendir");
		return ;
	}
	// dent_stats_arr = malloc(sizeof(t_stat) * (files_num + 1));
	file_data_arr = malloc(sizeof(t_file_data) * (files_num + 1));


	size_t	index;
	index = 0;
	while ((dir_ent = readdir(dir)) != NULL)
	{
		t_stat	dent_stat;
		char *d_name = dir_ent->d_name;
		if (d_name[0] == '.')
			continue ;
		// if (lstat(d_name, &dent_stats_arr[index]) != SUCCESS)
		if (lstat(d_name, &dent_stat) != SUCCESS)
		{
			perror(d_name);
			continue ;
		}
		file_data_arr[index].name = d_name;
		// printf("%ld\n", dent_stat.st_mtimespec.tv_sec);
		// printf("%ld\n", dent_stat.st_mtimespec.tv_nsec);
		file_data_arr[index].tv_sec = dent_stat.st_mtimespec.tv_sec;
		// DL(dent_stat.st_mtimespec.tv_nsec);

		file_data_arr[index].tv_nsec = dent_stat.st_mtimespec.tv_nsec;

		// file_data_arr[index].name = d_name;
		// file_data_arr[index].tv_sec = dent_stat.st_mtimespec.tv_sec;

		// dent_stat の配列に入れていく
		// put_l_option(dent_stat);
		// bool color = true;
		// bool link_ok = true;

		// if (color == true)
		// 	put_name_with_option_gg(d_name, dent_stat.st_mode, link_ok);
		// else

			// ft_putendl(d_name);
		// put_ff_option(dent_stat.st_mode)	;
		index++;
	}
	closedir(dir);
	sort_files(file_data_arr, files_num);
	// sort_dent_stats(dent_stats_arr);
	put_file_data_arr(file_data_arr, files_num);
	// 配列をソート

}

int	main(int argc, char *argv[])
{
	(void)argv;
	if (argc > 1)
	{
		ft_putstr_fd(ARG_ERR, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	list_dir();
	return (EXIT_SUCCESS);
}
