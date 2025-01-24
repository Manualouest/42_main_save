/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:10:44 by mbirou            #+#    #+#             */
/*   Updated: 2025/01/24 19:17:15 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Game.hpp>

Game::Game()
{
	InitWindow(1920, 1000, "Cat Run");
	_player = new Player();
	// _map = new Map();
}

Game::~Game()
{
	delete _player;
}

void	Game::run()
{
    SetTargetFPS(60);
	// HideCursor();
	while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            BeginMode3D(_player->getCamera());
			DrawGrid(1000, 1);
                _player->update();
            EndMode3D();

            DrawFPS(10, 10);
        EndDrawing();
		SetMousePosition(GetScreenWidth() / 2, GetScreenHeight() / 2);
    }
    CloseWindow(); 
}
