/*

*/

#include "Entity.hpp"

namespace tppo {
    //
    uint64_t Entity::counter = 0;
    
    //
    uint64_t Entity::UseCounter() {
        return counter++;
    }
    
    //
    uint64_t Entity::GetCounter() {
        return counter;
    }
    
    //
    Entity::Entity()
        : entityId(counter++)
    {
        
    }
}