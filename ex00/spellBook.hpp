/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spellBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:43:27 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/29 10:05:05 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# define CLR "\033[0m"
# define BOLD "\033[1m"
# define UNDL "\033[4m"
# define ITAL "\033[3m"
# define STRK "\033[9m"

# define BLK "\033[0;30m"
# define RED "\033[0;31m"
# define GRN "\033[0;32m"
# define YLW "\033[0;33m"
# define BLU "\033[0;34m"
# define PRP "\033[0;35m"
# define CYN "\033[0;36m"
# define WHT "\033[0;37m"

# define RGB(r, g, b) "\033[38;2;" #r ";" #g ";" #b "m"
# define DSTR RGB(200, 200, 0)

# define PRINT std::cout <<
# define AND <<
# define ENDL << std::endl
# define TAB "\t"
# define NEWL std::cout << std::endl
