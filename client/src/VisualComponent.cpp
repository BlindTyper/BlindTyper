/*

*/

#include <VisualComponent.hpp>

namespace tppo {
    //
    VisualComponent::VisualComponent(uint64_t ownerId, sf::Texture &texture) 
        : Component(ownerId)
        , texture(texture)
        , sprite(texture)
    {
        
    }
}