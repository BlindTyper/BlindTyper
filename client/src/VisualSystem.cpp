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
        std::vector<std::pair<char, std::string>> textureFileNames = {
            {0, "../data/mainMenuBackground.png"},
            {0, "../data/floor.png"},
            {'a', "../data/a_glyph.png"},
            {'b', "../data/b_glyph.png"},
            {'c', "../data/c_glyph.png"},
            {'d', "../data/d_glyph.png"},
            {'e', "../data/e_glyph.png"},
            {'f', "../data/f_glyph.png"},
            {'g', "../data/g_glyph.png"},
            {'h', "../data/h_glyph.png"},
            {'i', "../data/i_glyph.png"},
            {'j', "../data/j_glyph.png"},
            {'k', "../data/k_glyph.png"},
            {'l', "../data/l_glyph.png"},
            {'m', "../data/m_glyph.png"},
            {'n', "../data/n_glyph.png"},
            {'o', "../data/o_glyph.png"},
            {'p', "../data/p_glyph.png"},
            {'q', "../data/q_glyph.png"},
            {'r', "../data/r_glyph.png"},
            {'s', "../data/s_glyph.png"},
            {'t', "../data/t_glyph.png"},
            {'u', "../data/u_glyph.png"},
            {'v', "../data/v_glyph.png"},
            {'w', "../data/w_glyph.png"},
            {'x', "../data/x_glyph.png"},
            {'y', "../data/y_glyph.png"},
            {'z', "../data/z_glyph.png"},
        };
        
        for (auto &[key, str] : textureFileNames) {
            visualResources.AddTexture(str);
            if (key != 0) {
                visualResources.AddCharToTextureName(key, str);
            }
        }
        
        
        // Загрузка шрифтов
        auto &fontConfig = visualResources.GetFontConfig();
        static const ImWchar CyrillicRanges[] = {
            0x0010, 0x04FF,
            0x0500, 0x052F,
            0x2000, 0x2500,
//            0x2DE0, 0x2DFF,
//            0xA640, 0xA69F,
            0
        };
        ImGuiIO &io = ImGui::GetIO();
        fontConfig.GlyphRanges = CyrillicRanges;
        io.Fonts->Clear();
        // io->Fonts->AddFontDefault();
        std::string arialFontName = "../data/arial.ttf";
        const std::uint64_t fontSizesCount = 6;
        std::array<std::uint64_t, fontSizesCount> fontSizes = {16, 24, 32, 48, 64, 80};
        for (std::uint64_t i = 0; i < fontSizesCount; i++) {
            visualResources.AddFont(arialFontName, fontSizes[i]);
        }
        (void) ImGui::SFML::UpdateFontTexture();
    }
    
    //
    void VisualSystem::Update() {
        auto &settings = entityManager.GetSystemResources()->GetSettings();
        auto &window = entityManager.GetSystemResources()->GetWindow();
        auto &visualResources = entityManager.GetSystemResources()->GetVisualResources();
        
        ImGuiIO &io = ImGui::GetIO();
        
        while (const auto event = window.GetWindow().pollEvent()) {
            ImGui::SFML::ProcessEvent(window.GetWindow(), *event);

            if (event->is<sf::Event::Closed>()) {
                window.Close();
            }
            if (const auto *resized = event->getIf<sf::Event::Resized>()) {
                sf::FloatRect visibleArea({0.f, 0.f}, sf::Vector2f(resized->size));
                window.GetWindow().setView(sf::View(visibleArea));
            }
        }

        ImGui::SFML::Update(window.GetWindow(), window.GetClock().restart());

        window.Clear();
        
        
        
        const ImGuiViewport &viewport = *ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(viewport.WorkPos);
        ImGui::SetNextWindowSize(viewport.WorkSize);
        ImVec2 workSize = viewport.WorkSize;
        
        ImGui::Begin("Blind Typer", &settings.GetOpenFlag(), settings.GetWindowFlags());
        
        //
        auto &displayOrder = componentManager.GetDisplayOrder();
        for (auto &[order, id] : displayOrder) {
            auto &visual = componentManager.GetVisualComponent(id);
            if (visual->IsVisible()) {
                sf::RenderStates states;
                if (componentManager.HasTransformComponent(id)) {
                    auto &transform = componentManager.GetTransformComponent(id);
                    
                    
                    states.transform.translate(
                        sf::Vector2f(
                            transform->GetPosition().x * workSize.x, 
                            transform->GetPosition().y * workSize.y
                        )
                    );
                    
                    states.transform.scale(
                        sf::Vector2f(
                            transform->GetSize().x * (workSize.x
                                / static_cast<long double>(visual->GetSprite().getTextureRect().size.x)), 
                            transform->GetSize().y * (workSize.y 
                                / static_cast<long double>(visual->GetSprite().getTextureRect().size.y))
                        )
                    );
                }
//                auto &sprite = visual->GetSprite();
//                if (componentManager.HasTransformComponent(id)) {
//                    auto &transform = componentManager.GetTransformComponent(id);
//                    
//                    sprite.setScale(
//                        sf::Vector2f(
//                            transform->GetSize().x * , 
//                            transform->GetSize().y
//                        )
//                    );
//                    sprite.setPosition(
//                        sf::Vector2f(
//                            transform->GetPosition().x * workSize.x, 
//                            transform->GetPosition().y * workSize.y
//                        )
//                    );
//                }
                
                //std::cout << id << std::endl;
                window.Draw(visual->GetSprite(), states);
            }
        }
        //std::cout << "viewport: " << viewport.WorkSize.x << " x " << viewport.WorkSize.y << std::endl;
        //std::cout << "new tick: " << std::endl;
        
        
        
        //
        auto uis = componentManager.GetUIComponents();
        for (auto &[key, ui] : uis) {
            if (!ui->IsVisible()) {
                continue;
            }
            auto &transform = componentManager.GetTransformComponent(key);
            ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 3.0f);
            ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, std::min(workSize.y / 3.0f, workSize.x / 3.0f));
            std::uint64_t fontNum = visualResources.GetFontNum(ui->GetFontSize());
            ImGui::PushFont(io.Fonts->Fonts[fontNum]);
            ImGui::PushStyleColor(
                ImGuiCol_Text, 
                ImVec4(
                    ui->GetTextColor().x,
                    ui->GetTextColor().y,
                    ui->GetTextColor().z,
                    1.0f
                )
            );
            ImVec2 size = ImVec2(
                transform->GetSize().x * workSize.x, 
                transform->GetSize().y * workSize.y
            );
            ImVec2 pos = ImVec2(
                transform->GetPosition().x * workSize.x, 
                transform->GetPosition().y * workSize.y
            );
            std::string text = ui->GetText();
            ImGui::SetCursorPos(pos);
            if (ui->GetType() == UIComponent::Type::label) {
//                if (ui->GetTrackedData1() != nullptr)
//                    text += std::format("{:.0f}", static_cast<long double>(*(static_cast<std::uint64_t *>(ui->GetTrackedData1()))));
                ImGui::Text(text.c_str(), size);
            } else if (ui->GetType() == UIComponent::Type::button) {
                if (ui->GetTrackedData() != nullptr)
                    text += (ui->GetTrackedData())();
                if (ImGui::Button(text.c_str(), size)) {
                    std::function<void()> call = ui->GetOnClick();
                    call();
                }
            } else if (ui->GetType() == UIComponent::Type::progressBar) {
                if (ui->GetTrackedData() != nullptr) {
                    long double progress = std::stold((ui->GetTrackedData())());
                    //text += (ui->GetTrackedData())();
                    ImGui::ProgressBar(progress, size, text.c_str());
                }
                else {
                    ImGui::ProgressBar(1.0f, size, text.c_str());
                }
            }
            ImGui::PopStyleColor();
            ImGui::PopFont();
            ImGui::PopStyleVar(2);
        }

        ImGui::End();
        ImGui::SFML::Render(window.GetWindow());
        window.Display();
    }
}