/*

*/

#include <SystemManager.hpp>

namespace tppo {
    //
    SystemManager::SystemManager(ComponentManager &componentManager, EntityManager &entityManager)
        : inputSystem(componentManager, entityManager)
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
    void SystemManager::Init() {
        visualSystem.Init();
    }
}