/*

*/

#include <ComponentManager.hpp>

namespace tppo {
    //
    ComponentManager::ComponentManager() {
        
    }
    
    //
    ComponentManager::~ComponentManager() {
        
    }
    
    //
    void ComponentManager::Init() {
        
    }
        
    //
    std::shared_ptr<VisualResourcesComponent> &ComponentManager::GetVisualResourcesComponent() {
        //return &(*visualResourcesComponents.emplace(Component::GetCounter(), VisualResourcesComponent(ownerId)).first).second;
        if (visualResourcesComponent == nullptr) {
            visualResourcesComponent = std::make_shared<VisualResourcesComponent>(Component::GetCounter());
            //std::cout << "systemResources == nullptr" << std::endl;
        }
        return visualResourcesComponent;
    }
        
    //
    std::unordered_map<size_t, VisualComponent> &ComponentManager::GetVisualComponents() {
        return visualComponents;
    }
        
    //
    VisualComponent &ComponentManager::GetVisualComponent(uint64_t id) {
        try {
            return visualComponents.at(id);
        }
        catch (std::out_of_range &e) {
            std::cerr << "Error:\nGetting from ComponentManager VisualComponent with id: " << id << std::endl;
            exit(1);
        }
    }
}