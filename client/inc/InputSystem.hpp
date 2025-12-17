/*

*/

#ifndef INPUT_SYSTEM_TYPE_HEADER
#define INPUT_SYSTEM_TYPE_HEADER

#include "System.hpp"

#include "ComponentManager.hpp"
#include "EntityManager.hpp"

namespace tppo {
    class InputSystem : public System {
        
    protected:
        
        
    public:
        //
        InputSystem(ComponentManager &componentManager, EntityManager &entityManager);
        
        //
        ~InputSystem();
    
        //
        void Init();
    
        //
        void Update();
        
    };
}

#endif //INPUT_SYSTEM_TYPE_HEADER