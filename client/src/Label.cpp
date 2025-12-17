/*

*/

#include "Label.hpp"

namespace tppo {
    //
    Label::Label(
        std::shared_ptr<UIComponent> &ui,
        std::shared_ptr<TransformComponent> &transform
    ) 
        : ui(ui)
        , transform(transform) {
    }
        
    //
    std::shared_ptr<UIComponent> &Label::GetUI() {
        return ui;
    }
    
    //
    std::shared_ptr<TransformComponent> &Label::GetTransform() {
        return transform;
    }
}