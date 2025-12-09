/*

*/

#ifndef VISUAL_COMPONENT_TYPE_HEADER
#define VISUAL_COMPONENT_TYPE_HEADER

#include "Main.hpp"

#include "Component.hpp"

namespace tppo {
    class VisualComponent : Component {

    protected:
        sf::Texture &texture;
        sf::Sprite sprite;
        
    public:
        //
        VisualComponent(uint64_t ownerId, sf::Texture &texture);
    };
}

#endif //VISUAL_COMPONENT_TYPE_HEADER   
