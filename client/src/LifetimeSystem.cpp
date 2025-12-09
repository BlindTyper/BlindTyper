/*

*/

#include <LifetimeSystem.hpp>

namespace tppo {
    //
    LifetimeSystem::LifetimeSystem(ComponentManager &componentManager, EntityManager &entityManager)
        : System(componentManager, entityManager) {
        
    }
    
    //
    LifetimeSystem::~LifetimeSystem() {
        
    }
    
    //
    void LifetimeSystem::Init() {
        
    }
}