/*

*/

#include "UIComponent.hpp"

namespace tppo {
    //
    UIComponent::UIComponent(
        std::uint64_t ownerId, 
        Type type, 
        std::string &text,
        std::function<std::string()> trackedData,
        std::uint64_t fontSize,
        Vec3d textColor, 
        bool isVisible, 
        std::function<void()> onClick
    ) 
        : Component(ownerId)
        , type(type)
        , text(text)
        , trackedData(trackedData)
        , fontSize(fontSize)
        , textColor(textColor)
        , isVisible(isVisible)
        , onClick(onClick)
    {
        
    }
    
    //
    UIComponent::UIComponent(
        std::uint64_t ownerId, 
        Type type, 
        std::string &&text,
        std::function<std::string()> trackedData,
        std::uint64_t fontSize,
        Vec3d textColor, 
        bool isVisible, 
        std::function<void()> onClick
    ) 
        : Component(ownerId)
        , type(type)
        , text(text)
        , trackedData(trackedData)
        , fontSize(fontSize)
        , textColor(textColor)
        , isVisible(isVisible)
        , onClick(onClick)
    {
        
    }
        
    //
    UIComponent::Type &UIComponent::GetType() {
        return type;
    }
        
    //
    std::string &UIComponent::GetText() {
        return text;
    }
        
    //
    void UIComponent::SetTrackedData(std::function<std::string()> trackedData) {
        this->trackedData = trackedData;
    }
        
    //
    std::function<std::string()> UIComponent::GetTrackedData() {
        return trackedData;
    }
        
    //
    std::uint64_t &UIComponent::GetFontSize() {
        return fontSize;
    }
        
    //
    Vec3d &UIComponent::GetTextColor() {
        return textColor;
    }
        
    //
    void UIComponent::Show() {
        isVisible = true;
    }
        
    //
    void UIComponent::Hide() {
        isVisible = false;
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