/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:33:20 by monoue            #+#    #+#             */
/*   Updated: 2020/12/02 17:42:39 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"

// bonus_start
void	print_type_indicator(mode_t mode)
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
// bonus_end

void	print_mode(mode_t mode)
{
	char str[13];
	
	// ブロックデバイス
	
	str[0] = (S_ISBLK(mode))  ? 'b' :
		(S_ISCHR(mode))  ? 'c' :
		(S_ISDIR(mode))  ? 'd' :
		(S_ISREG(mode))  ? '-' :
		(S_ISFIFO(mode)) ? 'p' :
		(S_ISLNK(mode))  ? 'l' :
		(S_ISSOCK(mode)) ? 's' : '?';
	str[1] = mode & S_IRUSR ? 'r' : '-';
	str[2] = mode & S_IWUSR ? 'w' : '-';
	str[3] = mode & S_ISUID ? (mode & S_IXUSR ? 's' : 'S')
							: (mode & S_IXUSR ? 'x' : '-');
	str[4] = mode & S_IRGRP ? 'r' : '-';
	str[5] = mode & S_IWGRP ? 'w' : '-';
	str[6] = mode & S_ISGID ? (mode & S_IXGRP ? 's' : 'S')
							: (mode & S_IXGRP ? 'x' : '-');
	str[7] = mode & S_IROTH ? 'r' : '-';
	str[8] = mode & S_IWOTH ? 'w' : '-';
	str[9] = mode & S_ISVTX ? (mode & S_IXOTH ? 't' : 'T')
							: (mode & S_IXOTH ? 'x' : '-');
	str[10] = ' ';	
	str[11] = ' ';	
	str[12] = '\0';	
	ft_putstr(str);
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
		struct stat	dent_stat;
		char *d_name = dir_ent->d_name;
		if (d_name[0] == '.')
			continue ;
		if (lstat(d_name, &dent_stat) != 0)	
		{
			perror(d_name);
			continue ;
		}
		print_mode(dent_stat.st_mode);
		
		ft_putnbr((int)dent_stat.st_nlink);
		ft_putchar(' ');
		ft_putnbr(dent_stat.st_uid);
		ft_putchar(' ');
		ft_putnbr(dent_stat.st_gid);
		ft_putchar(' ');


		ft_putstr(d_name);
		// bonus_start
		print_type_indicator(dent_stat.st_mode)	;
		// bonus_end
		ft_putchar('\n');
	}
	closedir(dir);
}

int	main()
{
	list_dir();
	return (EXIT_SUCCESS);
}
