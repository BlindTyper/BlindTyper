/*

*/

#include "PlayerStatComponent.hpp"

namespace tppo {
    //
    PlayerStatComponent::PlayerStatComponent(
        std::uint64_t ownerId
    )
        : Component(ownerId)
        , totalLettersDestroyed(0)
        , lettersDestroyedPerMinute(0.0f)
        , timePassed(0)
    {
        
    }
    
    
    //
    std::uint64_t &PlayerStatComponent::GetTotalLettersDestroyed() {
        return totalLettersDestroyed;
    }
    
    //
    long double &PlayerStatComponent::GetLettersDestroyedPerMinute() {
        return lettersDestroyedPerMinute;
    }
    
    //
    std::uint64_t &PlayerStatComponent::GetTimePassed() {
        return timePassed;
    }
}