/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 19:17:10 by mbirou            #+#    #+#             */
/*   Updated: 2024/08/27 19:50:41 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokeniser.h>

int	ms_insert(char **arg, char **var_content, int var_pos, int *var_len)
{
	char	*arg_start;
	char	*new_arg;
	int		content_lenght;

	if (var_pos >= 0)
		arg_start = ft_substr(arg[0], 0, var_pos);
	else
		arg_start = ft_calloc(sizeof(char), 1);
	if (!arg_start)
		return (0);
	content_lenght = ft_strlen(*var_content);
	if (*var_len > 0)
		new_arg = ms_tripple_join(arg_start, *var_content,
				&arg[0][var_pos + *var_len + 1], 110);
	else
		new_arg = ms_tripple_join(arg_start, *var_content,
				&arg[0][var_pos + 1], 110);
	*var_content = NULL;
	*var_len = content_lenght;
	if (!new_arg)
		return (0);
	free(arg[0]);
	arg[0] = new_arg;
	return (1);
}

char	ms_cut_param(char ***arg, int arg_i, int var_pos, int var_len)
{
	char	quote;

	quote = ms_get_quote_to_index(arg[0][arg_i], var_pos);
	if (quote == 0)
	{
		arg[0] = tab_append(arg[0],
				ft_strdup(&arg[0][arg_i][var_pos + var_len]), arg_i + 1);
		arg[0][arg_i] = ms_replace_str(arg[0][arg_i],
				ft_substr(arg[0][arg_i], 0, var_pos));
	}
	else
	{
		arg[0] = tab_append(arg[0], ft_strjoin(&(char){-1},
					&arg[0][arg_i][var_pos + var_len]), arg_i + 1);
		arg[0][arg_i] = ms_replace_str(arg[0][arg_i],
				ft_substr(arg[0][arg_i], 0, var_pos));
		arg[0][arg_i] = ms_replace_str(arg[0][arg_i],
				ft_strjoin(arg[0][arg_i], &(char){-1}));
	}
	return (quote);
}

int	ms_get_quoted(char ***arg, int arg_i, char **cut_var, int *i)
{
	*i = *i - 1;
	if (arg[0][arg_i][ft_strlen(arg[0][arg_i])] < 0)
	{
		arg[0][arg_i + 1] = ms_tripple_join(&(char){-1},
				cut_var[*i], arg[0][arg_i + 1], 11);
		arg[0][arg_i] = ms_tripple_join(arg[0][arg_i],
				cut_var[0], &(char){-1}, 110);
	}
	else
	{
		arg[0][arg_i + 1] = ms_tripple_join("",
				cut_var[*i], arg[0][arg_i + 1], 11);
		arg[0][arg_i] = ms_tripple_join(arg[0][arg_i], cut_var[0], "", 110);
	}
	if (arg[0][arg_i + 1])
		return (1);
	return (0);
}

int	ms_insert_spaced(char ***arg, int arg_i, int var_pos, int var_len)
{
	char	**cut_var;
	char	*tp_str;
	char	quote[1];
	int		stopper;
	int		i;

	if (!arg[0][arg_i])
		return (0);
	tp_str = ft_substr(arg[0][arg_i], var_pos, var_len);
	cut_var = ft_split(tp_str, ' ');
	free(tp_str);
	quote[0] = ms_cut_param(arg, arg_i, var_pos, var_len);
	i = tablen(cut_var);
	stopper = ms_get_quoted(arg, arg_i, cut_var, &i);
	while (--i >= stopper)
	{
		if (quote[0] == 0)
			arg[0] = tab_append(arg[0], cut_var[i], arg_i + 1);
		else
			arg[0] = tab_append(arg[0], ms_tripple_join(&(char){-1},
						cut_var[i], &(char){-1}, 10), arg_i + 1);
	}
	free(cut_var);
	return (1);
}

int	ms_expand_loop(char ***args, char **envp)
{
	int		index;
	int		pos;
	int		var_len;
	char	*var;

	index = -1;
	while (args[0][++index])
	{
		if (ms_has_dollar(args[0][index]))
		{
			ms_setup_var_info(args, index, &pos, &var_len);
			var = ms_get_var(args[0][index], pos, var_len, envp);
			if (!var)
				return (0);
			if (ft_strchr(var, ' ') && ms_insert(&args[0][index], &var, pos,
				&var_len) && !ms_insert_spaced(args, index, pos, var_len))
				return (0);
			else if (var && !ft_strchr(var, ' ') && !ms_insert(&args[0][index],
				&var, pos, &var_len))
				return (0);
			if (ms_has_dollar(args[0][index]))
				index --;
		}
	}
	return (1);
}
