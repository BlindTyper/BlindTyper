/*

*/

#include "VisualSystem.hpp"

namespace tppo {
    //
    VisualSystem::VisualSystem(ComponentManager &componentManager, EntityManager &entityManager) 
        : System(componentManager, entityManager)
    {
        
    }
    
    //
    VisualSystem::~VisualSystem() {
        
    }
    
    //
    void VisualSystem::Init() {
        // Запуск графики
        auto &settings = entityManager.GetSystemResources()->GetSettings();
        auto &window = entityManager.GetSystemResources()->GetWindow();
        auto &visualResources = entityManager.GetSystemResources()->GetVisualResources();
        
        settings.SetWindowSettings(sf::VideoMode({1920, 1080}), "Blind Typer", sf::Style::Default, sf::State::Windowed);
        settings.SetWindowFlags(
            ImGuiWindowFlags_NoBackground
            | ImGuiWindowFlags_NoCollapse
            | ImGuiWindowFlags_NoMove
            | ImGuiWindowFlags_NoNav
            | ImGuiWindowFlags_NoScrollbar
            | ImGuiWindowFlags_NoResize
            | ImGuiWindowFlags_NoTitleBar
        );
        window.CreateWindow(
            settings.GetWindowVideoMode(),
            settings.GetWindowTitle(),
            settings.GetWindowStyle(),
            settings.GetWindowState()
        );
        window.SetFramerateLimit(60);
        window.SetVerticalSyncEnabled(1);
        
        ImGui::CreateContext();
        ImGui::StyleColorsDark();
        (void) ImGui::SFML::Init(window.GetWindow(), false);
        
        
        // Загрузка текстур
        std::vector<std::string> textureFileNames = {
            "../data/mainMenuBackground.png"
        };
        
        for (auto &it : textureFileNames) {
            visualResources.AddTexture(it);
        }
        
        
        // Загрузка шрифтов
        auto &fontConfig = visualResources.GetFontConfig();
        static const ImWchar CyrillicRanges[] = {
            0x0010, 0x04FF,
            0x0500, 0x052F,
            0x2DE0, 0x2DFF,
            0xA640, 0xA69F,
            0
        };
        ImGuiIO &io = ImGui::GetIO();
        fontConfig.GlyphRanges = CyrillicRanges;
        io.Fonts->Clear();
        // io->Fonts->AddFontDefault();
        io.Fonts->AddFontFromFileTTF("../data/arial.ttf", 24.0f, &fontConfig);
        io.Fonts->AddFontFromFileTTF("../data/arial.ttf", 80.0f, &fontConfig);
        io.Fonts->AddFontFromFileTTF("../data/arial.ttf", 120.0f, &fontConfig);
        io.Fonts->AddFontFromFileTTF("../data/arial.ttf", 64.0f, &fontConfig);
        io.Fonts->AddFontFromFileTTF("../data/arial.ttf", 48.0f, &fontConfig);
        io.Fonts->AddFontFromFileTTF("../data/arial.ttf", 32.0f, &fontConfig);
        io.Fonts->AddFontFromFileTTF("../data/arial.ttf", 16.0f, &fontConfig);
        (void) ImGui::SFML::UpdateFontTexture();
    }
    
    //
    void VisualSystem::Update() {
        auto &settings = entityManager.GetSystemResources()->GetSettings();
        auto &window = entityManager.GetSystemResources()->GetWindow();
        
        ImGuiIO &io = ImGui::GetIO();
        
        while (const auto event = window.GetWindow().pollEvent()) {
            ImGui::SFML::ProcessEvent(window.GetWindow(), *event);

            if (event->is<sf::Event::Closed>()) {
                window.Close();
            }
        }

        ImGui::SFML::Update(window.GetWindow(), window.GetClock().restart());

        window.Clear();
        
        auto visualComponents = componentManager.GetVisualComponents();
        for (auto &it : visualComponents) {
            window.Draw(it.second->GetSprite());
        }
        
        const ImGuiViewport &viewport = *ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(viewport.WorkPos);
        ImGui::SetNextWindowSize(viewport.WorkSize);
        ImVec2 next_pos = viewport.WorkSize;
        ImVec2 next_scale = viewport.WorkSize;
        
        ImGui::Begin("Blind Typer", &settings.GetOpenFlag(), settings.GetWindowFlags());
        
        auto labels = entityManager.GetLabels();
        for (auto &it : labels) {
            if (!it.second->GetUI()->IsVisible()) {
                continue;
            }
            ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 3.0f);
            ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, std::min(next_scale.y / 3.0f, next_scale.x / 3.0f));
            ImGui::PushFont(io.Fonts->Fonts[1]);
            ImGui::PushStyleColor(
                ImGuiCol_Text, 
                ImVec4(
                    it.second->GetUI()->GetTextColor().x,
                    it.second->GetUI()->GetTextColor().y,
                    it.second->GetUI()->GetTextColor().z,
                    1.0f
                )
            );
            ImVec2 size = ImVec2(
                it.second->GetTransform()->GetSize().x * next_scale.x, 
                it.second->GetTransform()->GetSize().y * next_scale.y
            );
            ImVec2 pos = ImVec2(
                it.second->GetTransform()->GetPosition().x * next_pos.x, 
                it.second->GetTransform()->GetPosition().y * next_pos.y
            );
            const char *text = it.second->GetUI()->GetText().c_str();
            ImGui::SetCursorPos(pos);
            ImGui::Text(text, size);
            ImGui::PopStyleColor();
            ImGui::PopFont();
            ImGui::PopStyleVar(2);
        }
        
        auto buttons = entityManager.GetButtons();
        for (auto &it : buttons) {
            if (!it.second->GetUI()->IsVisible()) {
                continue;
            }
            ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 3.0f);
            ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, std::min(next_scale.y / 3.0f, next_scale.x / 3.0f));
            ImGui::PushFont(io.Fonts->Fonts[1]);
            ImGui::PushStyleColor(
                ImGuiCol_Text, 
                ImVec4(
                    it.second->GetUI()->GetTextColor().x,
                    it.second->GetUI()->GetTextColor().y,
                    it.second->GetUI()->GetTextColor().z,
                    1.0f
                )
            );
            ImVec2 size = ImVec2(
                it.second->GetTransform()->GetSize().x * next_scale.x, 
                it.second->GetTransform()->GetSize().y * next_scale.y
            );
            ImVec2 pos = ImVec2(
                it.second->GetTransform()->GetPosition().x * next_pos.x, 
                it.second->GetTransform()->GetPosition().y * next_pos.y
            );
            const char *text = it.second->GetUI()->GetText().c_str();
            ImGui::SetCursorPos(pos);
            if (ImGui::Button(text, size)) {
                std::function<void()> call = it.second->GetUI()->GetOnClick();
                call();
            }
            ImGui::PopStyleColor();
            ImGui::PopFont();
            ImGui::PopStyleVar(2);
        }
        
