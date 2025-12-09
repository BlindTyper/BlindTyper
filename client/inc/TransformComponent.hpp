/*

*/

#ifndef TRANSFORM_COMPONENT_TYPE_HEADER
#define TRANSFORM_COMPONENT_TYPE_HEADER

#include "Vec3d.hpp"

#include "Component.hpp"

namespace tppo{
    class TransformComponent : Component {
        
    protected:
        Vec3d position;
        Vec3d size;
        Vec3d rotation;
        
    public:
        
    };
}

#endif //TRANSFORM_COMPONENT_TYPE_HEADER
