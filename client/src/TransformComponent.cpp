/*

*/

#include "TransformComponent.hpp"

namespace tppo {
    //
    TransformComponent::TransformComponent(
        std::uint64_t ownerId,
        Vec3d position, 
        Vec3d size, 
        Vec3d rotation
    )
        : Component(ownerId)
        , position(position)
        , size(size)
        , rotation(rotation)
    {
        
    }
    
    //
    Vec3d &TransformComponent::GetPosition() {
        return position;
    }
    
    //
    Vec3d &TransformComponent::GetSize() {
        return size;
    }
}