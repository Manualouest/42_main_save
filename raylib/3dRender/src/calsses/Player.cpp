/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:39:32 by mbirou            #+#    #+#             */
/*   Updated: 2025/01/24 19:21:10 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Player.hpp>
#include <unistd.h>

Player::Player() : _pos((Vector3){0, 0, 0}), _angle(0)
{
	_state = IDLE;
	_model = LoadModel("objects/oiiaioooooiai_cat.glb");
	_camera = {0};
    _camera.position = (Vector3){10, 10, 10};
    _camera.target = _pos;
    _camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    _camera.fovy = 60.0f;
    _camera.projection = CAMERA_PERSPECTIVE;
	_updateCamera(1);
}

Player::Player(const Vector3 &pos, const float &angle) : _pos(pos), _angle(angle)
{
	_state = IDLE;
	_model = LoadModel("objects/oiiaioooooiai_cat.glb");
	_camera = {0};
    _camera.position = _pos;
	_camera.position.x -= cos(_angle * TORAD) * 5;
	_camera.position.z -= sin(_angle * TORAD) * 5;
	_camera.position.y += 2;
    _camera.target = _pos;
    _camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    _camera.fovy = 60.0f;
    _camera.projection = CAMERA_PERSPECTIVE;
	_updateCamera(1);
}

Player::~Player()
{

}

void	Player::_inputs(float deltaTime)
{
	if (IsKeyDown(KEY_T))
	{
		_pos.x = -10;
		_pos.y = -5;
		_pos.z = -10;
		if (_state == DANCING)
			_angle = _angleSave;
		_updateCamera(deltaTime);
	}
	if (IsKeyDown(KEY_UP) + IsKeyDown(KEY_DOWN) != 1 && IsKeyDown(KEY_RIGHT) + IsKeyDown(KEY_LEFT) != 1)
	{
		if (_state == IDLE)
			_angleSave = _angle;
		_state = DANCING;
	}
	else
	{
		if (_state == DANCING)
			_angle = _angleSave;
		_state = IDLE;
	}
	PollInputEvents();
	if (_state == DANCING)
		_angle += 540 * deltaTime;
	else
		_angle += (IsKeyDown(KEY_RIGHT) - IsKeyDown(KEY_LEFT)) * 120 * deltaTime;
		// _angle -= 0.5 * (GetScreenWidth() / 2 - GetMousePosition().x);
	if (_angle <= 0)
		_angle += 360;
	else if (_angle >= 360)
		_angle -= 360;
	_pos.x += (IsKeyDown(KEY_UP) - IsKeyDown(KEY_DOWN)) * cos(_angle * TORAD + 0.5F * PI) * 20 * deltaTime;
	_pos.z += (IsKeyDown(KEY_UP) - IsKeyDown(KEY_DOWN)) * sin(_angle * TORAD + 0.5F * PI) * 20 * deltaTime;
	_pos.y += (IsKeyDown(KEY_X) - IsKeyDown(KEY_Z)) * 5 * deltaTime;
}

void	Player::_updateCamera(float deltaTime)
{
    _camera.position = _pos;
	_camera.position.x -= cos(_angle * TORAD + 0.5F * PI) * 3.5F;
	_camera.position.y += 2.15;
	_camera.position.z -= sin(_angle * TORAD + 0.5F * PI) * 3.5F;
    
	_camera.target.y = _pos.y + 1.F;
	_camera.target.z = _pos.z - (IsKeyDown(KEY_RIGHT) - IsKeyDown(KEY_LEFT)) * sin(_angle * TORAD) * 3 * deltaTime;
	_camera.target.x = _pos.x - (IsKeyDown(KEY_RIGHT) - IsKeyDown(KEY_LEFT)) * cos(_angle * TORAD) * 3 * deltaTime;
}

void	Player::update()
{
	float	deltaTime = GetFrameTime();
	_inputs(deltaTime);
	DrawModelEx(_model, _pos, (Vector3){0, 1, 0}, -_angle, (Vector3){2, 2, 2}, WHITE);
	if (_state == IDLE)
		_updateCamera(deltaTime);
	UpdateCamera(&_camera, CAMERA_PERSPECTIVE);
}

Camera	&Player::getCamera()
{
	return (_camera);
}
