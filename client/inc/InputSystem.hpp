/*

*/

#ifndef INPUT_SYSTEM_TYPE_HEADER
#define INPUT_SYSTEM_TYPE_HEADER

#include "System.hpp"

namespace tppo {
    class InputSystem : System {
        
    protected:
        
        
    public:
        //
        InputSystem(ComponentManager &componentManager, EntityManager &entityManager);
        
        //
        ~InputSystem();
    
        //
        void Init();
        
    };
}

#endif //INPUT_SYSTEM_TYPE_HEADER