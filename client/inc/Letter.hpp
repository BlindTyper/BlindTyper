//
// Created by anna_ on 07.12.2025.
//

#ifndef LETTER_TYPE_HEADER
#define LETTER_TYPE_HEADER

#include <memory>

#include "Entity.hpp"

#include "VisualComponent.hpp"
#include "TransformComponent.hpp"
#include "BodyComponent.hpp"
#include "MovementComponent.hpp"
#include "LifetimeComponent.hpp"
#include "SoundComponent.hpp"

namespace tppo{
    class Letter : Entity {
        
    protected:
        //
        std::shared_ptr<VisualComponent> visual;
        
        //
        std::shared_ptr<TransformComponent> transform;
        
        //
        std::shared_ptr<BodyComponent> body;
        
        //
        std::shared_ptr<MovementComponent> movement;
        
        //
        std::shared_ptr<LifetimeComponent> lifetime;
        
        //
        std::shared_ptr<SoundComponent> sound;
        
    public:
        
    };
}
#endif //LETTER_TYPE_HEADER
