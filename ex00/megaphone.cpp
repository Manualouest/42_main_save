/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:29:51 by mbirou            #+#    #+#             */
/*   Updated: 2024/11/23 15:32:04 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	std::string words;
	std::string::iterator letter;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < argc; ++i)
	{
		words = std::string(argv[i]);
		for (letter = words.begin(); letter != words.end(); letter++)
			std::cout << (char)toupper(*letter);
		if (argc - i > 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}
