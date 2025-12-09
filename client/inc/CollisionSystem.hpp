/*

*/

#ifndef COLLISION_SYSTEM_TYPE_HEADER
#define COLLISION_SYSTEM_TYPE_HEADER

#include "System.hpp"

namespace tppo {
    class CollisionSystem : System {
        
    protected:
        
        
    public:
        //
        CollisionSystem(ComponentManager &componentManager, EntityManager &entityManager);
        
        //
        ~CollisionSystem();
    
        //
        void Init();
        
    };
}

#endif //COLLISION_SYSTEM_TYPE_HEADER