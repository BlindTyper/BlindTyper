/*

*/

#ifndef VISUAL_COMPONENT_TYPE_HEADER
#define VISUAL_COMPONENT_TYPE_HEADER

#include "Vec3i.hpp"

#include "Component.hpp"

namespace tppo{
    class VisualComponent : Component {

    protected:
        sf::Texture &texture;
        sf::Sprite sprite;
        
    public:
        
    };
}

#endif //VISUAL_COMPONENT_TYPE_HEADER
