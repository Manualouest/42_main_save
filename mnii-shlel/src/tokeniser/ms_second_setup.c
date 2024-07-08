/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_second_setup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:20:40 by mbirou            #+#    #+#             */
/*   Updated: 2024/07/08 11:36:10 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokeniser.h>

int	ms_get_var_start(char *arg, int *var_len)
{
	int	quote_level;
	int	i;
	int	is_num;

	quote_level = 0;
	i = -1;
	while (arg[++i])
	{
		quote_level = ms_change_quote_level(arg, i, quote_level);
		printf("get_var quote: %d(%d, |%c|)\n", quote_level, i, arg[i]);
		if (quote_level % 2 == 0 && arg[i] == '$')
		{
			if (!arg[i + 1] || arg[i + 1] == ' ')
				continue ;
			if (ms_change_quote_level(arg, i + 1, 0) != 0)
				return (i);
			is_num = 0;
			if (ft_isdigit(arg[i + 1]))
				is_num = 1;
			while (arg[++*var_len + i] && (!is_num || *var_len != 2
					|| (is_num && !ft_isdigit(arg[*var_len + i])))
				&& (ft_isalnum(arg[*var_len + i]) || arg[*var_len + i] == '_'))
				;
			return (i);
		}
	}
	return (-1);
}

char *ms_get_var(char *arg, int var_pos, int var_len, char **envp)
{
	char	*var_name;
	char	*raw_content;
	char	*var_content;

	if (var_pos == -1)
		return (NULL);
	if (var_len >=0 )
		var_name = ft_substr(arg, var_pos + 1, var_len);
	else
		var_name = ft_calloc(sizeof(char), 1);
	if (!var_name)
		return (NULL);
	printf("var_name: |%s|\n", var_name);
	if (var_name[0] == 0)
		return (var_name);
	raw_content = envp_find(envp, var_name);
	printf("raw_content: |%s|\n", raw_content);
	free(var_name);
	if (!raw_content)
	{
		raw_content = ft_calloc(sizeof(char), 1);
		return (raw_content);
	}
	var_content = ft_strdup(&(ft_strchr(raw_content, '=')[1]));
	return(var_content);
}

int	ms_insert(char **arg, char *var_content, int var_pos, int var_len)
{
	char	*arg_start;
	char	*new_arg;

	if (var_pos - 1 > 0)
		arg_start = ft_substr(arg[0], 0, var_pos - 1);
	else
		arg_start = ft_calloc(sizeof(char), 1);
	if (!arg_start)
		return (0);
	if (var_len > var_pos)
		new_arg = ms_tripple_join(arg_start, var_content, &arg[0][var_len + 1], 110);
	else
		new_arg = ms_tripple_join(arg_start, var_content, &arg[0][var_pos + 1], 110);
	if (!new_arg)
		return (0);
	free(arg[0]);
	arg[0] = new_arg;
	return (1);
}

char	ms_get_quote_to_index(char *arg, int pos)
{
	int	i;
	int	quote_level;

	i = -1;
	quote_level = 0;
	while(arg[++i])
		quote_level = ms_change_quote_level(arg, i, quote_level);
	if (quote_level == 0)
		return (NULL);
	else if (quote_level == 1)
		return ((char)(-2));
	else if (quote_level == 2)
		return ((char)(-1));
}

int	ms_insert_spaced(char **arg, char *var_content, int var_pos, int var_len)
{
	char	quote;
	int		i;

	quote = ms_get_quote_to_index(arg[0], var_pos);
	i = -1;
	tab_append(arg, ft_strdup(&arg[0][var_len + 1]), 1);
	while (arg[0][++i])
	{
		if (arg[0][i] != ' ' && (i == 0 || arg[0][i - 1] == ' '))
		{
			
		}
	}
	return (1);
}

int	ms_expand_loop(char ***args, char **envp)
{
	int		index;
	int		var_pos;
	int		var_len;
	char	*var_content;

	index = -1;
	while (args[0][++index])
	{
		if (ms_has_dollar(args[0][index]))
		{
			var_len = 0;
			var_pos = ms_get_var_start(args[0][index], &var_len);
			var_len -= 1;
			printf("var_pos: %d(%c), var_len: %d(%c), arg: |%s|\n", var_pos, args[0][index][var_pos], var_len, args[0][index][var_len], args[0][index]);
			var_content = ms_get_var(args[0][index], var_pos, var_len, envp);
			printf("var_content: |%s|\n", var_content);
			if (!var_content)
				return (0);
			if ((!ft_strchr(var_content, ' ') && !ms_insert_spaced(&args[0]
						[index], var_content, var_pos, var_len))
				|| !ms_insert(&args[0][index], var_content, var_pos, var_len))
				return (0);
			printf("check arg: |%s|\n", args[0][index]);
			if (ms_has_dollar(args[0][index]))
				index --;
		}
	}
	return (1);
}

void	ms_setup_round_two(t_cmd *cmd, char **envp)
{
	int		args_i;
	t_cmd	*cpy_cmd;

	cpy_cmd = cmd;
	ms_separate_symbols_base(cmd);
	while (cpy_cmd)
	{
		args_i = -1;
		cpy_cmd->args = ms_remove_empty_chars(cpy_cmd->args);
		if (!ms_expand_loop(&cpy_cmd->args, envp))
		{
			ms_handle_errors(NULL, 0, MS_FAIL_STRUCT, NULL);
			ms_free_cmd(cmd);
			return ;
		}
		cpy_cmd = cpy_cmd->next;
	}
	ms_remove_hiders(cmd, -1);
	ms_in_out_files_setup(cmd, envp);
}
