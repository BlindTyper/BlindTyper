/*

*/

#include "VisualComponent.hpp"

namespace tppo {
    //
    VisualComponent::VisualComponent(
        uint64_t ownerId, 
        sf::Texture &texture,
        bool isVisible 
    ) 
        : Component(ownerId)
        , texture(texture)
        , sprite(texture)
        , isVisible(isVisible)
    {
        
    }
        
    //
    sf::Texture &VisualComponent::GetTexture() {
        return texture;
    }
        
    //
    sf::Sprite &VisualComponent::GetSprite() {
        return sprite;
    }
        
    //
    void VisualComponent::Show() {
        isVisible = true;
    }
        
    //
    void VisualComponent::Hide() {
        isVisible = false;
    }
        
    //
    bool &VisualComponent::IsVisible() {
        return isVisible;
    }
}