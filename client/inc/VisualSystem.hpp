/*

*/

#ifndef VISUAL_SYSTEM_TYPE_HEADER
#define VISUAL_SYSTEM_TYPE_HEADER

#include "System.hpp"

#include <format>
#include <string>
#include <vector>

#include "ComponentManager.hpp"
#include "EntityManager.hpp"

namespace tppo {
    class VisualSystem : public System {
        
    protected:
        
        
    public:
        //
        VisualSystem(ComponentManager &componentManager, EntityManager &entityManager);
        
        //
        ~VisualSystem();
        
        //
        void Init();
        
        //
        void Update();
    };
}

#endif //VISUAL_SYSTEM_TYPE_HEADER