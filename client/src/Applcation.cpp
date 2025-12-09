/*

*/

#include <Application.hpp>

namespace tppo {
    //
    Application::Application()
        : componentManager()
        , entityManager(componentManager) 
        , systemManager(componentManager, entityManager) 
        , currentScreen(mainMenu) 
        , window(sf::VideoMode({1920, 1080}), L"Blind Typer"/*, sf::State::Fullscreen*/)
        , window_flags(0)
        , p_open(false)
        , deltaClock() {
        Init();
    }
    
    //
    Application::~Application() {
        
    }
    
    //
    void Application::Init() {
        // Запуск графики
        ImGui::CreateContext();
        ImGui::StyleColorsDark();
        (void) ImGui::SFML::Init(window, false);
        
        systemManager.Init();
        window.setFramerateLimit(60);
        window.setVerticalSyncEnabled(true);
        
        
        
        
        
    // Fonts style
        

    // window flags
        window_flags |= ImGuiWindowFlags_NoBackground;
        window_flags |= ImGuiWindowFlags_NoCollapse;
        window_flags |= ImGuiWindowFlags_NoMove;
        window_flags |= ImGuiWindowFlags_NoNav;
        window_flags |= ImGuiWindowFlags_NoScrollbar;
        window_flags |= ImGuiWindowFlags_NoResize;
    }
    
    //
    void Application::Run() {
        ImGuiIO* io = &ImGui::GetIO();
        sf::Sprite imageBackground(entityManager.GetSystemResources().GetVisualResources().GetTexture("../data/mainMenuBackground.png"));
        
        imageBackground.setPosition({0, 0});
        imageBackground.setScale({0.697f, 0.703f});
        while (window.isOpen()) {
            while (const auto event = window.pollEvent()) {
                ImGui::SFML::ProcessEvent(window, *event);

                if (event->is<sf::Event::Closed>()) {
                    window.close();
                }
            }

            ImGui::SFML::Update(window, deltaClock.restart());

            window.clear();

            // ImGui::ShowDemoWindow();
    // parametrs for fullscreen
            const ImGuiViewport* viewport = ImGui::GetMainViewport();
            ImGui::SetNextWindowPos(viewport->WorkPos);
            ImGui::SetNextWindowSize(viewport->WorkSize);
            
            ImGui::Begin("Blind Typer", &p_open, window_flags);

            switch (currentScreen) {
                case mainMenu: {
                    showMainMenu(io->Fonts, viewport, imageBackground);
                    break;
                }
                case campaignMenu: {
                    showCampaignMenu(io->Fonts, viewport, imageBackground);
                    break;
                }
                case endlessModeMenu: {}
                case onlineGameMenu: {}
                case lobbyMenuPlayer: {}
                case lobbyMenuHost: {}
                case lobbyMenuHostLobbySettings: {}
                case applicationSettingsMenu: {}
                case profileMenu: {}
                case profileRegistrationMenu: {}
                case profileAuthorizationMenu: {}
                case gameMenu: {}
                case pauseMenu: {}
                default: {
                    if (ImGui::Button("Назад")) {
                        currentScreen = mainMenu;
                    }
                    break;
                }
            }

            ImGui::End();
            window.draw(imageBackground);
            ImGui::SFML::Render(window);
            window.display();
        }

        ImGui::SFML::Shutdown();
    }
    
    void Application::showMainMenu(ImFontAtlas *Fonts, const ImGuiViewport* viewport, sf::Sprite &imageBackground) {
        ImVec2 next_pos = viewport->WorkSize;
        ImVec2 next_scale = viewport->WorkSize;
        ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 3.0f);
        ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, std::min(next_scale.y / 3.0f, next_scale.x / 3.0f));
        ImGui::PushFont(Fonts->Fonts[1]);
        //sf::Sprite imageBackground(entityManager.GetSystemResources().GetVisualResources().GetTexture("../data/mainMenuBackground.png"));
        imageBackground.setPosition({0, 0});
        imageBackground.setScale({0.697f, 0.703f});
