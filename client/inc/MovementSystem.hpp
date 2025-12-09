/*

*/

#ifndef MOVEMENT_SYSTEM_TYPE_HEADER
#define MOVEMENT_SYSTEM_TYPE_HEADER

#include "System.hpp"

namespace tppo {
    class MovementSystem : System {
        
    protected:
        
        
    public:
        //
        MovementSystem(ComponentManager &componentManager, EntityManager &entityManager);
        
        //
        ~MovementSystem();
    
        //
        void Init();
        
    };
}

#endif //MOVEMENT_SYSTEM_TYPE_HEADER