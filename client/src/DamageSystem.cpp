/*

*/

#include "DamageSystem.hpp"

namespace tppo {
    //
    DamageSystem::DamageSystem(ComponentManager &componentManager, EntityManager &entityManager)
        : System(componentManager, entityManager) {
        
    }
    
    //
    DamageSystem::~DamageSystem() {
        
    }
    
    //
    void DamageSystem::Init() {
        
    }
    
    //
    void DamageSystem::Update() {
        auto &gameModes = componentManager.GetGameModeComponents();
        for (auto it : gameModes) {
            auto &gameMode = it.second;
            if (!gameMode->IsActive()) {
                continue;
            }
            auto &bodies = componentManager.GetBodyComponents();
            for (auto &[key0, body0] : bodies) {
                if (!componentManager.HasTransformComponent(key0)) {
                    continue;
                }
                if (!componentManager.HasHealthComponent(key0)) {
                    continue;
                }
                auto &transform0 = componentManager.GetTransformComponent(key0);
                for (auto &[key1, body1] : bodies) {
                    if (!componentManager.HasTransformComponent(key1)) {
                        continue;
                    }
                    if (!componentManager.HasDamageComponent(key1)) {
                        continue;
                    }
                    auto &transform1 = componentManager.GetTransformComponent(key1);
                    auto lx0 = transform0->GetPosition().x;
                    auto rx0 = lx0 + body0->GetSize().x;
                    auto ly0 = transform0->GetPosition().y;
                    auto ry0 = ly0 + body0->GetSize().y;
                    auto lx1 = transform1->GetPosition().x;
                    auto rx1 = lx1 + body1->GetSize().x;
                    auto ly1 = transform1->GetPosition().y;
                    auto ry1 = ly1 + body1->GetSize().y;
                    if ((lx0 < lx1 && rx0 < lx1) ||
                        (rx1 < lx0 && rx1 < rx0) ||
                        (ly0 < ly1 && ry0 < ly1) ||
                        (ry1 < ly0 && ry1 < ry0)) {
                        continue;
                    }
                    auto &health = componentManager.GetHealthComponent(key0);
                    auto &damage = componentManager.GetDamageComponent(key1);
                    health->GetCurrentHealth() -= damage->GetDamage();
                    entityManager.RemoveLetter(key1);
                    if (health->GetCurrentHealth() <= 0ull) {
                        auto &gameModes = componentManager.GetGameModeComponents();
                        for (auto &[key, gameMode] : gameModes) {
                            gameMode->CallResultState();
                            return;
                        }
                    }
                    break;
                }
            }
            
            break;
        }
    }
}