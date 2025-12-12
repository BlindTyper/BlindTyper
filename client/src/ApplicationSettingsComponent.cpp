/*

*/

#include "ApplicationSettingsComponent.hpp"

namespace tppo {
    //
    ApplicationSettingsComponent::ApplicationSettingsComponent(uint64_t ownerId) 
        : Component(ownerId)
        , isUpdated(0)
        , isFullscreen(0)
        , windowFlags(0)
        , windowTitle()
        , windowMode()
        , windowStyle(0)
        , windowState()
    {
        
    }
    
    //
    void ApplicationSettingsComponent::SetWindowFlags(ImGuiWindowFlags newWindowFlags) {
        windowFlags = newWindowFlags;
    }
    
    //
    void ApplicationSettingsComponent::AddWindowFlags(ImGuiWindowFlags newWindowFlags) {
        windowFlags |= newWindowFlags;
    }
    
    //
    ImGuiWindowFlags &ApplicationSettingsComponent::GetWindowFlags() {
        return windowFlags;
    }
    
    //
    void ApplicationSettingsComponent::SetWindowTitle(std::string &title) {
        windowTitle = title;
    }
    
    //
    void ApplicationSettingsComponent::SetWindowTitle(std::string &&title) {
        windowTitle = title;
    }
    
    //
    std::string &ApplicationSettingsComponent::GetWindowTitle() {
        return windowTitle;
    }
    
    //
    void ApplicationSettingsComponent::SetWindowVideoMode(sf::VideoMode &mode) {
        windowMode = mode;
    }
    
    //
    void ApplicationSettingsComponent::SetWindowVideoMode(sf::VideoMode &&mode) {
        windowMode = mode;
    }
    
    //
    sf::VideoMode &ApplicationSettingsComponent::GetWindowVideoMode() {
        return windowMode;
    }
    
    //
    void ApplicationSettingsComponent::SetWindowStyle(std::uint32_t style) {
        windowStyle = style;
    }
    
    //
    std::uint32_t &ApplicationSettingsComponent::GetWindowStyle() {
        return windowStyle;
    }
    
    //
    void ApplicationSettingsComponent::SetWindowState(sf::State &state) {
        windowState = state;
    }
    
    //
    void ApplicationSettingsComponent::SetWindowState(sf::State &&state) {
        windowState = state;
    }
    
    //
    sf::State &ApplicationSettingsComponent::GetWindowState() {
        return windowState;
    }
    
    //
    void ApplicationSettingsComponent::SetWindowSettings(sf::VideoMode &mode, std::string &title, std::uint32_t &style, sf::State &state) {
        windowMode = mode;
        windowTitle = title;
        windowStyle = style;
        windowState = state;
    }
        
    //
    void ApplicationSettingsComponent::SetWindowSettings(sf::VideoMode &&mode, std::string &&title, std::uint32_t &&style, sf::State &&state) {
        windowMode = mode;
        windowTitle = title;
        windowStyle = style;
        windowState = state;
    }
}