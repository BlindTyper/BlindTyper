/*

*/

#ifndef HEALTH_BAR_TYPE_HEADER
#define HEALTH_BAR_TYPE_HEADER

#include <memory>

#include "Entity.hpp"

#include "UIComponent.hpp"
#include "TransformComponent.hpp"

namespace tppo {
    class HealthBar : public Entity {
        
    protected:
        //
        std::shared_ptr<UIComponent> ui;
        
        //
        std::shared_ptr<TransformComponent> transform;
        
    public:
        //
        HealthBar(
            std::shared_ptr<UIComponent> &ui,
            std::shared_ptr<TransformComponent> &transform
        );
        
        //
        std::shared_ptr<UIComponent> &GetUI();
        
        //
        std::shared_ptr<TransformComponent> &GetTransform();
        
        
    };
}
#endif //HEALTH_BAR_TYPE_HEADER
