/*

*/

#ifndef SYSTEM_MANAGER_TYPE_HEADER
#define SYSTEM_MANAGER_TYPE_HEADER

#include "Main.hpp"

#include "Manager.hpp"
#include "InputSystem.hpp"
#include "VisualSystem.hpp"
#include "DamageSystem.hpp"
#include "MovementSystem.hpp"
#include "LifetimeSystem.hpp"
#include "CollisionSystem.hpp"
#include "AudioSystem.hpp"

namespace tppo{
    class SystemManager : Manager {
        
    protected:
        //
        bool isRunning;
        
        //
        ComponentManager &componentManager;
        
        //
        EntityManager &entityManager;
        
        //
        InputSystem inputSystem;
        
        //
        VisualSystem visualSystem;
        
        //
        DamageSystem damageSystem;
        
        //
        MovementSystem movementSystem;
        
        //
        LifetimeSystem lifetimeSystem;
        
        //
        CollisionSystem collisionSystem;
        
        //
        AudioSystem audioSystem;
        
    public:
        //
        SystemManager(ComponentManager &componentManager, EntityManager &entityManager);
        
        //
        ~SystemManager();
        
        //
        bool IsRunning();
        
        //
        void Init();
        
        //
        void Update();
        
    };
}
#endif //SYSTEM_MANAGER_TYPE_HEADER
