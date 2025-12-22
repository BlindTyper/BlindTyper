/*

*/

#include "HealthBar.hpp"

namespace tppo {
    //
    HealthBar::HealthBar(
        std::shared_ptr<UIComponent> &ui,
        std::shared_ptr<TransformComponent> &transform
    ) 
        : ui(ui)
        , transform(transform) {
    }
        
    //
    std::shared_ptr<UIComponent> &HealthBar::GetUI() {
        return ui;
    }
    
    //
    std::shared_ptr<TransformComponent> &HealthBar::GetTransform() {
        return transform;
    }
}