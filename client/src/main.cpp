#include "imgui.h"
#include "imgui-SFML.h"

#include <SFML/Graphics.hpp>

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

Screens currentScreen = mainMenu;

void showMainMenu(ImFontAtlas *Fonts, const ImGuiViewport* viewport);
void showCampaignMenu(ImFontAtlas *Fonts, const ImGuiViewport* viewport);

int main() {
// Window create
    sf::RenderWindow window(sf::VideoMode({1920, 1080}), L"Blind Typer", sf::State::Fullscreen);
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
    
    ImGui::CreateContext();
    ImGui::StyleColorsDark();
    (void) ImGui::SFML::Init(window, false);
    
    static const ImWchar CyrillicRanges[] = {
        0x0010, 0x04FF,
        0x0500, 0x052F,
        0x2DE0, 0x2DFF,
        0xA640, 0xA69F,
        0,
    };
    
// Settings for Cyrillic font???
    ImGuiIO& io = ImGui::GetIO();
    ImFontConfig font_cfg;
    font_cfg.GlyphRanges = CyrillicRanges;
    
// Fonts style
    io.Fonts->Clear();
    // io.Fonts->AddFontDefault();
    io.Fonts->AddFontFromFileTTF("../data/arial.ttf", 24.0f, &font_cfg);
    io.Fonts->AddFontFromFileTTF("../data/arial.ttf", 80.0f, &font_cfg);
    io.Fonts->AddFontFromFileTTF("../data/arial.ttf", 120.0f, &font_cfg);
    io.Fonts->AddFontFromFileTTF("../data/arial.ttf", 64.0f, &font_cfg);
    io.Fonts->AddFontFromFileTTF("../data/arial.ttf", 48.0f, &font_cfg);
    io.Fonts->AddFontFromFileTTF("../data/arial.ttf", 32.0f, &font_cfg);
    io.Fonts->AddFontFromFileTTF("../data/arial.ttf", 16.0f, &font_cfg);
    (void) ImGui::SFML::UpdateFontTexture();

// window flags
    ImGuiWindowFlags window_flags = 0;
    window_flags |= ImGuiWindowFlags_NoBackground;
    window_flags |= ImGuiWindowFlags_NoCollapse;
    window_flags |= ImGuiWindowFlags_NoMove;
    window_flags |= ImGuiWindowFlags_NoNav;
    window_flags |= ImGuiWindowFlags_NoScrollbar;
    window_flags |= ImGuiWindowFlags_NoResize;
    
// Create Background
    auto windowSize = window.getSize();
    sf::Texture backgroundImage("../data/backgroundMainMenu.png");
    sf::Sprite imageBackground(backgroundImage);
    imageBackground.setPosition({0, 0});
    imageBackground.setScale({0.697f, 0.703f});
    
    bool *p_open;
    static bool use_work_area = true;


// Main cycle that draw window
    sf::Clock deltaClock;
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
        
        ImGui::Begin("Blind Typer", p_open, window_flags);

        switch (currentScreen) {
            case mainMenu: {
                showMainMenu(io.Fonts, viewport);
                break;
            }
            case campaignMenu: {
                showCampaignMenu(io.Fonts, viewport);
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

void showMainMenu(ImFontAtlas *Fonts, const ImGuiViewport* viewport){
    ImVec2 next_pos = viewport->WorkSize;
    ImVec2 next_scale = viewport->WorkSize;
    ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 3.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, std::min(next_scale.y / 3.0f, next_scale.x / 3.0f));
    ImGui::PushFont(Fonts->Fonts[1]);
    sf::Texture backgroundImage("../data/backgroundMainMenu.png");
    sf::Sprite imageBackground(backgroundImage);
    imageBackground.setPosition({0, 0});
    imageBackground.setScale({0.697f, 0.703f});
    ImTextureID my_tex_id = backgroundImage.getNativeHandle();
    float my_tex_w = (float)Fonts->TexWidth;
    float my_tex_h = (float)Fonts->TexHeight;
    
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

void showCampaignMenu(ImFontAtlas *Fonts, const ImGuiViewport* viewport) {
    ImVec2 next_pos = viewport->WorkSize;
    ImVec2 next_scale = viewport->WorkSize;
    ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 3.0f);
    ImGui::PushFont(Fonts->Fonts[1]);
    sf::Texture backgroundImage("../data/backgroundMainMenu.png");
    sf::Sprite imageBackground(backgroundImage);
    imageBackground.setPosition({0, 0});
    imageBackground.setScale({0.697f, 0.703f});
    ImTextureID my_tex_id = backgroundImage.getNativeHandle();
    float my_tex_w = (float)Fonts->TexWidth;
    float my_tex_h = (float)Fonts->TexHeight;

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