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
#include "HealthBar.hpp"
#include "GameMode.hpp"

namespace tppo {
    class EntityManager : public Manager{
        
    protected:
        //
        ComponentManager &componentManager;
    
        //
        std::shared_ptr<SystemResources> systemResources;
    
        //
        std::shared_ptr<ApplicationStates> applicationStates;
        
        //
        std::unordered_map<std::uint64_t, std::shared_ptr<GameMode>> gameModes;
        
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
        std::unordered_map<std::uint64_t, std::shared_ptr<HealthBar>> healthBars;
        
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
        std::shared_ptr<GameMode> &AddGameMode(
            bool isActive,
            std::function<void()> resultState,
            std::pair<long double, long double> &respawnSpace,
            std::pair<sf::Time, sf::Time> &respawnPeriodRange
        );
        

        //
        std::shared_ptr<GameMode> &AddGameMode(
            bool isActive,
            std::function<void()> resultState,
            std::pair<long double, long double> &&respawnSpace,
            std::pair<sf::Time, sf::Time> &&respawnPeriodRange
        );
        
        //
        std::shared_ptr<GameMode> &GetGameMode(std::uint64_t id);
        
        //
        void DeactivateGameModes();
        
        //
        std::shared_ptr<Background> &AddBackground(
            std::string &textureName,
            bool isVisible = true
        );
        
        //
        std::shared_ptr<Background> &AddBackground(
            std::string &&textureName,
            bool isVisible = true
        );
        
        //
        bool HasBackground(std::uint64_t id);
        
        //
        std::shared_ptr<Background> &GetBackground(std::uint64_t id);
        
        //
        std::unordered_map<std::uint64_t, std::shared_ptr<Background>> &GetBackgrounds();
        
        //
        std::shared_ptr<Button> &AddButton(
            std::string &text, 
            std::function<std::string()> trackedData = nullptr,
            std::uint64_t fontSize = 16,
            Vec3d textColor = Vec3d(),
            bool isVisible = true,
            std::function<void()> onClick = nullptr,
            Vec3d pos = Vec3d(), 
            Vec3d size = Vec3d()
        );
        
        //
        std::shared_ptr<Button> &AddButton(
            std::string &&text, 
            std::function<std::string()> trackedData = nullptr,
            std::uint64_t fontSize = 16,
            Vec3d textColor = Vec3d(),
            bool isVisble = true,
            std::function<void()> onClick = nullptr,
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
            std::function<std::string()> trackedData = nullptr,
            std::uint64_t fontSize = 16,
            Vec3d textColor = Vec3d(),
            bool isVisible = true,
            std::function<void()> onClick = nullptr,
            Vec3d pos = Vec3d(), 
            Vec3d size = Vec3d()
        );
        
        //
        std::shared_ptr<Label> &AddLabel(
            std::string &&text, 
            std::function<std::string()> trackedData = nullptr,
            std::uint64_t fontSize = 16,
            Vec3d textColor = Vec3d(),
            bool isVisible = true,
            std::function<void()> onClick = nullptr, 
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
        std::shared_ptr<HealthBar> &AddHealthBar(
            std::string &text,
            std::function<std::string()> trackedData = nullptr,
            Vec3d textColor = Vec3d(),
            bool isVisible = true,
            std::function<void()> onClick = nullptr,
            Vec3d pos = Vec3d(), 
            Vec3d size = Vec3d()
        );
        
        //
        std::shared_ptr<HealthBar> &AddHealthBar(
            std::string &&text,
            std::function<std::string()> trackedData = nullptr,
            Vec3d textColor = Vec3d(),
            bool isVisible = true,
            std::function<void()> onClick = nullptr, 
            Vec3d pos = Vec3d(), 
            Vec3d size = Vec3d()
        );
        
        //
        bool HasHealthBar(std::uint64_t id);
        
        //
        std::shared_ptr<HealthBar> &GetHealthBar(std::uint64_t id);
        
        //
        std::unordered_map<std::uint64_t, std::shared_ptr<HealthBar>> &GetHealthBars();
        
        //
        void HideUI();
        
        //
        std::shared_ptr<Player> &AddPlayer();
        
        //
        void RemovePlayer(std::uint64_t id);
        
        //
        bool HasPlayer(std::uint64_t id);
        
        //
        std::shared_ptr<Player> &GetPlayer(std::uint64_t id);
        
        //
        std::unordered_map<std::uint64_t, std::shared_ptr<Player>> &GetPlayers();
        
        //
        std::shared_ptr<Letter> &AddLetter(
            bool isVisible = true,
            Vec3d position = Vec3d(), 
            Vec3d rotation = Vec3d(), 
            Vec3d size = Vec3d(),
            Vec3d velocity = Vec3d(),
            Vec3d acceleration = Vec3d(),
            char letter = 'a',
            std::uint64_t damageSize = 1
        );
        
        //
        void RemoveLetter(std::uint64_t id);
        
        //
        bool HasLetter(std::uint64_t id);
        
        //
        std::shared_ptr<Letter> &GetLetter(std::uint64_t id);
        
        //
        std::unordered_map<std::uint64_t, std::shared_ptr<Letter>> &GetLetters();
        
        //
        std::shared_ptr<Floor> &AddFloor(
            bool isVisible = true,
            Vec3d position = Vec3d(), 
            Vec3d rotation = Vec3d(), 
            Vec3d size = Vec3d(),
            std::uint64_t currentHealth = 100ull,
            std::uint64_t maxHealth = 100ull
        );
        
        //
        void RemoveFloor(std::uint64_t id);
        
        //
        bool HasFloor(std::uint64_t id);
        
        //
        std::shared_ptr<Floor> &GetFloor(std::uint64_t id);
        
        //
        std::unordered_map<std::uint64_t, std::shared_ptr<Floor>> &GetFloors();
        
    };
}
#endif //ENTITY_MANAGER_TYPE_HEADER
