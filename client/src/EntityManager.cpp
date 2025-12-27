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
    std::shared_ptr<GameMode> &EntityManager::AddGameMode(
        bool isActive,
        std::function<void()> resultState,
        std::pair<long double, long double> &respawnSpace,
        std::pair<sf::Time, sf::Time> &respawnPeriodRange
    ) {
        std::uint64_t id = Entity::GetCounter();
        std::shared_ptr<GameModeComponent> &gameMode = componentManager.AddGameModeComponent(id, isActive, resultState, respawnSpace, respawnPeriodRange);
        return (*gameModes.try_emplace(id, std::make_shared<GameMode>(gameMode)).first).second;
    }

    //
    std::shared_ptr<GameMode> &EntityManager::AddGameMode(
        bool isActive,
        std::function<void()> resultState,
        std::pair<long double, long double> &&respawnSpace,
        std::pair<sf::Time, sf::Time> &&respawnPeriodRange
    ) {
        std::uint64_t id = Entity::GetCounter();
        std::shared_ptr<GameModeComponent> &gameMode = componentManager.AddGameModeComponent(id, isActive, resultState, respawnSpace, respawnPeriodRange);
        return (*gameModes.try_emplace(id, std::make_shared<GameMode>(gameMode)).first).second;
    }
    
    //
    std::shared_ptr<GameMode> &EntityManager::GetGameMode(std::uint64_t id) {
        try {
            return gameModes.at(id);
        }
        catch (std::out_of_range &e) {
            std::cerr << "Error:\nGetting from EntityManager gameModes with id: " << id << std::endl;
            exit(1);
        }
    }
        
    //
    void EntityManager::DeactivateGameModes() {
        for (auto &[key, it] : gameModes) {
            it->GetGameMode()->Deactivate();
        }
        for (auto &[id, letter] : letters) {
            componentManager.RemoveVisualComponent(id, 1000000);
            componentManager.RemoveTransformComponent(id);
            componentManager.RemoveBodyComponent(id);
            componentManager.RemoveMovementComponent(id);
            componentManager.RemoveGlyphComponent(id);
            componentManager.RemoveDamageComponent(id);
        }
        letters.clear();
        for (auto &[id, floor] : floors) {
            componentManager.RemoveVisualComponent(id, 1000);
            componentManager.RemoveTransformComponent(id);
            componentManager.RemoveBodyComponent(id);
            componentManager.RemoveHealthComponent(id);
        }
        floors.clear();
        for (auto &[id, player] : players) {
            player->GetPlayerStatComponent()->GetTotalLettersDestroyed() = 0;
            player->GetPlayerStatComponent()->GetLettersDestroyedPerMinute() = 0;
            player->GetPlayerStatComponent()->GetTimePassed() = 0;
        }
    }
        
    //
    std::shared_ptr<Background> &EntityManager::AddBackground(
        std::string &textureName,
        bool isVisible
    ) {
        sf::Texture &texture = GetSystemResources()->GetVisualResources().GetTexture(textureName);
        std::uint64_t id = Entity::GetCounter();
        std::shared_ptr<VisualComponent> &visual = componentManager.AddVisualComponent(id, texture, isVisible, 1);
        std::shared_ptr<ApplicationSettingsComponent> &settings = componentManager.GetApplicationSettingsComponent();
        return (*backgrounds.try_emplace(id, std::make_shared<Background>(visual, settings)).first).second;
    }
        
    //
    std::shared_ptr<Background> &EntityManager::AddBackground(
        std::string &&textureName,
        bool isVisible
    ) {
        sf::Texture &texture = GetSystemResources()->GetVisualResources().GetTexture(textureName);
        std::uint64_t id = Entity::GetCounter();
        std::shared_ptr<VisualComponent> &visual = componentManager.AddVisualComponent(id, texture, isVisible, 1);
        std::shared_ptr<ApplicationSettingsComponent> &settings = componentManager.GetApplicationSettingsComponent();
        return (*backgrounds.try_emplace(id, std::make_shared<Background>(visual, settings)).first).second;
    }
        
    //
    bool EntityManager::HasBackground(std::uint64_t id) {
        try {
            backgrounds.at(id);
            return true;
        }
        catch (std::out_of_range &e) {
            return false;
        }
    }
    
    //
    std::shared_ptr<Background> &EntityManager::GetBackground(std::uint64_t id) {
        try {
            return backgrounds.at(id);
        }
        catch (std::out_of_range &e) {
            std::cerr << "Error:\nGetting from EntityManager Background with id: " << id << std::endl;
            exit(1);
        }
    }
        
    //
    std::unordered_map<std::uint64_t, std::shared_ptr<Background>> &EntityManager::GetBackgrounds() {
        return backgrounds;
    }
        
    //
    std::shared_ptr<Button> &EntityManager::AddButton(
        std::string &text,
        std::function<std::string()> trackedData,
        std::uint64_t fontSize,
        Vec3d textColor,
        bool isVisible,
        std::function<void()> onClick,
        Vec3d pos,
        Vec3d size
    ) {
        std::uint64_t id = Entity::GetCounter();
        std::shared_ptr<UIComponent> &uiComponent = componentManager.AddUIComponent(id, UIComponent::Type::button, text, trackedData, fontSize, textColor, isVisible, onClick);
        id = Entity::GetCounter();
        std::shared_ptr<TransformComponent> &transform = componentManager.AddTransformComponent(id, pos, size);
        return (*buttons.try_emplace(id, std::make_shared<Button>(uiComponent, transform)).first).second;
    }
        
    //
    std::shared_ptr<Button> &EntityManager::AddButton(
        std::string &&text,
        std::function<std::string()> trackedData,
        std::uint64_t fontSize,
        Vec3d textColor, 
        bool isVisible,
        std::function<void()> onClick,
        Vec3d pos,
        Vec3d size
    ) {
        std::uint64_t id = Entity::GetCounter();
        std::shared_ptr<UIComponent> &uiComponent = componentManager.AddUIComponent(id, UIComponent::Type::button, text, trackedData, fontSize, textColor, isVisible, onClick);
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
        std::function<std::string()> trackedData,
        std::uint64_t fontSize,
        Vec3d textColor,
        bool isVisible,
        std::function<void()> onClick,
        Vec3d pos,
        Vec3d size
    ) {
        std::uint64_t id = Entity::GetCounter();
        std::shared_ptr<UIComponent> &uiComponent = componentManager.AddUIComponent(id, UIComponent::Type::label, text, trackedData, fontSize, textColor, isVisible, onClick);
        id = Entity::GetCounter();
        std::shared_ptr<TransformComponent> &transform = componentManager.AddTransformComponent(id, pos, size);
        return (*labels.try_emplace(id, std::make_shared<Label>(uiComponent, transform)).first).second;
    }
        
    //
    std::shared_ptr<Label> &EntityManager::AddLabel(
        std::string &&text,
        std::function<std::string()> trackedData,
        std::uint64_t fontSize,
        Vec3d textColor, 
        bool isVisible,
        std::function<void()> onClick,
        Vec3d pos,
        Vec3d size
    ) {
        std::uint64_t id = Entity::GetCounter();
        std::shared_ptr<UIComponent> &uiComponent = componentManager.AddUIComponent(id, UIComponent::Type::label, text, trackedData, fontSize, textColor, isVisible, onClick);
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
    std::unordered_map<std::uint64_t, std::shared_ptr<Label>> &EntityManager::GetLabels() {
        return labels;
    }
        
    //
    std::shared_ptr<HealthBar> &EntityManager::AddHealthBar(
        std::string &text,
        std::function<std::string()> trackedData,
        Vec3d textColor,
        bool isVisible,
        std::function<void()> onClick,
        Vec3d pos,
        Vec3d size
    ) {
        std::uint64_t id = Entity::GetCounter();
        std::shared_ptr<UIComponent> &uiComponent = componentManager.AddUIComponent(id, UIComponent::Type::progressBar, text, trackedData, 16, textColor, isVisible, onClick);
        id = Entity::GetCounter();
        std::shared_ptr<TransformComponent> &transform = componentManager.AddTransformComponent(id, pos, size);
        return (*healthBars.try_emplace(id, std::make_shared<HealthBar>(uiComponent, transform)).first).second;
    }
        
    //
    std::shared_ptr<HealthBar> &EntityManager::AddHealthBar(
        std::string &&text,
        std::function<std::string()> trackedData,
        Vec3d textColor, 
        bool isVisible,
        std::function<void()> onClick,
        Vec3d pos,
        Vec3d size
    ) {
        std::uint64_t id = Entity::GetCounter();
        std::shared_ptr<UIComponent> &uiComponent = componentManager.AddUIComponent(id, UIComponent::Type::progressBar, text, trackedData, 16, textColor, isVisible, onClick);
        id = Entity::GetCounter();
        std::shared_ptr<TransformComponent> &transform = componentManager.AddTransformComponent(id, pos, size);
        return (*healthBars.try_emplace(id, std::make_shared<HealthBar>(uiComponent, transform)).first).second;
    }
        
    //
    bool EntityManager::HasHealthBar(std::uint64_t id) {
        return healthBars.contains(id);
    }
        
    //
    std::shared_ptr<HealthBar> &EntityManager::GetHealthBar(std::uint64_t id) {
        try {
            return healthBars.at(id);
        }
        catch (std::out_of_range &e) {
            std::cerr << "Error:\nGetting from EntityManager HealthBar with id: " << id << std::endl;
            exit(1);
        }
    }
        
    //
    std::unordered_map<std::uint64_t, std::shared_ptr<HealthBar>> &EntityManager::GetHealthBars() {
        return healthBars;
    }
    
    //
    void EntityManager::HideUI() {
        auto uis = componentManager.GetUIComponents();
        for (auto &it : uis) {
            it.second->IsVisible() = false;
        }
        auto visuals = componentManager.GetVisualComponents();
        for (auto &it : visuals) {
            it.second->IsVisible() = false;
        }
    }
    
    //
    std::shared_ptr<Player> &EntityManager::AddPlayer() {
        std::uint64_t id = Entity::GetCounter();
        std::shared_ptr<PlayerStatComponent> &playerStat = componentManager.AddPlayerStatComponent(id);
        return (*players.try_emplace(id, std::make_shared<Player>(playerStat)).first).second;
    }
        
    //
    void EntityManager::RemovePlayer(std::uint64_t id) {
        componentManager.RemovePlayerStatComponent(id);
        players.erase(id);
    }
        
    //
    bool EntityManager::HasPlayer(std::uint64_t id) {
        return players.contains(id);
    }
    
    //
    std::shared_ptr<Player> &EntityManager::GetPlayer(std::uint64_t id) {
        try {
            return players.at(id);
        }
        catch (std::out_of_range &e) {
            std::cerr << "Error:\nGetting from EntityManager Button with id: " << id << std::endl;
            exit(1);
        }
    }
    
    //
    std::unordered_map<std::uint64_t, std::shared_ptr<Player>> &EntityManager::GetPlayers() {
        return players;
    }
    
    //
    std::shared_ptr<Letter> &EntityManager::AddLetter(
        bool isVisible,
        Vec3d position,
        Vec3d rotation, 
        Vec3d size,
        Vec3d velocity,
        Vec3d acceleration,
        char letter,
        std::uint64_t damageSize
    ) {
        std::string &textureName = GetSystemResources()->GetVisualResources().CharToTextureName(letter);
        sf::Texture &texture = GetSystemResources()->GetVisualResources().GetTexture(textureName);
        std::uint64_t id = Entity::GetCounter();
        std::shared_ptr<VisualComponent> &visual = componentManager.AddVisualComponent(id, texture, isVisible, 1000000);
        id = Entity::GetCounter();
        std::shared_ptr<TransformComponent> &transform = componentManager.AddTransformComponent(id, position, size);
        id = Entity::GetCounter();
        std::shared_ptr<BodyComponent> &body = componentManager.AddBodyComponent(id, size);
        id = Entity::GetCounter();
        std::shared_ptr<MovementComponent> &movement = componentManager.AddMovementComponent(id, velocity, acceleration);
        id = Entity::GetCounter();
        std::shared_ptr<GlyphComponent> &glyph = componentManager.AddGlyphComponent(id, letter);
        id = Entity::GetCounter();
        std::shared_ptr<DamageComponent> &damage = componentManager.AddDamageComponent(id, damageSize);
        return (*letters.try_emplace(id, std::make_shared<Letter>(visual, transform, body, movement, glyph, damage)).first).second;
    }
        
    //
    void EntityManager::RemoveLetter(std::uint64_t id) {
        componentManager.RemoveVisualComponent(id, 1000000);
        componentManager.RemoveTransformComponent(id);
        componentManager.RemoveBodyComponent(id);
        componentManager.RemoveMovementComponent(id);
        componentManager.RemoveGlyphComponent(id);
        componentManager.RemoveDamageComponent(id);
        letters.erase(id);
    }
        
    //
    bool EntityManager::HasLetter(std::uint64_t id) {
        return letters.contains(id);
    }
    
    //
    std::shared_ptr<Letter> &EntityManager::GetLetter(std::uint64_t id) {
        try {
            return letters.at(id);
        }
        catch (std::out_of_range &e) {
            std::cerr << "Error:\nGetting from EntityManager Button with id: " << id << std::endl;
            exit(1);
        }
    }
    
    //
    std::unordered_map<std::uint64_t, std::shared_ptr<Letter>> &EntityManager::GetLetters() {
        return letters;
    }
        
    //
    std::shared_ptr<Floor> &EntityManager::AddFloor(
        bool isVisible,
        Vec3d position, 
        Vec3d rotation, 
        Vec3d size,
        std::uint64_t currentHealth,
        std::uint64_t maxHealth
    ) {
        sf::Texture &texture = GetSystemResources()->GetVisualResources().GetTexture("../data/floor.png");
        std::uint64_t id = Entity::GetCounter();
        std::shared_ptr<VisualComponent> &visual = componentManager.AddVisualComponent(id, texture, isVisible, 1000);
        id = Entity::GetCounter();
        std::shared_ptr<TransformComponent> &transform = componentManager.AddTransformComponent(id, position, size);
        id = Entity::GetCounter();
        std::shared_ptr<BodyComponent> &body = componentManager.AddBodyComponent(id, size);
        id = Entity::GetCounter();
        std::shared_ptr<HealthComponent> &health = componentManager.AddHealthComponent(id, currentHealth, maxHealth);
        return (*floors.try_emplace(id, std::make_shared<Floor>(visual, transform, body, health)).first).second;
    }
        
    //
    void EntityManager::RemoveFloor(std::uint64_t id) {
        componentManager.RemoveVisualComponent(id, 1000);
        componentManager.RemoveTransformComponent(id);
        componentManager.RemoveBodyComponent(id);
        componentManager.RemoveHealthComponent(id);
        floors.erase(id);
    }
        
    //
    bool EntityManager::HasFloor(std::uint64_t id) {
        return floors.contains(id);
    }
    
    //
    std::shared_ptr<Floor> &EntityManager::GetFloor(std::uint64_t id) {
        try {
            return floors.at(id);
        }
        catch (std::out_of_range &e) {
            std::cerr << "Error:\nGetting from EntityManager Button with id: " << id << std::endl;
            exit(1);
        }
    }
    
    //
    std::unordered_map<std::uint64_t, std::shared_ptr<Floor>> &EntityManager::GetFloors() {
        return floors;
    }
}