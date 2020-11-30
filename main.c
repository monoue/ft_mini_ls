/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:33:20 by monoue            #+#    #+#             */
/*   Updated: 2020/11/30 14:12:41 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"

int	main(int argc, char *argv[])
{
	DIR				*dir;
	struct dirent	*dir_ent;

	dir = opendir(".");
	if (dir == NULL)
	{
		perror("opendir");
		return (EXIT_FAILURE);
	}
	while ((dir_ent = readdir(dir)) != NULL)
	{
		ft_printf("%s\n", dir_ent->d_name);
	}
	closedir(dir);
	return (EXIT_SUCCESS);
}
