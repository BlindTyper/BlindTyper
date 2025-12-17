/*

*/

#include "UIComponent.hpp"

namespace tppo {
    //
    UIComponent::UIComponent(uint64_t ownerId, std::string &text, Vec3d textColor, bool isVisible, std::function<void()> onClick) 
        : Component(ownerId)
        , text(text)
        , textColor(textColor)
        , isVisible(isVisible)
        , onClick(onClick)
    {
        
    }
    
    //
    UIComponent::UIComponent(uint64_t ownerId, std::string &&text, Vec3d textColor, bool isVisible, std::function<void()> onClick) 
        : Component(ownerId)
        , text(text)
        , textColor(textColor)
        , isVisible(isVisible)
        , onClick(onClick)
    {
        
    }
        
    //
    std::string &UIComponent::GetText() {
        return text;
    }
        
    //
    Vec3d &UIComponent::GetTextColor() {
        return textColor;
    }
        
    //
    bool &UIComponent::IsVisible() {
        return isVisible;
    }
    
    //
    std::function<void()> &UIComponent::GetOnClick() {
        return onClick;
    }
}