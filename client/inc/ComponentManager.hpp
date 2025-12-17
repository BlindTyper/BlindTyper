/*

*/

#ifndef COMPONENT_MANAGER_TYPE_HEADER
#define COMPONENT_MANAGER_TYPE_HEADER

#include "Main.hpp"

#include <iostream>
#include <memory>
#include <stdexcept>
#include <unordered_map>

#include "Manager.hpp"

#include "ApplicationSettingsComponent.hpp"
#include "ApplicationStateComponent.hpp"
#include "WindowComponent.hpp"
#include "VisualResourcesComponent.hpp"
#include "UIComponent.hpp"
#include "VisualComponent.hpp"
#include "TransformComponent.hpp"
#include "BodyComponent.hpp"
#include "HealthComponent.hpp"
#include "LifetimeComponent.hpp"
#include "SoundComponent.hpp"
#include "MovementComponent.hpp"
#include "LetterComponent.hpp"

namespace tppo{
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
        std::unordered_map<std::uint64_t, std::shared_ptr<UIComponent>> uiComponents;
        
        //
        std::unordered_map<std::uint64_t, std::shared_ptr<VisualComponent>> visualComponents;
        
        //
        std::unordered_map<std::uint64_t, std::shared_ptr<TransformComponent>> transformComponents;
        
        //
        std::unordered_map<std::uint64_t, std::shared_ptr<BodyComponent>> bodyComponents;
        
        //
        std::unordered_map<std::uint64_t, std::shared_ptr<SoundComponent>> soundComponents;
        
        //
        std::unordered_map<std::uint64_t, std::shared_ptr<LifetimeComponent>> lifetimeComponents;
        
        //
        std::unordered_map<std::uint64_t, std::shared_ptr<HealthComponent>> healthComponents;
        
        //
        std::unordered_map<std::uint64_t, std::shared_ptr<MovementComponent>> movementComponents;
        
        //
        std::unordered_map<std::uint64_t, std::shared_ptr<LetterComponent>> letterComponents;
        
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
        std::unordered_map<size_t, std::shared_ptr<UIComponent>> &GetUIComponents();
        
        //
        std::shared_ptr<UIComponent> &AddUIComponent(
            std::uint64_t ownerId, 
            std::string &text,
            Vec3d textColor, 
            bool isVisible,
            std::function<void()> onClick
        );
        
        //
        std::shared_ptr<UIComponent> &AddUIComponent(
            std::uint64_t ownerId, 
            std::string &&text,
            Vec3d textColor, 
            bool isVisible,
            std::function<void()> onClick
        );
        
        //
        bool HasUIComponent(std::uint64_t id);
        
        //
        std::shared_ptr<UIComponent> &GetUIComponent(std::uint64_t id);
        
        //
        std::unordered_map<size_t, std::shared_ptr<VisualComponent>> &GetVisualComponents();
        
        //
        std::shared_ptr<VisualComponent> &AddVisualComponent(std::uint64_t ownerId, sf::Texture &texture);
        
        //
        std::shared_ptr<VisualComponent> &GetVisualComponent(std::uint64_t id);
        
        //
        std::unordered_map<size_t, std::shared_ptr<TransformComponent>> &GetTransformComponents();
        
        //
        std::shared_ptr<TransformComponent> &AddTransformComponent(
            std::uint64_t ownerId,
            Vec3d pos,
            Vec3d size
        );
        
        //
        std::shared_ptr<TransformComponent> &GetTransformComponent(std::uint64_t id);
        
    };
}
#endif //COMPONENT_MANAGER_TYPE_HEADER
