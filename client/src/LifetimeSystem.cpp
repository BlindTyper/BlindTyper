/*

*/

#include "LifetimeSystem.hpp"

namespace tppo {
    //
    LifetimeSystem::LifetimeSystem(ComponentManager &componentManager, EntityManager &entityManager)
        : System(componentManager, entityManager) {
        
    }
    
    //
    LifetimeSystem::~LifetimeSystem() {
        
    }
    
    //
    void LifetimeSystem::Init() {
        
    }
    
    //
    void LifetimeSystem::Update() {
        auto &gameModes = componentManager.GetGameModeComponents();
        for (auto &[it, gameMode] : gameModes) {
            if (!gameMode->IsActive()) {
                continue;
            }
            auto &respawnPeriodRange = gameMode->GetRespawnPeriodRange();
            std::int32_t lowerRange = respawnPeriodRange.first.asMilliseconds();
            std::int32_t upperRange = respawnPeriodRange.second.asMilliseconds();
            std::int32_t timePassed = gameMode->GetTimePassed().getElapsedTime().asMilliseconds();
            std::uint64_t leftRespawnBorder = static_cast<std::uint64_t>(gameMode->GetRespawnSpace().first * 100.f);
            std::uint64_t rightRespawnBorder = static_cast<std::uint64_t>(gameMode->GetRespawnSpace().second * 100.f);
            if (upperRange <= timePassed) {
                gameMode->GetTimePassed().restart();
                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<> dist(leftRespawnBorder, rightRespawnBorder);
                long double posX = static_cast<long double>(dist(gen)) / 100.d;
                long double posY = static_cast<long double>(dist(gen)) / 100.d;
                long double velY = static_cast<long double>(dist(gen)) / 500.d;
                std::uniform_int_distribution<> cdist('a', 'z');
                entityManager.AddLetter(
                    true,
                    Vec3d(posX, -0.07f),
                    Vec3d(0.0f, 0.0f),
                    Vec3d(0.04f, 0.07f),
                    Vec3d(0.0f, velY, 1.0f),
                    Vec3d(1.0f, 1.0f, 1.0f),
                    cdist(gen),
                    1
                );
            }
            
            break;
        }
    }
}