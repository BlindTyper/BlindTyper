/*

*/

#ifndef MOVEMENT_SYSTEM_TYPE_HEADER
#define MOVEMENT_SYSTEM_TYPE_HEADER

#include "System.hpp"

#include "ComponentManager.hpp"
#include "EntityManager.hpp"

namespace tppo {
    class MovementSystem : public System {
        
    protected:
        
        
    public:
        //
        MovementSystem(ComponentManager &componentManager, EntityManager &entityManager);
        
        //
        ~MovementSystem();
    
        //
        void Init();
    
        //
        void Update();
        
    };
}

#endif //MOVEMENT_SYSTEM_TYPE_HEADER