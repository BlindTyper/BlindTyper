/*

*/

#ifndef SYSTEM_MANAGER_TYPE_HEADER
#define SYSTEM_MANAGER_TYPE_HEADER

#include "Main.hpp"

#include "Manager.hpp"
#include "InputSystem.hpp"
#include "VisualSystem.hpp"
//#include "HealthSystem.hpp"
#include "MovementSystem.hpp"
#include "LifetimeSystem.hpp"
#include "CollisionSystem.hpp"
#include "AudioSystem.hpp"

namespace tppo{
    class SystemManager : Manager {
        
    protected:
        //
        InputSystem inputSystem;
        
        //
        VisualSystem visualSystem;
        
        //
        //HealthSystem healthSystem;
        
        //
        MovementSystem movementSystem;
        
        //
        LifetimeSystem lifetimeSystem;
        
        //
        CollisionSystem collisionSystem;
        
        //
        AudioSystem audioSystem;
        
    public:
        SystemManager() {}
        ~SystemManager() {}
        
    };
}
#endif //SYSTEM_MANAGER_TYPE_HEADER
