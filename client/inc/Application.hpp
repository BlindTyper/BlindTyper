/*

*/

#ifndef APPLICATION_TYPE_HEADER
#define APPLICATION_TYPE_HEADER

#include <Main.hpp>

#include "EntityManager.hpp"
#include "ComponentManager.hpp"
#include "SystemManager.hpp"

namespace tppo{
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
    
    class Application {
        
    protected:
        //
        ComponentManager componentManager;
        
        //
        EntityManager entityManager;
        
        //
        SystemManager systemManager;
        
        //
        Screens currentScreen;
        
        //
        sf::RenderWindow window;
        
        //
        ImGuiWindowFlags window_flags;
        
        //
        bool p_open;
        
        //
        sf::Clock deltaClock;
        
    public:
        //
        Application();
        
        //
        ~Application();
        
        //
        void Init();
        
        //
        void Run();
        
        //
        void showMainMenu(ImFontAtlas *Fonts, const ImGuiViewport* viewport, sf::Sprite &imageBackground);
        
        //
        void showCampaignMenu(ImFontAtlas *Fonts, const ImGuiViewport* viewport, sf::Sprite &imageBackground);
        
    };
}

#endif //APPLICATION_TYPE_HEADER
