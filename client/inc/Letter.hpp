//
// Created by anna_ on 07.12.2025.
//

#ifndef LETTER_TYPE_HEADER
#define LETTER_TYPE_HEADER

#include "Entity.hpp"

#include "VisualComponent.hpp"
#include "TransformComponent.hpp"
#include "BodyComponent.hpp"
#include "MovementComponent.hpp"
#include "LifetimeComponent.hpp"
#include "SoundComponent.hpp"

namespace tppo{
    class Letter{
        
    protected:
        VisualComponent visual;
        TransformComponent transform;
        BodyComponent body;
        MovementComponent movement;
        LifetimeComponent lifetime;
        SoundComponent sound;
        
    public:
        
    };
}
#endif //LETTER_TYPE_HEADER
