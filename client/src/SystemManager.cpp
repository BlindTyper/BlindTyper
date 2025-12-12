/*

*/

#include <SystemManager.hpp>

namespace tppo {
    //
    SystemManager::SystemManager(ComponentManager &componentManager, EntityManager &entityManager)
        : isRunning(1)
        , componentManager(componentManager)
        , entityManager(entityManager)
        , inputSystem(componentManager, entityManager)
        , visualSystem(componentManager, entityManager)
        , damageSystem(componentManager, entityManager)
        , movementSystem(componentManager, entityManager)
        , lifetimeSystem(componentManager, entityManager)
        , collisionSystem(componentManager, entityManager)
        , audioSystem(componentManager, entityManager)
    {
        
    }
    
    //
    SystemManager::~SystemManager() {
        
    }
        
    //
    bool SystemManager::IsRunning() {
        auto &window = entityManager.GetSystemResources().GetWindow().GetWindow();
        if (!window.isOpen()) {
            isRunning = 0;
        }
        return isRunning;
    }
    
    //
    void SystemManager::Init() {
        visualSystem.Init();
    }
    
    //
    void SystemManager::Update() {
        visualSystem.Update();
    }
}