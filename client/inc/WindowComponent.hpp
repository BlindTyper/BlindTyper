/*

*/

#ifndef WINDOW_COMPONENT_TYPE_HEADER
#define WINDOW_COMPONENT_TYPE_HEADER

#include "Main.hpp"

#include "Component.hpp"

#include <iostream>
#include <unordered_map>

namespace tppo {
    class WindowComponent : Component {

    protected:
        sf::RenderWindow window;
        
    public:
        //
        WindowComponent(uint64_t ownerId);
        
        //
        WindowComponent(
            uint64_t ownerId, 
            sf::VideoMode mode, 
            std::string title, 
            std::uint32_t style = sf::Style::Default,
            sf::State state = sf::State::Windowed
        );
        
    };
}

#endif //WINDOW_COMPONENT_TYPE_HEADER   
