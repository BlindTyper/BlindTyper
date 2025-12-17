/*

*/

#include "EntityManager.hpp"

namespace tppo {
    //
    EntityManager::EntityManager(ComponentManager &componentManager)
        : componentManager(componentManager)
    {
        
    }
    
    //
    EntityManager::~EntityManager() {
        
    }
    
    //
    void EntityManager::Init() {
        
    }
        
    //
    std::shared_ptr<SystemResources> &EntityManager::GetSystemResources() {
        if (systemResources == nullptr) {
            systemResources = std::make_shared<SystemResources>(
                componentManager.GetApplicationSettingsComponent(),
                componentManager.GetWindowComponent(),
                componentManager.GetVisualResourcesComponent()
            );
        }
        return systemResources;
    }
        
    //
    std::shared_ptr<ApplicationStateComponent> &EntityManager::AddApplicationState(std::string &stateName) {
        std::uint64_t id = Entity::GetCounter();
        return componentManager.AddApplicationStateComponent(id, stateName);
    }
        
    //
    std::shared_ptr<ApplicationStateComponent> &EntityManager::AddApplicationState(std::string &&stateName) {
        std::uint64_t id = Entity::GetCounter();
        return componentManager.AddApplicationStateComponent(id, stateName);
    }
        
    //
    std::shared_ptr<ApplicationStates> &EntityManager::GetApplicationStates() {
        if (applicationStates == nullptr) {
            applicationStates = std::make_shared<ApplicationStates>();
        }
        return applicationStates;
    }
        
    //
    std::shared_ptr<Background> &EntityManager::AddBackground(std::string &textureName) {
        sf::Texture &texture = GetSystemResources()->GetVisualResources().GetTexture(textureName);
        std::uint64_t id = Entity::GetCounter();
        std::shared_ptr<VisualComponent> &visual = componentManager.AddVisualComponent(id, texture);
        std::shared_ptr<ApplicationSettingsComponent> &settings = componentManager.GetApplicationSettingsComponent();
        return (*backgrounds.try_emplace(id, std::make_shared<Background>(visual, settings)).first).second;
    }
        
    //
    std::shared_ptr<Background> &EntityManager::AddBackground(std::string &&textureName) {
        sf::Texture &texture = GetSystemResources()->GetVisualResources().GetTexture(textureName);
        std::uint64_t id = Entity::GetCounter();
        std::shared_ptr<VisualComponent> &visual = componentManager.AddVisualComponent(id, texture);
        std::shared_ptr<ApplicationSettingsComponent> &settings = componentManager.GetApplicationSettingsComponent();
        return (*backgrounds.try_emplace(id, std::make_shared<Background>(visual, settings)).first).second;
    }
        
    //
    std::unordered_map<std::uint64_t, std::shared_ptr<Background>> &EntityManager::GetBackgrounds() {
        return backgrounds;
    }
        
    //
    std::shared_ptr<Button> &EntityManager::AddButton(
        std::string &text, 
        Vec3d textColor,
        bool isVisible,
        std::function<void()> onClick,
        Vec3d pos,
        Vec3d size
    ) {
        std::uint64_t id = Entity::GetCounter();
        std::shared_ptr<UIComponent> &uiComponent = componentManager.AddUIComponent(id, text, textColor, isVisible, onClick);
        id = Entity::GetCounter();
        std::shared_ptr<TransformComponent> &transform = componentManager.AddTransformComponent(id, pos, size);
        return (*buttons.try_emplace(id, std::make_shared<Button>(uiComponent, transform)).first).second;
    }
        
    //
    std::shared_ptr<Button> &EntityManager::AddButton(
        std::string &&text, 
        Vec3d textColor, 
        bool isVisible,
        std::function<void()> onClick,
        Vec3d pos,
        Vec3d size
    ) {
        std::uint64_t id = Entity::GetCounter();
        std::shared_ptr<UIComponent> &uiComponent = componentManager.AddUIComponent(id, text, textColor, isVisible, onClick);
        id = Entity::GetCounter();
        std::shared_ptr<TransformComponent> &transform = componentManager.AddTransformComponent(id, pos, size);
        return (*buttons.try_emplace(id, std::make_shared<Button>(uiComponent, transform)).first).second;
    }
        
    //
    bool EntityManager::HasButton(std::uint64_t id) {
        try {
            buttons.at(id);
            return true;
        }
        catch (std::out_of_range &e) {
            return false;
        }
    }
        
    //
    std::shared_ptr<Button> &EntityManager::GetButton(std::uint64_t id) {
        try {
            return buttons.at(id);
        }
        catch (std::out_of_range &e) {
            std::cerr << "Error:\nGetting from EntityManager Button with id: " << id << std::endl;
            exit(1);
        }
    }
        
    //
    std::unordered_map<std::uint64_t, std::shared_ptr<Button>> &EntityManager::GetButtons() {
        return buttons;
    }
        
    //
    std::shared_ptr<Label> &EntityManager::AddLabel(
        std::string &text, 
        Vec3d textColor,
        bool isVisible,
        std::function<void()> onClick,
        Vec3d pos,
        Vec3d size
    ) {
        std::uint64_t id = Entity::GetCounter();
        std::shared_ptr<UIComponent> &uiComponent = componentManager.AddUIComponent(id, text, textColor, isVisible, onClick);
        id = Entity::GetCounter();
        std::shared_ptr<TransformComponent> &transform = componentManager.AddTransformComponent(id, pos, size);
        return (*labels.try_emplace(id, std::make_shared<Label>(uiComponent, transform)).first).second;
    }
        
    //
    std::shared_ptr<Label> &EntityManager::AddLabel(
        std::string &&text, 
        Vec3d textColor, 
        bool isVisible,
        std::function<void()> onClick,
        Vec3d pos,
        Vec3d size
    ) {
        std::uint64_t id = Entity::GetCounter();
        std::shared_ptr<UIComponent> &uiComponent = componentManager.AddUIComponent(id, text, textColor, isVisible, onClick);
        id = Entity::GetCounter();
        std::shared_ptr<TransformComponent> &transform = componentManager.AddTransformComponent(id, pos, size);
        return (*labels.try_emplace(id, std::make_shared<Label>(uiComponent, transform)).first).second;
    }
        
    //
    bool EntityManager::HasLabel(std::uint64_t id) {
        try {
            labels.at(id);
            return true;
        }
        catch (std::out_of_range &e) {
            return false;
        }
    }
        
    //
    std::shared_ptr<Label> &EntityManager::GetLabel(std::uint64_t id) {
        try {
            return labels.at(id);
        }
        catch (std::out_of_range &e) {
            std::cerr << "Error:\nGetting from EntityManager Button with id: " << id << std::endl;
            exit(1);
        }
    }
    
    //
    void EntityManager::HideUI() {
        auto uis = componentManager.GetUIComponents();
        for (auto &it : uis) {
            it.second->IsVisible() = false;
        }
    }
        
    //
    std::unordered_map<std::uint64_t, std::shared_ptr<Label>> &EntityManager::GetLabels() {
        return labels;
    }
}