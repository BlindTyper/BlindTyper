/*

*/

#ifndef SYSTEM_RESOURCES_TYPE_HEADER
#define SYSTEM_RESOURCES_TYPE_HEADER

#include <memory>

#include "Entity.hpp"

#include "VisualResourcesComponent.hpp"

namespace tppo {
    class SystemResources : Entity {
        
    protected:
        std::shared_ptr<VisualResourcesComponent> visualResources;
        
    public:
        //
        SystemResources(std::shared_ptr<VisualResourcesComponent> &visualResources);
        
        //
        VisualResourcesComponent &GetVisualResources();
        
    };
}
#endif //SYSTEM_RESOURCES_TYPE_HEADER
