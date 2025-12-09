/*

*/

#ifndef STATE_SYSTEM_TYPE_HEADER
#define STATE_SYSTEM_TYPE_HEADER

#include "System.hpp"

namespace tppo {
    class StateSystem : System {
        
    protected:
        
        
    public:
        //
        StateSystem(ComponentManager &componentManager, EntityManager &entityManager);
        
        //
        ~StateSystem();
    
        //
        void Init();
        
    };
}

#endif //STATE_SYSTEM_TYPE_HEADER