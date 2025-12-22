/*

*/

#include "UIComponent.hpp"

namespace tppo {
    //
    UIComponent::UIComponent(
        std::uint64_t ownerId, 
        Type type, 
        std::string &text,
        void *trackedData1,
        void *trackedData2,
        Vec3d textColor, 
        bool isVisible, 
        std::function<void()> onClick
    ) 
        : Component(ownerId)
        , type(type)
        , text(text)
        , trackedData1(trackedData1)
        , trackedData2(trackedData2)
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
        void *trackedData1,
        void *trackedData2,
        Vec3d textColor, 
        bool isVisible, 
        std::function<void()> onClick
    ) 
        : Component(ownerId)
        , type(type)
        , text(text)
        , trackedData1(trackedData1)
        , trackedData2(trackedData2)
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
    void UIComponent::SetTrackedData1(void *trackedData) {
        this->trackedData1 = trackedData;
    }
        
    //
    void *UIComponent::GetTrackedData1() {
        return trackedData1;
    }
        
    //
    void UIComponent::SetTrackedData2(void *trackedData) {
        this->trackedData2 = trackedData;
    }
        
    //
    void *UIComponent::GetTrackedData2() {
        return trackedData2;
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