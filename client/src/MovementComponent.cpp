/*

*/

#include "MovementComponent.hpp"

namespace tppo {
    //
    MovementComponent::MovementComponent(
        std::uint64_t ownerId,
        Vec3d velocity, 
        Vec3d acceleration
    )
        : Component(ownerId)
        , velocity(velocity)
        , acceleration(acceleration)
    {
        
    }
    
    //
    Vec3d &MovementComponent::GetVelocity() {
        return velocity;
    }
    
    //
    Vec3d &MovementComponent::GetAcceleration() {
        return acceleration;
    }
}