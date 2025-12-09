/*

*/

#include <WindowComponent.hpp>

namespace tppo {
    //
    WindowComponent::WindowComponent(uint64_t ownerId) 
        : Component(ownerId)
        , window()
    {
        
    }
    
    //
    WindowComponent::WindowComponent (
        uint64_t ownerId, 
        sf::VideoMode mode, 
        std::string title, 
        std::uint32_t style,
        sf::State state
    )
        : Component(ownerId)
        , window(mode, title, style, state)
    {
        
    }
}