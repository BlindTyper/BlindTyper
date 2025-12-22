/*

*/

#ifndef TRANSFORM_COMPONENT_TYPE_HEADER
#define TRANSFORM_COMPONENT_TYPE_HEADER

#include "Vec3d.hpp"

#include "Component.hpp"

namespace tppo {
    class TransformComponent : public Component {
        
    protected:
        //
        Vec3d position;
        
        //
        Vec3d size;
        
        //
        Vec3d rotation;
        
    public:
        //
        TransformComponent(
            std::uint64_t ownerId,
            Vec3d position = Vec3d(), 
            Vec3d size = Vec3d(), 
            Vec3d rotation = Vec3d()
        );
        
        //
        Vec3d &GetPosition();
        
        //
        Vec3d &GetSize();
        
    };
}

#endif //TRANSFORM_COMPONENT_TYPE_HEADER
