/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:08:24 by mbirou            #+#    #+#             */
/*   Updated: 2025/01/24 18:25:37 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <Defines.hpp>
#include <Player.hpp>
#include <Map.hpp>

class Game
{
	public:
		Game();
		~Game();

		void	run();

	private:
		Player	*_player;
		// Map		*_map;
};