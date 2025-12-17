/*

*/

#ifndef UI_COMPONENT_TYPE_HEADER
#define UI_COMPONENT_TYPE_HEADER

#include "Main.hpp"

#include "Component.hpp"

#include "Vec3d.hpp"

namespace tppo {
    class UIComponent : public Component {

    protected:
        //
        std::string text;
        
        //
        Vec3d textColor;
        
        //
        bool isVisible;
        
        //
        std::function<void()> onClick;
        
    public:
        //
        UIComponent(
            uint64_t ownerId, 
            std::string &text, 
            Vec3d textColor = Vec3d(),
            bool isVisible = true,
            std::function<void()> onClick = [](){}
        );
        
        //
        UIComponent(
            uint64_t ownerId, 
            std::string &&text, 
            Vec3d textColor = Vec3d(),
            bool isVisible = true,
            std::function<void()> onClick = [](){}
        );
        
        //
        std::string &GetText();
        
        //
        Vec3d &GetTextColor();
        
        //
        bool &IsVisible();
        
        //
        std::function<void()> &GetOnClick();
    };
}

#endif //UI_COMPONENT_TYPE_HEADER   
