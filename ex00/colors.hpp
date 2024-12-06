/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:43:27 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/06 18:03:01 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_HPP
# define COLORS_HPP

# define CLR "\033[0m"
# define BOLD "\033[1m"
# define UNDL "\033[4m"
# define ITAL "\033[3m"
# define STRK "\033[9m"

# define BLK "\033[0;90m"
# define RED "\033[0;91m"
# define GRN "\033[0;92m"
# define YLW "\033[0;93m"
# define BLU "\033[0;94m"
# define PRP "\033[0;95m"
# define CYN "\033[0;96m"
# define WHT "\033[0;97m"

# define RGB(r, g, b) "\033[38;2;" #r ";" #g ";" #b "m"

#endif