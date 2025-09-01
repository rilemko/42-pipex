/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _definitions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:04:01 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/24 12:20:58 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "_constants.h"

typedef int			t_fd;
typedef int			t_pid;
typedef int			t_rt;

typedef struct s_cmd
{
	t_lst	*args;
	t_lst	*cmds;
	size_t	count;
	size_t	initialized;
}	t_cmd;

typedef struct s_doc
{
	char	*tempname;
	size_t	initialized;
}	t_doc;

typedef struct s_env
{
	size_t	initialized;
	char	**paths;
}	t_env;

typedef struct s_app
{
	t_cmd	cmd;
	t_doc	doc;
	t_env	env;
	int		input_fd;
	int		min_arg;
	char	*name;
	size_t	offset;
	int		output_fd;
	int		pipe[512];
}	t_app;