//        ImTextureID my_tex_id = backgroundImage.getNativeHandle();
//        float my_tex_w = (float)Fonts->TexWidth;
//        float my_tex_h = (float)Fonts->TexHeight;
        
        ImGui::PushFont(Fonts->Fonts[2]);
        ImVec2 size = ImGui::CalcTextSize("Blind Typer");
        ImVec2 pos = ImVec2(next_pos.x / 2.0f - size.x * 0.5f, next_pos.y / 4.0f - size.y / 2.0f);
        ImGui::SetCursorPos(pos);
        ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.0f, 0.0f, 0.0f, 1.0f));
        ImGui::Text("Blind Typer");
        ImGui::PopFont();
        ImGui::PopStyleColor();

        size = ImVec2(next_scale.x / 4, next_scale.y / 10 * 1.5f);
        pos = ImVec2(next_pos.x / 2.0f - size.x * 1.8f, next_pos.y / 2.0f - size.y / 2.0f);
        ImGui::SetCursorPos(pos);
        if (ImGui::Button("Кампания", size)) {
            currentScreen = campaignMenu;
        }

        size = ImVec2(next_scale.x / 4, next_scale.y / 10 * 1.5f);
        pos = ImVec2(next_pos.x / 2.0f - size.x * 0.5f, next_pos.y / 2.0f - size.y / 2.0f);
        ImGui::SetCursorPos(pos);
        if (ImGui::Button("Бесконечный", size)) {
            currentScreen = endlessModeMenu;
        }

        size = ImVec2(next_scale.x / 4, next_scale.y / 10 * 1.5f);
        pos = ImVec2(next_pos.x / 2.0f + size.x * 0.8f, next_pos.y / 2.0f - size.y / 2.0f);
        ImGui::SetCursorPos(pos);
        if (ImGui::Button("Сетевая", size)) {
            currentScreen = onlineGameMenu;
        }

        size = ImVec2(next_scale.x / 4, next_scale.y / 10 * 1.5f);
        pos = ImVec2(next_pos.x / 2.0f - size.x * 1.8f, next_pos.y / 4.0f * 3.0f - size.y / 2.0f);
        ImGui::SetCursorPos(pos);
        if (ImGui::Button("Настройки", size)) {
            currentScreen = applicationSettingsMenu;
        }

        size = ImVec2(next_scale.x / 4, next_scale.y / 10 * 1.5f);
        pos = ImVec2(next_pos.x / 2.0f - size.x * 0.5f, next_pos.y / 4.0f * 3.0f - size.y / 2.0f);
        ImGui::SetCursorPos(pos);
        if (ImGui::Button("Профиль", size)) {
            currentScreen = profileMenu;
        }

        size = ImVec2(next_scale.x / 4, next_scale.y / 10 * 1.5f);
        pos = ImVec2(next_pos.x / 2.0f + size.x * 0.8f, next_pos.y / 4.0f * 3.0f - size.y / 2.0f);
        ImGui::SetCursorPos(pos);
        if (ImGui::Button("Выход", size)) {
            exit(0);
        }

        ImGui::PopFont();
        ImGui::PopStyleVar(2);

    }

    void Application::showCampaignMenu(ImFontAtlas *Fonts, const ImGuiViewport* viewport, sf::Sprite &imageBackground) {
        ImVec2 next_pos = viewport->WorkSize;
        ImVec2 next_scale = viewport->WorkSize;
        ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 3.0f);
        ImGui::PushFont(Fonts->Fonts[1]);
        //sf::Sprite imageBackground(entityManager.GetSystemResources().GetVisualResources().GetTexture("../data/mainMenuBackground.png"));
        imageBackground.setPosition({0, 0});
        imageBackground.setScale({0.697f, 0.703f});
//        ImTextureID my_tex_id = backgroundImage.getNativeHandle();
//        float my_tex_w = (float)Fonts->TexWidth;
//        float my_tex_h = (float)Fonts->TexHeight;

        ImGui::PushFont(Fonts->Fonts[2]);
        ImVec2 size = ImGui::CalcTextSize("Кампания");
        ImVec2 pos = ImVec2(next_pos.x / 2.0f - size.x * 0.5f, next_pos.y / 4.0f - size.y / 2.0f);
        ImGui::SetCursorPos(pos);
        ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.0f, 0.0f, 0.0f, 1.0f));
        ImGui::Text("Кампания");
        ImGui::PopStyleColor();
        ImGui::PopFont();

        size = ImGui::CalcTextSize("Назад");
        pos = ImVec2(size.x / 3.0f, size.y);
        ImGui::SetCursorPos(pos);
        ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, std::min(size.y / 3.0f, size.x / 3.0f));
        if (ImGui::Button("Назад")) {
            currentScreen = mainMenu;
        }
        ImGui::PopStyleVar();
        
        size = ImVec2(next_scale.x / 4 * 1.5f, next_scale.y / 2);
        pos = ImVec2(next_scale.x / 4 - size.x / 2.0f, next_scale.y / 4.0f * 2.5f - size.y / 2.0f);
        ImGui::SetCursorPos(pos);
        ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, std::min(size.y / 3.0f, size.x / 3.0f));
        ImGui::Button("Глава I\n\"Обучение\"", size);
        ImGui::PopStyleVar();

        size = ImVec2(next_scale.x / 4 * 1.5f, next_scale.y / 2);
        pos = ImVec2(next_scale.x / 4 * 3 - size.x / 2.0f, next_scale.y / 4.0f * 2.5f - size.y / 2.0f);
        ImGui::SetCursorPos(pos);
        ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, std::min(size.y / 3.0f, size.x / 3.0f));
        ImGui::Button("Глава II\n\"as df\"", size);
        ImGui::PopStyleVar();
        
        ImGui::PopFont();
        ImGui::PopStyleVar();
    }
}