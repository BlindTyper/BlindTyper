/*

*/

#ifndef LIFETIME_COMPONENT_TYPE_HEADER
#define LIFETIME_COMPONENT_TYPE_HEADER

#include "Component.hpp"

namespace tppo{
    class LifetimeComponent : Component {
        
    protected:
        bool isAlive;
        time_t creationTime;
        time_t texpirationTime;
        
    public:
        
    };
}

#endif //LIFETIME_COMPONENT_TYPE_HEADER
