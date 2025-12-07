/*

*/

#ifndef TRANSFORM_COMPONENT_TYPE_HEADER
#define TRANSFORM_COMPONENT_TYPE_HEADER

#include "Vec3i.hpp"

#include "Component.hpp"

namespace tppo{
    class TransformComponent : Component {
        
    protected:
        Vec3i position;
        Vec3i size;
        Vec3i rotation;
        
    public:
        
    };
}

#endif //TRANSFORM_COMPONENT_TYPE_HEADER
