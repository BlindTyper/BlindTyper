/*

*/

#ifndef UI_COMPONENT_TYPE_HEADER
#define UI_COMPONENT_TYPE_HEADER

#include "Main.hpp"

#include "Component.hpp"

#include "Vec3d.hpp"

namespace tppo {
    class UIComponent : public Component {
        
    public:
        enum class Type {
            none = 0,
            label,
            button,
            progressBar,
            count
        };

    protected:
        //
        Type type;
    
        //
        std::string text;
        
        //
        std::function<std::string()> trackedData;
        
        //
        std::uint64_t fontSize;
        
        //
        Vec3d textColor;
        
        //
        bool isVisible;
        
        //
        std::function<void()> onClick;
        
    public:
        //
        UIComponent(
            std::uint64_t ownerId,
            Type type,
            std::string &text,
            std::function<std::string()> trackedData = nullptr,
            std::uint64_t fontSize = 16,
            Vec3d textColor = Vec3d(),
            bool isVisible = true,
            std::function<void()> onClick = [](){}
        );
        
        //
        UIComponent(
            std::uint64_t ownerId, 
            Type type,
            std::string &&text,
            std::function<std::string()> trackedData = nullptr,
            std::uint64_t fontSize = 16,
            Vec3d textColor = Vec3d(),
            bool isVisible = true,
            std::function<void()> onClick = [](){}
        );
        
        //
        UIComponent::Type &GetType();
        
        //
        std::string &GetText();
        
        //
        void SetTrackedData(std::function<std::string()> trackedData);
        
        //
        std::function<std::string()> GetTrackedData();
        
        //
        std::uint64_t &GetFontSize();
        
        //
        Vec3d &GetTextColor();
        
        //
        void Show();
        
        //
        void Hide();
        
        //
        bool &IsVisible();
        
        //
        std::function<void()> &GetOnClick();
    };
}

#endif //UI_COMPONENT_TYPE_HEADER   
