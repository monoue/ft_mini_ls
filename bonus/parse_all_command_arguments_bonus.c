/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_all_command_arguments_bonus.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 13:57:45 by monoue            #+#    #+#             */
/*   Updated: 2020/12/04 20:29:41 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls_bonus.h"

static int	set_option(char c)
{
	if (c == 'A')
		g_aa_flag = true;
	else if (c == 'F')
		g_ff_flag = true;
	else if (c == 'G')
		g_gg_flag = true;
	else if (c == 'a')
		g_a_flag = true;
	else if (c == 'r')
		g_r_flag = false;
	else if (c == 't')
		g_t_flag = false;
	else if (c == '1')
		g_one_flag = false;
	else
		return (ERROR);
	return (SUCCESS);
}

static int	parse_command_argument(char *arg)
{
	const size_t	arg_len = ft_strlen(arg);
	size_t			index;

	if (arg_len == 1 || arg[0] != '-')
		return (ERROR);
	index = 1;
	while (index < arg_len)
	{
		if (set_option(arg[index]) == ERROR)
			return (ERROR);
		index++;
	}
	return (SUCCESS);
}

int			parse_all_command_arguments(int argc, char *argv[])
{
	int	index;

	if (argc == 1)
		return (SUCCESS);
	index = 1;
	while (index < argc)
	{
		if (parse_command_argument(argv[index]) == ERROR)
			return (ERROR);
		index++;
	}
	return (SUCCESS);
}
