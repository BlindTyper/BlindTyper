/*

*/

#ifndef COMPONENT_MANAGER_TYPE_HEADER
#define COMPONENT_MANAGER_TYPE_HEADER

#include "Main.hpp"

#include <iostream>
#include <memory>
#include <set>
#include <stdexcept>
#include <unordered_map>

#include "Manager.hpp"

#include "ApplicationSettingsComponent.hpp"
#include "ApplicationStateComponent.hpp"
#include "WindowComponent.hpp"
#include "VisualResourcesComponent.hpp"
#include "GameModeComponent.hpp"
#include "PlayerStatComponent.hpp"
#include "UIComponent.hpp"
#include "VisualComponent.hpp"
#include "TransformComponent.hpp"
#include "BodyComponent.hpp"
#include "HealthComponent.hpp"
#include "DamageComponent.hpp"
#include "MovementComponent.hpp"
#include "GlyphComponent.hpp"
#include "SoundComponent.hpp"

namespace tppo {
    class ComponentManager : public Manager {
        
    protected:
        //
        std::shared_ptr<ApplicationSettingsComponent> applicationSettingsComponent;
        
        //
        std::unordered_map<std::string, std::shared_ptr<ApplicationStateComponent>> applicationStatesComponents;
        
        //
        std::shared_ptr<WindowComponent> windowComponent;
        
        //
        std::shared_ptr<VisualResourcesComponent> visualResourcesComponent;
        
        //
        std::unordered_map<std::uint64_t, std::shared_ptr<GameModeComponent>> gameModeComponents;
        
        //
        std::unordered_map<std::uint64_t, std::shared_ptr<PlayerStatComponent>> playerStatComponents;
        
        //
        std::unordered_map<std::uint64_t, std::shared_ptr<UIComponent>> uiComponents;
        
        //
        std::unordered_map<std::uint64_t, std::shared_ptr<VisualComponent>> visualComponents;
        
        //
        std::set<std::pair<std::uint64_t, std::uint64_t>> displayOrder;
        
        //
        std::unordered_map<std::uint64_t, std::shared_ptr<TransformComponent>> transformComponents;
        
        //
        std::unordered_map<std::uint64_t, std::shared_ptr<BodyComponent>> bodyComponents;
        
        //
        std::unordered_map<std::uint64_t, std::shared_ptr<HealthComponent>> healthComponents;
        
        //
        std::unordered_map<std::uint64_t, std::shared_ptr<DamageComponent>> damageComponents;
        
        //
        std::unordered_map<std::uint64_t, std::shared_ptr<MovementComponent>> movementComponents;
        
        //
        std::unordered_map<std::uint64_t, std::shared_ptr<GlyphComponent>> glyphComponents;
        
        //
        std::unordered_map<std::uint64_t, std::shared_ptr<SoundComponent>> soundComponents;
        
    public:
        //
        ComponentManager();
        
        //
        ~ComponentManager();
        
        //
        void Init();
        
        //
        std::shared_ptr<ApplicationSettingsComponent> &GetApplicationSettingsComponent();
        
        //
        std::shared_ptr<ApplicationStateComponent> &AddApplicationStateComponent(std::uint64_t ownerId, std::string &stateName);
        
        //
        std::shared_ptr<ApplicationStateComponent> &AddApplicationStateComponent(std::uint64_t ownerId, std::string &&stateName);
        
        //
        std::shared_ptr<ApplicationStateComponent> &GetApplicationStateComponent(std::string stateName);
        
        //
        std::shared_ptr<WindowComponent> &GetWindowComponent();
        
        //
        std::shared_ptr<VisualResourcesComponent> &GetVisualResourcesComponent();
        
        //
        std::shared_ptr<GameModeComponent> &AddGameModeComponent(
            std::uint64_t ownerId,
            bool isActive,
            std::function<void()> resultState,
            std::pair<long double, long double> &respawnSpace,
            std::pair<sf::Time, sf::Time> &respawnPeriodRange,
            std::uint64_t defaultLetterDamage = 1
        );
        
        //
        std::shared_ptr<GameModeComponent> &AddGameModeComponent(
            std::uint64_t ownerId,
            bool isActive,
            std::function<void()> resultState,
            std::pair<long double, long double> &&respawnSpace,
            std::pair<sf::Time, sf::Time> &&respawnPeriodRange,
            std::uint64_t defaultLetterDamage = 1
        );
        
        //
        bool HasGameModeComponent(std::uint64_t id);
        
        //
        std::shared_ptr<GameModeComponent> &GetGameModeComponent(std::uint64_t id);
        
        //
        std::unordered_map<size_t, std::shared_ptr<GameModeComponent>> &GetGameModeComponents();
        
        //
        std::shared_ptr<PlayerStatComponent> &AddPlayerStatComponent(
            std::uint64_t ownerId
        );
        
        //
        bool HasPlayerStatComponent(std::uint64_t id);
        
        //
        std::shared_ptr<PlayerStatComponent> &GetPlayerStatComponent(std::uint64_t id);
        
        //
        std::unordered_map<size_t, std::shared_ptr<PlayerStatComponent>> &GetPlayerStatComponents();
        
