/*

*/

#include "Button.hpp"

namespace tppo {
    //
    Button::Button(
        std::shared_ptr<UIComponent> &ui,
        std::shared_ptr<TransformComponent> &transform
    ) 
        : ui(ui)
        , transform(transform) {
    }
        
    //
    std::shared_ptr<UIComponent> &Button::GetUI() {
        return ui;
    }
    
    //
    std::shared_ptr<TransformComponent> &Button::GetTransform() {
        return transform;
    }
}