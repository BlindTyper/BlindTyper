/*

*/

#include <Application.hpp>

namespace tppo {
    //
    Application::Application()
        : componentManager()
        , entityManager(componentManager) 
        , systemManager(componentManager, entityManager)
    {
        Init();
    }
    
    //
    Application::~Application() {
        
    }
    
    //
    void Application::Init() {
        systemManager.Init();
    }
    
    //
    void Application::Run() {
        while (systemManager.IsRunning()) {
            systemManager.Update();
        }

        ImGui::SFML::Shutdown();
    }
}