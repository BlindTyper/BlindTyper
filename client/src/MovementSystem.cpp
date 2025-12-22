/*

*/

#include "MovementSystem.hpp"

namespace tppo {
    //
    MovementSystem::MovementSystem(ComponentManager &componentManager, EntityManager &entityManager)
        : System(componentManager, entityManager) {
        
    }
    
    //
    MovementSystem::~MovementSystem() {
        
    }
    
    //
    void MovementSystem::Init() {
        
    }
    
    //
    void MovementSystem::Update() {
        auto &gameModes = componentManager.GetGameModeComponents();
        for (auto &[it, gameMode] : gameModes) {
            if (!gameMode->IsActive()) {
                continue;
            }
            
            auto &movements = componentManager.GetMovementComponents();
            for (auto &[key, movement] : movements) {
                auto time = componentManager.GetWindowComponent()->GetClock().getElapsedTime();
                auto &transform = componentManager.GetTransformComponent(key);
                transform->GetPosition().x += movement->GetVelocity().x * time.asSeconds();
                transform->GetPosition().y += movement->GetVelocity().y * time.asSeconds();
            }
            
            break;
        }
        
    }
}