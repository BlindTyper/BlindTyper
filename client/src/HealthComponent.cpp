/*

*/

#include "HealthComponent.hpp"

namespace tppo {
    //
    HealthComponent::HealthComponent(
        std::uint64_t ownerId,
        std::uint64_t currentHealth,
        std::uint64_t maxHealth
    )
        : Component(ownerId)
        , currentHealth(currentHealth)
        , maxHealth(maxHealth)
    {
        
    }
    
    //
    std::uint64_t &HealthComponent::GetCurrentHealth() {
        return currentHealth;
    }
    
    //
    std::uint64_t &HealthComponent::GetMaxHealth() {
        return maxHealth;
    }
}