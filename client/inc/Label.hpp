/*

*/

#ifndef LABEL_TYPE_HEADER
#define LABEL_TYPE_HEADER

#include <memory>

#include "Entity.hpp"

#include "UIComponent.hpp"
#include "TransformComponent.hpp"

namespace tppo {
    class Label : public Entity {
        
    protected:
        //
        std::shared_ptr<UIComponent> ui;
        
        //
        std::shared_ptr<TransformComponent> transform;
        
    public:
        //
        Label(
            std::shared_ptr<UIComponent> &ui,
            std::shared_ptr<TransformComponent> &transform
        );
        
        //
        std::shared_ptr<UIComponent> &GetUI();
        
        //
        std::shared_ptr<TransformComponent> &GetTransform();
        
        
    };
}
#endif //LABEL_TYPE_HEADER
