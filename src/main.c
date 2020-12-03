/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:33:20 by monoue            #+#    #+#             */
/*   Updated: 2020/12/03 10:58:35 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"

void	put_ff_option(mode_t mode)
{
	if (S_ISREG(mode))
	{
		if (mode & S_IXUGO)
			ft_putchar('*');
	}
	else
	{
		if (S_ISDIR(mode))
			ft_putchar('/');
		else if (S_ISLNK(mode))
			ft_putchar('@');
		else if (S_ISFIFO(mode))
			ft_putchar('|');
		else if (S_ISSOCK(mode))
			ft_putchar('=');
	}
}

void	put_file_type(mode_t mode)
{
	char c;

	if (S_ISBLK(mode))
		c = 'b';
	else if (S_ISCHR(mode))
		c = 'c';
	else if (S_ISDIR(mode))
		c = 'd';
	else if (S_ISREG(mode))
		c = '-';
	else if (S_ISFIFO(mode))
		c = 'p';
	else if (S_ISLNK(mode))
		c = 'l';
	else if (S_ISSOCK(mode))
		c = 's';
	else
		c = '?';
	ft_putchar(c);
}

void	put_owner_permission(mode_t mode)
{
	char str[4];

	ft_memset(str, '-', 3);
	if (mode & S_IRUSR)
		str[0] = 'r';
	if (mode & S_IWUSR)
		str[1] = 'w';
	if (mode & S_ISUID)
	{
		if (mode & S_IXUSR)
			str[2] = 's';
		else
			str[2] = 'S';
	}
	else if (mode & S_IXUSR)
			str[2] = 'x';
	str[3] = '\0';
	ft_putstr(str);
}

void	put_group_permission(mode_t mode)
{
	char str[4];

	ft_memset(str, '-', 3);
	if (mode & S_IRGRP)
		str[0] = 'r';
	if (mode & S_IWGRP)
		str[1] = 'w';
	if (mode & S_ISGID)
	{
		if (mode & S_IXGRP)
			str[2] = 's';
		else
			str[2] = 'S';
	}
	else if (mode & S_IXGRP)
			str[2] = 'x';
	str[3] = '\0';
	ft_putstr(str);
}

void	put_other_permission(mode_t mode)
{
	char str[4];

	ft_memset(str, '-', 3);
	if (mode & S_IROTH)
		str[0] = 'r';
	if (mode & S_IWOTH)
		str[1] = 'w';
	if (mode & S_ISVTX)
	{
		if (mode & S_IXOTH)
			str[2] = 's';
		else
			str[2] = 'S';
	}
	else if (mode & S_IXOTH)
			str[2] = 'x';
	str[3] = '\0';
	ft_putstr(str);
}

void	put_permissions(mode_t mode)
{
	put_owner_permission(mode);
	put_group_permission(mode);
	put_other_permission(mode);
}

void	print_mode(mode_t mode)
{
	put_file_type(mode);
	put_permissions(mode);
	ft_putstr("  ");
}

void	put_l_option(t_stat dent_stat)
{
	print_mode(dent_stat.st_mode);

	ft_putnbr((int)dent_stat.st_nlink);
	ft_putchar(' ');
	ft_putnbr(dent_stat.st_uid);
	ft_putchar(' ');
	ft_putnbr(dent_stat.st_gid);
	ft_putchar(' ');
	// -n オプションでの、名前解決前の動作（blue_print p6）は後回し
}

void	put_name_with_color(const char *name, mode_t mode, bool link_ok)
{
	if (!link_ok)
		ft_putstr("\033[31m");
	else if (S_ISREG(mode))
	{
		if (mode & S_ISUID)
			printf("\033[37;41m");
		else if (mode & S_ISGID)
			printf("\033[30;43m");
		else if (mode & S_IXUGO)
			printf("\033[01;32m");
		else
			printf("\033[0m");
	}
	else if (S_ISDIR(mode))
	{
		if ((mode & S_ISVTX) && (mode & S_IWOTH))
			printf("\033[30;42m");
		else if (mode & S_IWOTH)
			printf("\033[34;42m");
		else if (mode & S_ISVTX)
			printf("\033[37;44m");
		else
			printf("\033[01;34m");
	}
	else if (S_ISLNK(mode))
		printf("\033[01;36m");
	else if (S_ISFIFO(mode))
		printf("\033[33m");
	else if (S_ISSOCK(mode))
		printf("\033[01;35m");
	else if (S_ISBLK(mode))
		printf("\033[01;33m");
	else if (S_ISCHR(mode))
		printf("\033[01;33m");
	printf("%s", name);
	printf("\033[0m");
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
		// put_l_option(dent_stat);
		bool color = true;
		bool link_ok = true;

		if (color == true)
			put_name_with_color(d_name, dent_stat.st_mode, link_ok);
		else
			ft_putstr(d_name);
		// put_ff_option(dent_stat.st_mode)	;
		ft_putchar('\n');
	}
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
