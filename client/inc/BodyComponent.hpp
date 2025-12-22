/*

*/

#ifndef BODY_COMPONENT_TYPE_HEADER
#define BODY_COMPONENT_TYPE_HEADER

#include "Vec3d.hpp"

#include "Component.hpp"

namespace tppo {
    class BodyComponent : public Component {
        
    protected:
        //
        Vec3d size;
        
    public:
        //
        BodyComponent(
            std::uint64_t ownerId,
            Vec3d size
        );
        
        Vec3d &GetSize();
        
    };
}
#endif //BODY_COMPONENT_TYPE_HEADER
