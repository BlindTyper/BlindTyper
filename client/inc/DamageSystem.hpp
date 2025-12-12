/*

*/

#ifndef DAMAGE_SYSTEM_TYPE_HEADER
#define DAMAGE_SYSTEM_TYPE_HEADER

#include "System.hpp"

namespace tppo {
    class DamageSystem : System {
        
    protected:
        
        
    public:
        //
        DamageSystem(ComponentManager &componentManager, EntityManager &entityManager);
        
        //
        ~DamageSystem();
    
        //
        void Init();
    
        //
        void Update();
        
    };
}

#endif //DAMAGE_SYSTEM_TYPE_HEADER