/*

*/

#ifndef MOVEMENT_COMPONENT_TYPE_HEADER
#define MOVEMENT_COMPONENT_TYPE_HEADER

#include "Component.hpp"

namespace tppo{
    class MovementComponent : Component {
    
    protected:
        Vec3d velocity;
        Vec3d acceleration;
        
    public:
        
    };
}

#endif //MOVEMENT_COMPONENT_TYPE_HEADER