//        switch (currentScreen) {
//            case mainMenu: {
//                break;
//            }
//            case campaignMenu: {
//                //showCampaignMenu(io->Fonts, viewport, imageBackground);
//                ImVec2 next_pos = viewport->WorkSize;
//                ImVec2 next_scale = viewport->WorkSize;
//                ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 3.0f);
//                ImGui::PushFont(io.Fonts->Fonts[1]);
//        //        ImTextureID my_tex_id = backgroundImage.getNativeHandle();
//        //        float my_tex_w = (float)Fonts->TexWidth;
//        //        float my_tex_h = (float)Fonts->TexHeight;
//
//                ImGui::PushFont(io.Fonts->Fonts[2]);
//                ImVec2 size = ImGui::CalcTextSize("Кампания");
//                ImVec2 pos = ImVec2(next_pos.x / 2.0f - size.x * 0.5f, next_pos.y / 4.0f - size.y / 2.0f);
//                ImGui::SetCursorPos(pos);
//                ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.0f, 0.0f, 0.0f, 1.0f));
//                ImGui::Text("Кампания");
//                ImGui::PopStyleColor();
//                ImGui::PopFont();
//
//                size = ImGui::CalcTextSize("Назад");
//                pos = ImVec2(size.x / 3.0f, size.y);
//                ImGui::SetCursorPos(pos);
//                ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, std::min(size.y / 3.0f, size.x / 3.0f));
//                if (ImGui::Button("Назад")) {
//                    currentScreen = mainMenu;
//                }
//                ImGui::PopStyleVar();
//                
//                size = ImVec2(next_scale.x / 4 * 1.5f, next_scale.y / 2);
//                pos = ImVec2(next_scale.x / 4 - size.x / 2.0f, next_scale.y / 4.0f * 2.5f - size.y / 2.0f);
//                ImGui::SetCursorPos(pos);
//                ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, std::min(size.y / 3.0f, size.x / 3.0f));
//                ImGui::Button("Глава I\n\"Обучение\"", size);
//                ImGui::PopStyleVar();
//
//                size = ImVec2(next_scale.x / 4 * 1.5f, next_scale.y / 2);
//                pos = ImVec2(next_scale.x / 4 * 3 - size.x / 2.0f, next_scale.y / 4.0f * 2.5f - size.y / 2.0f);
//                ImGui::SetCursorPos(pos);
//                ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, std::min(size.y / 3.0f, size.x / 3.0f));
//                ImGui::Button("Глава II\n\"as df\"", size);
//                ImGui::PopStyleVar();
//                
//                ImGui::PopFont();
//                ImGui::PopStyleVar();
//                break;
//            }
//            case endlessModeMenu: {}
//            case onlineGameMenu: {}
//            case lobbyMenuPlayer: {}
//            case lobbyMenuHost: {}
//            case lobbyMenuHostLobbySettings: {}
//            case applicationSettingsMenu: {}
//            case profileMenu: {}
//            case profileRegistrationMenu: {}
//            case profileAuthorizationMenu: {}
//            case gameMenu: {}
//            case pauseMenu: {}
//            default: {
//                if (ImGui::Button("Назад")) {
//                    currentScreen = mainMenu;
//                }
//                break;
//            }
//        }

        ImGui::End();
        ImGui::SFML::Render(window.GetWindow());
        window.Display();
    }
}