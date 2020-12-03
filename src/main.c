/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:33:20 by monoue            #+#    #+#             */
/*   Updated: 2020/12/03 13:34:59 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"



size_t	count_files(void)
{
	DIR				*dir;
	size_t			files_num;

	dir = opendir(CURRENT_DIR_PATH);
	if (dir == NULL)
	{
		perror("opendir");
		return (0);
	}
	files_num = 0;
	while (readdir(dir))
		files_num++;
	closedir(dir);
	return (files_num - 1);
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
	
	while ((dir_ent = readdir(dir)) != NULL)
	{
		t_stat	dent_stat;
		char *d_name = dir_ent->d_name;
		if (d_name[0] == '.')
			continue ;
		if (lstat(d_name, &dent_stat) != SUCCESS)
		{
			perror(d_name);
			continue ;
		}
		// dent_stat の配列に入れていく
		// put_l_option(dent_stat);
		// bool color = true;
		// bool link_ok = true;

		// if (color == true)
		// 	put_name_with_option_gg(d_name, dent_stat.st_mode, link_ok);
		// else
			ft_putendl(d_name);
		// put_ff_option(dent_stat.st_mode)	;
	}
	// 配列をソート

	closedir(dir);
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
