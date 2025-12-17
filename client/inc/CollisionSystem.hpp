/*

*/

#ifndef COLLISION_SYSTEM_TYPE_HEADER
#define COLLISION_SYSTEM_TYPE_HEADER

#include "System.hpp"

#include "ComponentManager.hpp"
#include "EntityManager.hpp"

namespace tppo {
    class CollisionSystem : public System {
        
    protected:
        
        
    public:
        //
        CollisionSystem(ComponentManager &componentManager, EntityManager &entityManager);
        
        //
        ~CollisionSystem();
    
        //
        void Init();
    
        //
        void Update();
        
    };
}

#endif //COLLISION_SYSTEM_TYPE_HEADER