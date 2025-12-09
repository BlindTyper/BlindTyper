/*

*/

#include "SystemResources.hpp"

namespace tppo {
    //
    SystemResources::SystemResources(std::shared_ptr<VisualResourcesComponent> &visualResources) 
        : visualResources(visualResources) {
        
    }
        
    //
    VisualResourcesComponent &SystemResources::GetVisualResources() {
        return *visualResources;
    }
}