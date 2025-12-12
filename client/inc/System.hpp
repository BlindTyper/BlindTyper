/*

*/

#ifndef SYSTEM_TYPE_HEADER
#define SYSTEM_TYPE_HEADER

#include <ComponentManager.hpp>
#include <EntityManager.hpp>

namespace tppo {
    class System {
        
    protected:
        //
        ComponentManager &componentManager;
        
        //
        EntityManager &entityManager;
        
        
    public:
        //
        System() = delete;
        
        //
        System(ComponentManager &componentManager, EntityManager &entityManager);
    
        //
        virtual void Init() = 0;
    
        //
        virtual void Update() = 0;
    };
}

#endif //SYSTEM_TYPE_HEADER