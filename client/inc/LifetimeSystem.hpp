/*

*/

#ifndef LIFETIME_SYSTEM_TYPE_HEADER
#define LIFETIME_SYSTEM_TYPE_HEADER

#include "System.hpp"

namespace tppo {
    class LifetimeSystem : System {
        
    protected:
        
        
    public:
        //
        LifetimeSystem(ComponentManager &componentManager, EntityManager &entityManager);
        
        //
        ~LifetimeSystem();
    
        //
        void Init();
    
        //
        void Update();
        
    };
}

#endif //LIFETIME_SYSTEM_TYPE_HEADER