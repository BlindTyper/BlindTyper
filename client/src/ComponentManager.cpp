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
    std::shared_ptr<ApplicationSettingsComponent> &ComponentManager::GetApplicationSettingsComponent() {
        if (applicationSettingsComponent == nullptr) {
            applicationSettingsComponent = std::make_shared<ApplicationSettingsComponent>(Component::GetCounter());
        }
        return applicationSettingsComponent;
    }
        
    //
    std::shared_ptr<ApplicationStateComponent> &ComponentManager::AddApplicationStateComponent(std::uint64_t ownerId, std::string &stateName) {
        return (*applicationStatesComponents.try_emplace(stateName, std::make_shared<ApplicationStateComponent>(ownerId, stateName)).first).second;
    }
        
    //
    std::shared_ptr<ApplicationStateComponent> &ComponentManager::AddApplicationStateComponent(std::uint64_t ownerId, std::string &&stateName) {
        return (*applicationStatesComponents.try_emplace(stateName, std::make_shared<ApplicationStateComponent>(ownerId, stateName)).first).second;
    }
        
    //
    std::shared_ptr<ApplicationStateComponent> &ComponentManager::GetApplicationStateComponent(std::string stateName) {
        try {
            return applicationStatesComponents.at(stateName);
        }
        catch (std::out_of_range &e) {
            std::cerr << "Error:\nGetting from ComponentManager ApplicationStateComponent with stateName: " << stateName << std::endl;
            exit(1);
        }
    }
        
    //
    std::shared_ptr<WindowComponent> &ComponentManager::GetWindowComponent() {
        if (windowComponent == nullptr) {
            windowComponent = std::make_shared<WindowComponent>(Component::GetCounter());
        }
        return windowComponent;
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
    std::unordered_map<size_t, std::shared_ptr<UIComponent>> &ComponentManager::GetUIComponents() {
        return uiComponents;
    }
        
    //
    std::shared_ptr<UIComponent> &ComponentManager::AddUIComponent(
        std::uint64_t ownerId,
        std::string &text, 
        Vec3d textColor, 
        bool isVisible,
        std::function<void()> onClick
    ) {
        std::uint64_t id = Component::GetCounter();
        return (*uiComponents.try_emplace(id, std::make_shared<UIComponent>(ownerId, text, textColor, isVisible, onClick)).first).second;
    }
        
    //
    std::shared_ptr<UIComponent> &ComponentManager::AddUIComponent(
        std::uint64_t ownerId, 
        std::string &&text,
        Vec3d textColor, 
        bool isVisible,
        std::function<void()> onClick
    ) {
        std::uint64_t id = Component::GetCounter();
        return (*uiComponents.try_emplace(id, std::make_shared<UIComponent>(ownerId, text, textColor, isVisible, onClick)).first).second;
    }
        
    bool ComponentManager::HasUIComponent(std::uint64_t id) {
        try {
            uiComponents.at(id);
            return true;
        }
        catch (std::out_of_range &e) {
            return false;
        }
    }
        
    std::shared_ptr<UIComponent> &ComponentManager::GetUIComponent(std::uint64_t id) {
        try {
            return uiComponents.at(id);
        }
        catch (std::out_of_range &e) {
            std::cerr << "Error:\nGetting from ComponentManager UIComponent with id: " << id << std::endl;
            exit(1);
        }
    }
        
    //
    std::unordered_map<size_t, std::shared_ptr<VisualComponent>> &ComponentManager::GetVisualComponents() {
        return visualComponents;
    }
        
    //
    std::shared_ptr<VisualComponent> &ComponentManager::AddVisualComponent(std::uint64_t ownerId, sf::Texture &texture) {
        std::uint64_t id = Component::GetCounter();
        return (*visualComponents.try_emplace(id, std::make_shared<VisualComponent>(ownerId, texture)).first).second;
    }
        
    
    std::shared_ptr<VisualComponent> &ComponentManager::GetVisualComponent(std::uint64_t id) {
        try {
            return visualComponents.at(id);
        }
        catch (std::out_of_range &e) {
            std::cerr << "Error:\nGetting from ComponentManager VisualComponent with id: " << id << std::endl;
            exit(1);
        }
    }
        
    //
    std::unordered_map<size_t, std::shared_ptr<TransformComponent>> &ComponentManager::GetTransformComponents() {
        return transformComponents;
    }
        
    //
    std::shared_ptr<TransformComponent> &ComponentManager::AddTransformComponent(
        std::uint64_t ownerId,
        Vec3d pos,
        Vec3d size
    ) {
        std::uint64_t id = Component::GetCounter();
        return (*transformComponents.try_emplace(id, std::make_shared<TransformComponent>(ownerId, pos, size)).first).second;
    }
        
    
    std::shared_ptr<TransformComponent> &ComponentManager::GetTransformComponent(std::uint64_t id) {
        try {
            return transformComponents.at(id);
        }
        catch (std::out_of_range &e) {
            std::cerr << "Error:\nGetting from ComponentManager TransformComponent with id: " << id << std::endl;
            exit(1);
        }
    }
}