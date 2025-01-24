/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:32:58 by mbirou            #+#    #+#             */
/*   Updated: 2025/01/24 18:33:26 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <Defines.hpp>

class Player
{
	public:
		Player();
		Player(const Vector3 &pos, const float &angle);
		~Player();

		void	update();
		Camera	&getCamera();

	protected:
		Model	_model;
		Camera	_camera;
		Vector3	_pos;
		float	_heightSave;
		float	_angle;
		float	_angleSave;
		int		_state;
		enum	_states
		{
			IDLE,
			DANCING,
		};

	private:
		void	_inputs(float deltaTime);
		void	_updateCamera(float deltaTime);
		void	_updateCam();
};