/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_option_l_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 11:35:30 by monoue            #+#    #+#             */
/*   Updated: 2020/12/04 21:25:21 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
