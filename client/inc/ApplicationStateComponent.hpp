/*

*/

#ifndef APPLICATION_STATE_COMPONENT_TYPE_HEADER
#define APPLICATION_STATE_COMPONENT_TYPE_HEADER

#include "Main.hpp"

#include <string>
#include <unordered_map>

#include "Component.hpp"

namespace tppo{
    class ApplicationStateComponent : public Component {
        
    protected:
        //
        std::string stateName;
        
        //
        bool isActive;
        
        //
        std::unordered_map<std::uint64_t, bool> stateEntitiesIds;
        
    public:
        //
        ApplicationStateComponent(std::uint64_t ownerId, std::string &stateName);
        
        //
        void LinkEntityToState(std::uint64_t entityId);
        
        //
        void UnlinkEntityFromState(std::uint64_t entityId);
        
        //
        std::unordered_map<std::uint64_t, bool> &GetEntitiesIds();
        
    };
}

#endif //APPLICATION_STATE_COMPONENT_TYPE_HEADER
