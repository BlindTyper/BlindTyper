/*

*/

#ifndef COMPONENT_MANAGER_TYPE_HEADER
#define COMPONENT_MANAGER_TYPE_HEADER

#include "Main.hpp"

#include <unordered_map>

#include "Manager.hpp"

#include "VisualComponent.hpp"
#include "TransformComponent.hpp"
#include "BodyComponent.hpp"
#include "HealthComponent.hpp"
#include "LifetimeComponent.hpp"
#include "SoundComponent.hpp"
#include "MovementComponent.hpp"
#include "LetterComponent.hpp"

namespace tppo{
    class ComponentManager : Manager {
        
    protected:
        //
        std::unordered_map<size_t, TransformComponent> transformComponents;
        
        //
        std::unordered_map<size_t, VisualComponent> visualComponents;
        
        //
        std::unordered_map<size_t, BodyComponent> bodyComponents;
        
        //
        std::unordered_map<size_t, SoundComponent> soundComponents;
        
        //
        std::unordered_map<size_t, LifetimeComponent> lifetimeComponents;
        
        //
        std::unordered_map<size_t, HealthComponent> healthComponents;
        
        //
        std::unordered_map<size_t, MovementComponent> movementComponents;
        
        //
        std::unordered_map<size_t, LetterComponent> letterComponents;
        
    public:
        ComponentManager() {}
        ~ComponentManager() {}
        
    };
}
#endif //COMPONENT_MANAGER_TYPE_HEADER
