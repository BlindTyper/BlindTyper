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
        WindowComponent(std::uint64_t ownerId);
        
        //
        WindowComponent(
            uint64_t ownerId, 
            sf::VideoMode mode, 
            std::string title, 
            std::uint32_t style = sf::Style::Default,
            sf::State state = sf::State::Windowed
        );
        
        //
        sf::RenderWindow &GetWindow();
        
        //
        void CreateWindow(
            sf::VideoMode &mode, 
            std::string &title, 
            std::uint32_t &style,
            sf::State &state
        );
        
        //
        void CreateWindow(
            sf::VideoMode &&mode, 
            std::string &&title, 
            std::uint32_t &&style = sf::Style::Default,
            sf::State &&state = sf::State::Windowed
        );
        
        //
        void SetFramerateLimit(std::uint32_t limit);
        
        //
        void SetVerticalSyncEnabled(bool enabled);
        
        //
        void Clear(sf::Color color = sf::Color::Black);
        
        //
        void Draw(const sf::Drawable &drawable, const sf::RenderStates &states = sf::RenderStates::Default);
        
        //
        void Display();
        
        //
        void Close();
        
    };
}

#endif //WINDOW_COMPONENT_TYPE_HEADER   
