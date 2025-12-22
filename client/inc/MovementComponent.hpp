/*

*/

#ifndef MOVEMENT_COMPONENT_TYPE_HEADER
#define MOVEMENT_COMPONENT_TYPE_HEADER

#include "Vec3d.hpp"

#include "Component.hpp"

namespace tppo {
    class MovementComponent : public Component {
    
    protected:
        //
        Vec3d velocity;
        
        //
        Vec3d acceleration;
        
    public:
        //
        MovementComponent(
            std::uint64_t ownerId,
            Vec3d velocity = Vec3d(), 
            Vec3d acceleration = Vec3d()
        );
        
        //
        Vec3d &GetVelocity();
        
        //
        Vec3d &GetAcceleration();
        
    };
}

#endif //MOVEMENT_COMPONENT_TYPE_HEADER
