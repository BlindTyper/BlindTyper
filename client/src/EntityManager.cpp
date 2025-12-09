/*

*/

#include "EntityManager.hpp"

namespace tppo {
    //
    EntityManager::EntityManager(ComponentManager &componentManager)
        : componentManager(componentManager)
    {
        
    }
    
    //
    EntityManager::~EntityManager() {
        
    }
    
    //
    void EntityManager::Init() {
        
    }
        
    //
    SystemResources &EntityManager::GetSystemResources() {
        if (systemResources == nullptr) {
            systemResources = std::make_shared<SystemResources>(componentManager.GetVisualResourcesComponent());
            //std::cout << "systemResources == nullptr" << std::endl;
        }
        return *systemResources;
    }
}