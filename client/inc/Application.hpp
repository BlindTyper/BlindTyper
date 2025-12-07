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
        EntityManager entityManager;
        
        //
        ComponentManager componentManager;
        
        //
        SystemManager systemManager;
        
        //
        Screens currentScreen;
        
        //
        sf::RenderWindow window;
        
        //
        ImFontConfig font_cfg;
        
        //
        ImGuiWindowFlags window_flags;
        
        //
        sf::Texture backgroundImage;
        
        //
        sf::Sprite imageBackground;
        
        //
        bool p_open;
        
        //
        sf::Clock deltaClock;
        
        //
        ImGuiIO *io;
        
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
        void showMainMenu(ImFontAtlas *Fonts, const ImGuiViewport* viewport);
        
        //
        void showCampaignMenu(ImFontAtlas *Fonts, const ImGuiViewport* viewport);
        
    };
}

#endif //APPLICATION_TYPE_HEADER
