/*

*/

#include "SystemResources.hpp"

namespace tppo {
    //
    SystemResources::SystemResources(
        std::shared_ptr<ApplicationSettingsComponent> &settings,
        std::shared_ptr<WindowComponent> &window,
        std::shared_ptr<VisualResourcesComponent> &visualResources
    ) 
        : settings(settings) 
        , window(window) 
        , visualResources(visualResources) {
        
    }
        
    //
    ApplicationSettingsComponent &SystemResources::GetSettings() {
        return *settings;
    }
        
    //
    WindowComponent &SystemResources::GetWindow() {
        return *window;
    }
        
    //
    VisualResourcesComponent &SystemResources::GetVisualResources() {
        return *visualResources;
    }
}