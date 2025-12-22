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
    std::shared_ptr<GameModeComponent> &ComponentManager::AddGameModeComponent(
        std::uint64_t ownerId,
        bool isActive,
        std::function<void()> resultState,
        std::pair<long double, long double> &respawnSpace,
        std::pair<sf::Time, sf::Time> &respawnPeriodRange,
        std::uint64_t defaultLetterDamage
    ) {
        return (*gameModeComponents.try_emplace(ownerId, std::make_shared<GameModeComponent>(
            ownerId, isActive, resultState, respawnSpace, respawnPeriodRange, defaultLetterDamage)).first).second;
    }
        
    //
    std::shared_ptr<GameModeComponent> &ComponentManager::AddGameModeComponent(
        std::uint64_t ownerId,
        bool isActive,
        std::function<void()> resultState,
        std::pair<long double, long double> &&respawnSpace,
        std::pair<sf::Time, sf::Time> &&respawnPeriodRange,
        std::uint64_t defaultLetterDamage
    ) {
        return (*gameModeComponents.try_emplace(ownerId, std::make_shared<GameModeComponent>(
            ownerId, isActive, resultState, respawnSpace, respawnPeriodRange, defaultLetterDamage)).first).second;
    }
        
    bool ComponentManager::HasGameModeComponent(std::uint64_t id) {
        try {
            gameModeComponents.at(id);
            return true;
        }
        catch (std::out_of_range &e) {
            return false;
        }
    }
        
    std::shared_ptr<GameModeComponent> &ComponentManager::GetGameModeComponent(std::uint64_t id) {
        try {
            return gameModeComponents.at(id);
        }
        catch (std::out_of_range &e) {
            std::cerr << "Error:\nGetting from ComponentManager GameModeComponent with id: " << id << std::endl;
            exit(1);
        }
    }
        
    //
    std::unordered_map<size_t, std::shared_ptr<GameModeComponent>> &ComponentManager::GetGameModeComponents() {
        return gameModeComponents;
    }
        
    //
    std::shared_ptr<UIComponent> &ComponentManager::AddUIComponent(
        std::uint64_t ownerId,
        UIComponent::Type type,
        std::string &text, 
        void *trackedData1,
        void *trackedData2,
        Vec3d textColor, 
        bool isVisible,
        std::function<void()> onClick
    ) {
        return (*uiComponents.try_emplace(ownerId, std::make_shared<UIComponent>(ownerId, type, text, trackedData1, trackedData2, textColor, isVisible, onClick)).first).second;
    }
        
    //
    std::shared_ptr<UIComponent> &ComponentManager::AddUIComponent(
        std::uint64_t ownerId, 
        UIComponent::Type type,
        std::string &&text,
        void *trackedData1,
        void *trackedData2,
        Vec3d textColor, 
        bool isVisible,
        std::function<void()> onClick
    ) {
        return (*uiComponents.try_emplace(ownerId, std::make_shared<UIComponent>(ownerId, type, text, trackedData1, trackedData2, textColor, isVisible, onClick)).first).second;
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
    std::unordered_map<size_t, std::shared_ptr<UIComponent>> &ComponentManager::GetUIComponents() {
        return uiComponents;
    }
        
    //
    std::unordered_map<size_t, std::shared_ptr<VisualComponent>> &ComponentManager::GetVisualComponents() {
        return visualComponents;
    }
        
    //
    std::shared_ptr<VisualComponent> &ComponentManager::AddVisualComponent(
        std::uint64_t ownerId, 
        sf::Texture &texture,
        bool isVisible,
        std::uint64_t displayOrder
    ) {
        this->displayOrder.insert({displayOrder, ownerId});
        return (*visualComponents.try_emplace(ownerId, std::make_shared<VisualComponent>(ownerId, texture, isVisible)).first).second;
    }
        
    //
    void ComponentManager::RemoveVisualComponent(std::uint64_t ownerId, std::uint64_t displayOrder) {
        this->displayOrder.erase({displayOrder, ownerId});
        visualComponents.erase(ownerId);
    }
        
    
    bool ComponentManager::HasVisualComponent(std::uint64_t id) {
        return visualComponents.contains(id);
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
    std::set<std::pair<std::uint64_t, std::uint64_t>> &ComponentManager::GetDisplayOrder() {
        return displayOrder;
    }
        
    //
    std::unordered_map<std::uint64_t, std::shared_ptr<TransformComponent>> &ComponentManager::GetTransformComponents() {
        return transformComponents;
    }
        
    //
    std::shared_ptr<TransformComponent> &ComponentManager::AddTransformComponent(
        std::uint64_t ownerId,
        Vec3d pos,
        Vec3d size
    ) {
        return (*transformComponents.try_emplace(ownerId, std::make_shared<TransformComponent>(ownerId, pos, size)).first).second;
    }
        
    //
    void ComponentManager::RemoveTransformComponent(std::uint64_t ownerId) {
        transformComponents.erase(ownerId);
    }
        
    
    bool ComponentManager::HasTransformComponent(std::uint64_t id) {
        return transformComponents.contains(id);
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
    
    //
    std::shared_ptr<MovementComponent> &ComponentManager::AddMovementComponent(
        std::uint64_t ownerId,
        Vec3d velocity,
        Vec3d acceleration
    ) {
        return (*movementComponents.try_emplace(ownerId, std::make_shared<MovementComponent>(ownerId, velocity, acceleration)).first).second;
    }
        
    //
    void ComponentManager::RemoveMovementComponent(std::uint64_t ownerId) {
        movementComponents.erase(ownerId);
    }
    
    //
    bool ComponentManager::HasMovementComponent(std::uint64_t id) {
        return movementComponents.contains(id);
    }
    
    //
    std::shared_ptr<MovementComponent> &ComponentManager::GetMovementComponent(std::uint64_t id) {
        try {
            return movementComponents.at(id);
        }
        catch (std::out_of_range &e) {
            std::cerr << "Error:\nGetting from ComponentManager MovementComponent with id: " << id << std::endl;
            exit(1);
        }
    }
    
    //
    std::unordered_map<std::uint64_t, std::shared_ptr<MovementComponent>> &ComponentManager::GetMovementComponents() {
        return movementComponents;
    }
    
    //
    std::shared_ptr<BodyComponent> &ComponentManager::AddBodyComponent(
        std::uint64_t ownerId,
        Vec3d size
    ) {
        return (*bodyComponents.try_emplace(ownerId, std::make_shared<BodyComponent>(ownerId, size)).first).second;
    }
        
    //
    void ComponentManager::RemoveBodyComponent(std::uint64_t ownerId) {
        bodyComponents.erase(ownerId);
    }
    
    //
    bool ComponentManager::HasBodyComponent(std::uint64_t id) {
        return bodyComponents.contains(id);
    }
    
    //
    std::shared_ptr<BodyComponent> &ComponentManager::GetBodyComponent(std::uint64_t id) {
        try {
            return bodyComponents.at(id);
        }
        catch (std::out_of_range &e) {
            std::cerr << "Error:\nGetting from ComponentManager BodyComponent with id: " << id << std::endl;
            exit(1);
        }
    }
    
    //
    std::unordered_map<std::uint64_t, std::shared_ptr<BodyComponent>> &ComponentManager::GetBodyComponents() {
        return bodyComponents;
    }
    
    //
    std::shared_ptr<GlyphComponent> &ComponentManager::AddGlyphComponent(
        std::uint64_t ownerId,
        char letter
    ) {
        return (*glyphComponents.try_emplace(ownerId, std::make_shared<GlyphComponent>(ownerId, letter)).first).second;
    }
        
    //
    void ComponentManager::RemoveGlyphComponent(std::uint64_t ownerId) {
        glyphComponents.erase(ownerId);
    }
    
    //
    bool ComponentManager::HasGlyphComponent(std::uint64_t id) {
        return glyphComponents.contains(id);
    }
    
    //
    std::shared_ptr<GlyphComponent> &ComponentManager::GetGlyphComponent(std::uint64_t id) {
        try {
            return glyphComponents.at(id);
        }
        catch (std::out_of_range &e) {
            std::cerr << "Error:\nGetting from ComponentManager GlyphComponent with id: " << id << std::endl;
            exit(1);
        }
    }
    
    //
    std::unordered_map<std::uint64_t, std::shared_ptr<GlyphComponent>> &ComponentManager::GetGlyphComponents() {
        return glyphComponents;
    }
    
    //
    std::shared_ptr<HealthComponent> &ComponentManager::AddHealthComponent(
        std::uint64_t ownerId,
        std::uint64_t currentHealth,
        std::uint64_t maxHealth
    ) {
        return (*healthComponents.try_emplace(ownerId, std::make_shared<HealthComponent>(ownerId, currentHealth, maxHealth)).first).second;
    }
        
    //
    void ComponentManager::RemoveHealthComponent(std::uint64_t ownerId) {
        healthComponents.erase(ownerId);
    }
    
    //
    bool ComponentManager::HasHealthComponent(std::uint64_t id) {
        return healthComponents.contains(id);
    }
    
    //
    std::shared_ptr<HealthComponent> &ComponentManager::GetHealthComponent(std::uint64_t id) {
        try {
            return healthComponents.at(id);
        }
        catch (std::out_of_range &e) {
            std::cerr << "Error:\nGetting from ComponentManager HealthComponent with id: " << id << std::endl;
            exit(1);
        }
    }
    
    //
    std::unordered_map<std::uint64_t, std::shared_ptr<HealthComponent>> &ComponentManager::GetHealthComponents() {
        return healthComponents;
    }
    
    //
    std::shared_ptr<DamageComponent> &ComponentManager::AddDamageComponent(
        std::uint64_t ownerId,
        std::uint64_t damageSize
    ) {
        return (*damageComponents.try_emplace(ownerId, std::make_shared<DamageComponent>(ownerId, damageSize)).first).second;
    }
        
    //
    void ComponentManager::RemoveDamageComponent(std::uint64_t ownerId) {
        damageComponents.erase(ownerId);
    }
    
    //
    bool ComponentManager::HasDamageComponent(std::uint64_t id) {
        return damageComponents.contains(id);
    }
    
    //
    std::shared_ptr<DamageComponent> &ComponentManager::GetDamageComponent(std::uint64_t id) {
        try {
            return damageComponents.at(id);
        }
        catch (std::out_of_range &e) {
            std::cerr << "Error:\nGetting from ComponentManager DamageComponent with id: " << id << std::endl;
            exit(1);
        }
    }
    
    //
    std::unordered_map<std::uint64_t, std::shared_ptr<DamageComponent>> &ComponentManager::GetDamageComponents() {
        return damageComponents;
    }
}