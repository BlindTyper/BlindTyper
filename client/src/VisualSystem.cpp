/*

*/

#include <VisualSystem.hpp>

namespace tppo {
    //
    VisualSystem::VisualSystem(ComponentManager &componentManager, EntityManager &entityManager) 
        : System(componentManager, entityManager){
        
    }
    
    //
    VisualSystem::~VisualSystem() {
        
    }
    
    //
    void VisualSystem::Init() {
        
        // Загрузка текстур
        std::vector<std::string> textureFileNames = {
            "../data/mainMenuBackground.png"
        };
        
        auto &visualResources = entityManager.GetSystemResources().GetVisualResources();
        
        for (auto &it : textureFileNames) {
            visualResources.AddTexture(it);
        }
        
        // Загрузка шрифтов
        ImFontConfig font_cfg;
        static const ImWchar CyrillicRanges[] = {
            0x0010, 0x04FF,
            0x0500, 0x052F,
            0x2DE0, 0x2DFF,
            0xA640, 0xA69F,
            0
        };
        ImGuiIO &io = ImGui::GetIO();
        font_cfg.GlyphRanges = CyrillicRanges;
        io.Fonts->Clear();
        // io->Fonts->AddFontDefault();
        io.Fonts->AddFontFromFileTTF("../data/arial.ttf", 24.0f, &font_cfg);
        io.Fonts->AddFontFromFileTTF("../data/arial.ttf", 80.0f, &font_cfg);
        io.Fonts->AddFontFromFileTTF("../data/arial.ttf", 120.0f, &font_cfg);
        io.Fonts->AddFontFromFileTTF("../data/arial.ttf", 64.0f, &font_cfg);
        io.Fonts->AddFontFromFileTTF("../data/arial.ttf", 48.0f, &font_cfg);
        io.Fonts->AddFontFromFileTTF("../data/arial.ttf", 32.0f, &font_cfg);
        io.Fonts->AddFontFromFileTTF("../data/arial.ttf", 16.0f, &font_cfg);
        (void) ImGui::SFML::UpdateFontTexture();
    }
    
    //
    void VisualSystem::Update() {
        auto visualComponents = componentManager.GetVisualComponents();
        for (auto &it : visualComponents) {
            
        }
    }
}