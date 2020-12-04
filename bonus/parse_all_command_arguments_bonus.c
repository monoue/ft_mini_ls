/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_all_command_arguments_bonus.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 13:57:45 by monoue            #+#    #+#             */
/*   Updated: 2020/12/04 14:14:11 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls_bonus.h"

static int	parse_command_argument(char *arg)
{
	const size_t	arg_len = ft_strlen(arg);
	size_t			index;

	if (arg_len == 1 || arg[0] != '-')
		return (ERROR);
	index = 1;
	while (index < arg_len)
	{
		if (arg[index] == 'A')
			g_aa_flag = true;
		else if (arg[index] == 'F')
			g_ff_flag = true;
		else if (arg[index] == 'G')
			g_gg_flag = true;
		else if (arg[index] == 'a')
			g_a_flag = true;
		else if (arg[index] == 'r')
			g_r_flag = true;
		else if (arg[index] == 't')
			g_t_flag = true;
		else if (arg[index] == '1')
			g_one_flag = true;
		else
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
