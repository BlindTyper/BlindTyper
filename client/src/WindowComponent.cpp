/*

*/

#include "WindowComponent.hpp"

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
    
    //
    sf::RenderWindow &WindowComponent::GetWindow() {
        return window;
    }
        
    //
    void WindowComponent::CreateWindow(
        sf::VideoMode &mode, 
        std::string &title, 
        std::uint32_t &style,
        sf::State &state
    ) {
        window.create(mode, title, style, state);
    }
        
    //
    void WindowComponent::CreateWindow(
        sf::VideoMode &&mode, 
        std::string &&title, 
        std::uint32_t &&style,
        sf::State &&state
    ) {
        window.create(mode, title, style, state);
    }
        
    //
    void WindowComponent::SetFramerateLimit(std::uint32_t limit) {
        window.setFramerateLimit(limit);
    }
        
    //
    void WindowComponent::SetVerticalSyncEnabled(bool enabled) {
        window.setVerticalSyncEnabled(enabled);
    }
        
    //
    void WindowComponent::Clear(sf::Color color) {
        window.clear(color);
    }
        
    //
    void WindowComponent::Draw(const sf::Drawable &drawable, const sf::RenderStates &states) {
        window.draw(drawable, states);
    }
        
    //
    void WindowComponent::Display() {
        window.display();
    }
        
    //
    void WindowComponent::Close() {
        window.close();
    }
}