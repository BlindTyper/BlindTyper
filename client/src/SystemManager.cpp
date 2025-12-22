/*

*/

#include "SystemManager.hpp"

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
        , audioSystem(componentManager, entityManager)
        , stateSystem(componentManager, entityManager)
    {
        
    }
    
    //
    SystemManager::~SystemManager() {
        
    }
        
    //
    bool SystemManager::IsRunning() {
        auto &window = entityManager.GetSystemResources()->GetWindow().GetWindow();
        if (!window.isOpen()) {
            isRunning = 0;
        }
        return isRunning;
    }
    
    //
    void SystemManager::Init() {
        visualSystem.Init();
        inputSystem.Init();
        movementSystem.Init();
        lifetimeSystem.Init();
        damageSystem.Init();
        stateSystem.Init();
    }
    
    //
    void SystemManager::Update() {
        inputSystem.Update();
        movementSystem.Update();
        lifetimeSystem.Update();
        damageSystem.Update();
        stateSystem.Update();
        visualSystem.Update();
    }
}