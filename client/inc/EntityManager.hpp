/*

*/

#ifndef ENTITY_MANAGER_TYPE_HEADER
#define ENTITY_MANAGER_TYPE_HEADER

#include "Main.hpp"

#include <cstdint>
#include <memory>
#include <unordered_map>

#include "Manager.hpp"
#include "ComponentManager.hpp"

#include "Entity.hpp"
#include "SystemResources.hpp"
#include "ApplicationStates.hpp"
#include "Letter.hpp"
#include "Floor.hpp"
#include "Player.hpp"
#include "Background.hpp"
#include "Button.hpp"
#include "Label.hpp"
//#include "GameMode.hpp"

namespace tppo{
    class EntityManager : public Manager{
        
    protected:
        //
        ComponentManager &componentManager;
    
        //
        std::shared_ptr<SystemResources> systemResources;
    
        //
        std::shared_ptr<ApplicationStates> applicationStates;
        
        //
        std::unordered_map<std::uint64_t, std::shared_ptr<Letter>> letters;
        
        //
        std::unordered_map<std::uint64_t, std::shared_ptr<Floor>> floors;
        
        //
        std::unordered_map<std::uint64_t, std::shared_ptr<Player>> players;
        
        //
        std::unordered_map<std::uint64_t, std::shared_ptr<Background>> backgrounds;
        
        //
        std::unordered_map<std::uint64_t, std::shared_ptr<Button>> buttons;
        
        //
        std::unordered_map<std::uint64_t, std::shared_ptr<Label>> labels;
        
        //
        //std::unordered_map<uint64_t, GameMode> GameModes;
        
    public:
        //
        EntityManager(ComponentManager &componentManager);
        
        //
        ~EntityManager();
        
        //
        void Init();
        
        //
        std::shared_ptr<SystemResources> &GetSystemResources();

        //
        std::shared_ptr<ApplicationStateComponent> &AddApplicationState(std::string &stateName);

        //
        std::shared_ptr<ApplicationStateComponent> &AddApplicationState(std::string &&stateName);
        
        //
        std::shared_ptr<ApplicationStates> &GetApplicationStates();
        
        //
        std::shared_ptr<Background> &AddBackground(std::string &textureName);
        
        //
        std::shared_ptr<Background> &AddBackground(std::string &&textureName);
        
        //
        std::unordered_map<std::uint64_t, std::shared_ptr<Background>> &GetBackgrounds();
        
        //
        std::shared_ptr<Button> &AddButton(
            std::string &text, 
            Vec3d textColor = Vec3d(),
            bool isVisible = true,
            std::function<void()> onClick = [](){},
            Vec3d pos = Vec3d(), 
            Vec3d size = Vec3d()
        );
        
        //
        std::shared_ptr<Button> &AddButton(
            std::string &&text, 
            Vec3d textColor = Vec3d(),
            bool isVisble = true,
            std::function<void()> onClick = [](){},
            Vec3d pos = Vec3d(), 
            Vec3d size = Vec3d()
        );
        
        //
        bool HasButton(std::uint64_t id);
        
        //
        std::shared_ptr<Button> &GetButton(std::uint64_t id);
        
        //
        std::unordered_map<std::uint64_t, std::shared_ptr<Button>> &GetButtons();
        
        //
        std::shared_ptr<Label> &AddLabel(
            std::string &text,
            Vec3d textColor = Vec3d(),
            bool isVisible = true,
            std::function<void()> onClick = [](){},
            Vec3d pos = Vec3d(), 
            Vec3d size = Vec3d()
        );
        
        //
        std::shared_ptr<Label> &AddLabel(
            std::string &&text, 
            Vec3d textColor = Vec3d(),
            bool isVisible = true,
            std::function<void()> onClick = [](){}, 
            Vec3d pos = Vec3d(), 
            Vec3d size = Vec3d()
        );
        
        //
        bool HasLabel(std::uint64_t id);
        
        //
        std::shared_ptr<Label> &GetLabel(std::uint64_t id);
        
        //
        std::unordered_map<std::uint64_t, std::shared_ptr<Label>> &GetLabels();
        
        //
        void HideUI();
        
    };
}
#endif //ENTITY_MANAGER_TYPE_HEADER
