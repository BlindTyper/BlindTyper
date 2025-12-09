/*

*/

#include <Component.hpp>

namespace tppo {
    //
    uint64_t Component::counter = 0;
    
    //
    uint64_t Component::UseCounter() {
        return counter++;
    }
    
    //
    uint64_t Component::GetCounter() {
        return counter;
    }
    
    //
    Component::Component(uint64_t ownerId)
        : componentId(counter++)
        , ownerId(ownerId)
    {
        
    }
}