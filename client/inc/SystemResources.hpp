/*

*/

#ifndef SYSTEM_RESOURCES_TYPE_HEADER
#define SYSTEM_RESOURCES_TYPE_HEADER

#include <memory>

#include "Entity.hpp"

#include "ApplicationSettingsComponent.hpp"
#include "WindowComponent.hpp"
#include "VisualResourcesComponent.hpp"

namespace tppo {
    class SystemResources : Entity {
        
    protected:
        //
        std::shared_ptr<ApplicationSettingsComponent> settings;
        
        //
        std::shared_ptr<WindowComponent> window;
    
        //
        std::shared_ptr<VisualResourcesComponent> visualResources;
        
    public:
        //
        SystemResources(
            std::shared_ptr<ApplicationSettingsComponent> &settings,
            std::shared_ptr<WindowComponent> &window,
            std::shared_ptr<VisualResourcesComponent> &visualResources
        );
        
        //
        ApplicationSettingsComponent &GetSettings();
        
        //
        WindowComponent &GetWindow();
        
        //
        VisualResourcesComponent &GetVisualResources();
        
    };
}
#endif //SYSTEM_RESOURCES_TYPE_HEADER
