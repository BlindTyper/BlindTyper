/*

*/

#ifndef STATE_SYSTEM_TYPE_HEADER
#define STATE_SYSTEM_TYPE_HEADER

#include "System.hpp"

#include "ComponentManager.hpp"
#include "EntityManager.hpp"

namespace tppo {
    class StateSystem : public System {

    protected:
        
        
    public:
        //
        StateSystem(ComponentManager &componentManager, EntityManager &entityManager);
        
        //
        ~StateSystem();
    
        //
        void Init();
    
        //
        void Update();
    
        //
        void MainMenuInit();
    
        //
        void SoloGameMenuInit();
    
        //
        void MainMenuState();
    
        //
        void SoloGameMenuState();
        
    };
}

#endif //STATE_SYSTEM_TYPE_HEADER