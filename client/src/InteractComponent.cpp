/*

*/

#include "InteractComponent.hpp"

namespace tppo {
    //
    InteractComponent::InteractComponent(uint64_t ownerId, std::function<void()> onClick) 
        : Component(ownerId)
        , onClick(onClick)
    {
        
    }
}