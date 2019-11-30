///-------------------------------------------------------------------------------------------------
// file: GameEngine.cpp
//
// author: Willia Barry
// date: 10/28/2019
//
// summary:	The Game Engine
///-------------------------------------------------------------------------------------------------
#include "Core.h"
#include "GameEngine.h"

#include "AssetManager.h"
#include "FileSystem.h"
#include "GameObjectManager.h"
#include "InputManager.h"
#include "RenderSystem.h"

extern void registerEngineClasses();

void GameEngine::initialize(ISystem* _projectEngine)
{
    registerEngineClasses();
    
	FileSystem::instance().initialize();
	AssetManager::instance().initialize();
	InputManager::instance().initialize();
	RenderSystem::instance().initialize();
    GameObjectManager::instance().initialize();
    projectEngine = _projectEngine;
    if (projectEngine != nullptr)
    {
        projectEngine->initialize();
    }
}

void GameEngine::gameLoop()
{
	std::chrono::time_point<std::chrono::system_clock> _time;
	std::chrono::duration<float> deltaTime(0);
	std::chrono::duration<float> totalTime(0);

    while (true)
    {
		_time = std::chrono::system_clock::now();

		InputManager::instance().update(deltaTime.count());

        FileSystem::instance().update(deltaTime.count());

        AssetManager::instance().update(deltaTime.count());

        GameObjectManager::instance().update(deltaTime.count());
		
        if (projectEngine != nullptr)
        {
            projectEngine->update(deltaTime.count());
        }

        RenderSystem::instance().update(deltaTime.count());

        deltaTime = std::chrono::system_clock::now() - _time;
	}
}