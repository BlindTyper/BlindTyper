//
// Created by anna_ on 07.12.2025.
//

#ifndef FLOOR_TYPE_HEADER
#define FLOOR_TYPE_HEADER

#include <memory>

#include "Entity.hpp"

#include "VisualComponent.hpp"
#include "TransformComponent.hpp"
#include "BodyComponent.hpp"
#include "HealthComponent.hpp"
#include "SoundComponent.hpp"

namespace tppo {
    class Floor : public Entity {
    
    protected:
        //
        std::shared_ptr<VisualComponent> visual;
        
        //
        std::shared_ptr<TransformComponent> transform;
        
        //
        std::shared_ptr<BodyComponent> body;
        
        //
        std::shared_ptr<HealthComponent> health;
        
        //
        std::shared_ptr<SoundComponent> sound;
        
    public:
        //
        Floor(
            std::shared_ptr<VisualComponent> &visual,
            std::shared_ptr<TransformComponent> &transform,
            std::shared_ptr<BodyComponent> &body,
            std::shared_ptr<HealthComponent> &health
        );
        
        //
        std::shared_ptr<VisualComponent> &GetVisual();
        
        //
        std::shared_ptr<TransformComponent> &GetTransform();
        
        //
        std::shared_ptr<BodyComponent> &GetBody();
        
        //
        std::shared_ptr<HealthComponent> &GetHealth();
        
    };
}
#endif //FLOOR_TYPE_HEADER
