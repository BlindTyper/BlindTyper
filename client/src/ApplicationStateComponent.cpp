/*

*/

#include "ApplicationStateComponent.hpp"

namespace tppo {
    //
    ApplicationStateComponent::ApplicationStateComponent(uint64_t ownerId, std::string &stateName) 
        : Component(ownerId)
        , stateName(stateName)
        , isActive(false)
        , stateEntitiesIds()
    {
        
    }
        
    //
    void ApplicationStateComponent::LinkEntityToState(std::uint64_t entityId) {
        stateEntitiesIds.try_emplace(entityId, true);
    }
    
    //
    void ApplicationStateComponent::UnlinkEntityFromState(std::uint64_t entityId) {
        
    }
    
    //
    std::unordered_map<std::uint64_t, bool> &ApplicationStateComponent::GetEntitiesIds() {
        return stateEntitiesIds;
    }
}