        //
        void RemovePlayerStatComponent(std::uint64_t id);
        
        //
        std::shared_ptr<UIComponent> &AddUIComponent(
            std::uint64_t ownerId, 
            UIComponent::Type type,
            std::string &text,
            std::function<std::string()> trackedData,
            std::uint64_t fontSize,
            Vec3d textColor, 
            bool isVisible,
            std::function<void()> onClick
        );
        
        //
        std::shared_ptr<UIComponent> &AddUIComponent(
            std::uint64_t ownerId, 
            UIComponent::Type type,
            std::string &&text,
            std::function<std::string()> trackedData,
            std::uint64_t fontSize,
            Vec3d textColor, 
            bool isVisible,
            std::function<void()> onClick
        );
        
        //
        bool HasUIComponent(std::uint64_t id);
        
        //
        std::shared_ptr<UIComponent> &GetUIComponent(std::uint64_t id);
        
        //
        std::unordered_map<size_t, std::shared_ptr<UIComponent>> &GetUIComponents();
        
        //
        std::shared_ptr<VisualComponent> &AddVisualComponent(
            std::uint64_t ownerId, 
            sf::Texture &texture,
            bool isVisible,
            std::uint64_t displayOrder
        );
        
        //
        void RemoveVisualComponent(std::uint64_t id, std::uint64_t displayOrder);
        
        //
        bool HasVisualComponent(std::uint64_t id);
        
        //
        std::shared_ptr<VisualComponent> &GetVisualComponent(std::uint64_t id);
        
        //
        std::unordered_map<std::uint64_t, std::shared_ptr<VisualComponent>> &GetVisualComponents();
        
        //
        std::set<std::pair<std::uint64_t, std::uint64_t>> &GetDisplayOrder();
        
        //
        std::shared_ptr<TransformComponent> &AddTransformComponent(
            std::uint64_t ownerId,
            Vec3d pos,
            Vec3d size
        );
        
        //
        void RemoveTransformComponent(std::uint64_t id);
        
        //
        bool HasTransformComponent(std::uint64_t id);
        
        //
        std::shared_ptr<TransformComponent> &GetTransformComponent(std::uint64_t id);
        
        //
        std::unordered_map<std::uint64_t, std::shared_ptr<TransformComponent>> &GetTransformComponents();
        
        //
        std::shared_ptr<MovementComponent> &AddMovementComponent(
            std::uint64_t ownerId,
            Vec3d velocity,
            Vec3d acceleration
        );
        
        //
        void RemoveMovementComponent(std::uint64_t id);
        
        //
        bool HasMovementComponent(std::uint64_t id);
        
        //
        std::shared_ptr<MovementComponent> &GetMovementComponent(std::uint64_t id);
        
        //
        std::unordered_map<std::uint64_t, std::shared_ptr<MovementComponent>> &GetMovementComponents();
        
        //
        std::shared_ptr<BodyComponent> &AddBodyComponent(
            std::uint64_t ownerId,
            Vec3d size
        );
        
        //
        void RemoveBodyComponent(std::uint64_t id);
        
        //
        bool HasBodyComponent(std::uint64_t id);
        
        //
        std::shared_ptr<BodyComponent> &GetBodyComponent(std::uint64_t id);
        
        //
        std::unordered_map<std::uint64_t, std::shared_ptr<BodyComponent>> &GetBodyComponents();
        
        
        //
        std::shared_ptr<GlyphComponent> &AddGlyphComponent(
            std::uint64_t ownerId,
            char letter
        );
        
        //
        void RemoveGlyphComponent(std::uint64_t id);
        
        //
        bool HasGlyphComponent(std::uint64_t id);
        
        //
        std::shared_ptr<GlyphComponent> &GetGlyphComponent(std::uint64_t id);
        
        //
        std::unordered_map<std::uint64_t, std::shared_ptr<GlyphComponent>> &GetGlyphComponents();
        
        //
        std::shared_ptr<HealthComponent> &AddHealthComponent(
            std::uint64_t ownerId,
            std::uint64_t currentHealth,
            std::uint64_t maxHealth
        );
        
        //
        void RemoveHealthComponent(std::uint64_t id);
        
        //
        bool HasHealthComponent(std::uint64_t id);
        
        //
        std::shared_ptr<HealthComponent> &GetHealthComponent(std::uint64_t id);
        
        //
        std::unordered_map<std::uint64_t, std::shared_ptr<HealthComponent>> &GetHealthComponents();
        
        //
        std::shared_ptr<DamageComponent> &AddDamageComponent(
            std::uint64_t ownerId,
            std::uint64_t damageSize
        );
        
        //
        void RemoveDamageComponent(std::uint64_t id);
        
        //
        bool HasDamageComponent(std::uint64_t id);
        
        //
        std::shared_ptr<DamageComponent> &GetDamageComponent(std::uint64_t id);
        
        //
        std::unordered_map<std::uint64_t, std::shared_ptr<DamageComponent>> &GetDamageComponents();
        
    };
}
#endif //COMPONENT_MANAGER_TYPE_HEADER
