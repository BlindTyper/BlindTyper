//
// Created by anna_ on 07.12.2025.
//

#ifndef FLOOR_TYPE_HEADER
#define FLOOR_TYPE_HEADER

#include "Entity.hpp"

#include "VisualComponent.hpp"
#include "TransformComponent.hpp"
#include "BodyComponent.hpp"
#include "HealthComponent.hpp"
#include "LifetimeComponent.hpp"
#include "SoundComponent.hpp"

namespace tppo{
    class Floor{
    
    protected:
        VisualComponent visual;
        TransformComponent transform;
        BodyComponent body;
        HealthComponent movement;
        LifetimeComponent lifetime;
        SoundComponent sound;
        
    public:
        
    };
}
#endif //FLOOR_TYPE_HEADER
