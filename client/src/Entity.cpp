/*

*/

#include "Entity.hpp"

namespace tppo {
    //
    std::uint64_t Entity::counter = 0;
    
    //
    std::uint64_t Entity::UseCounter() {
        return counter++;
    }
    
    //
    std::uint64_t Entity::GetCounter() {
        return counter;
    }
    
    //
    Entity::Entity()
        : entityId(counter++)
    {
        
    }
}