/*

*/

#include "BodyComponent.hpp"

namespace tppo {
    //
    BodyComponent::BodyComponent(
        std::uint64_t ownerId,
        Vec3d size
    )
        : Component(ownerId)
        , size(size)
    {
        
    }
    
    //
    Vec3d &BodyComponent::GetSize() {
        return size;
    }
}