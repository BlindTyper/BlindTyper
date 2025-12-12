/*

*/

#ifndef VISUAL_SYSTEM_TYPE_HEADER
#define VISUAL_SYSTEM_TYPE_HEADER

#include "System.hpp"

#include <string>
#include <vector>

#include <ComponentManager.hpp>
#include <EntityManager.hpp>

namespace tppo {
    enum Screens {
        mainMenu = 0,
        campaignMenu,
        endlessModeMenu,
        onlineGameMenu,
        lobbyMenuPlayer,
        lobbyMenuHost,
        lobbyMenuHostLobbySettings,
        applicationSettingsMenu,
        profileMenu,
        profileRegistrationMenu,
        profileAuthorizationMenu,
        gameMenu,
        pauseMenu
    };
    
    class VisualSystem : System {
        
    protected:
        //
        Screens currentScreen;
        
        //
        sf::Clock deltaClock;
        
        //
        bool p_open;
        
        
    public:
        //
        VisualSystem(ComponentManager &componentManager, EntityManager &entityManager);
        
        //
        ~VisualSystem();
        
        //
        void Init();
        
        //
        void Update();
    };
}

#endif //VISUAL_SYSTEM_TYPE_HEADER