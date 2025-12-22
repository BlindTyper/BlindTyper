/*

*/

#include "DamageComponent.hpp"

namespace tppo {
    //
    DamageComponent::DamageComponent(
        std::uint64_t ownerId,
        std::uint64_t damage
    )
        : Component(ownerId)
        , damage(damage)
    {
        
    }
    
    //
    std::uint64_t DamageComponent::GetDamage() {
        return damage;
    }
}