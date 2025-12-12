/*

*/

#ifndef APPLICATION_SETTINGS_COMPONENT_TYPE_HEADER
#define APPLICATION_SETTINGS_COMPONENT_TYPE_HEADER

#include "Main.hpp"

#include "Component.hpp"

namespace tppo{
    class ApplicationSettingsComponent : Component {
        
    protected:
        //
        bool isUpdated;
        
        //
        bool isFullscreen;
        
        //
        ImGuiWindowFlags windowFlags;
        
        //
        std::string windowTitle;
        
        //
        sf::VideoMode windowMode;
        
        //
        std::uint32_t windowStyle;
        
        //
        sf::State windowState;
        
    public:
        //
        ApplicationSettingsComponent(std::uint64_t ownerId);
        
        //
        void SetWindowFlags(ImGuiWindowFlags newWindowFlags);
        
        //
        void AddWindowFlags(ImGuiWindowFlags newWindowFlags);
        
        //
        ImGuiWindowFlags &GetWindowFlags();
        
        //
        void SetWindowTitle(std::string &title);
        
        //
        void SetWindowTitle(std::string &&title);
        
        //
        std::string &GetWindowTitle();
        
        //
        void SetWindowVideoMode(sf::VideoMode &mode);
        
        //
        void SetWindowVideoMode(sf::VideoMode &&mode);
        
        //
        sf::VideoMode &GetWindowVideoMode();
        
        //
        void SetWindowStyle(std::uint32_t style);
        
        //
        std::uint32_t &GetWindowStyle();
        
        //
        void SetWindowState(sf::State &state);
        
        //
        void SetWindowState(sf::State &&state);
        
        //
        sf::State &GetWindowState();
        
        //
        void SetWindowSettings(sf::VideoMode &mode, std::string &title, std::uint32_t &style, sf::State &state);
        
        //
        void SetWindowSettings(sf::VideoMode &&mode, std::string &&title, std::uint32_t &&style, sf::State &&state);
        
    };
}

#endif //APPLICATION_SETTINGS_COMPONENT_TYPE_HEADER
