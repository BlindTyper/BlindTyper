/*

*/

#include "StateSystem.hpp"

namespace tppo {
    //
    StateSystem::StateSystem(ComponentManager &componentManager, EntityManager &entityManager)
        : System(componentManager, entityManager) {
        
    }
    
    //
    StateSystem::~StateSystem() {
        
    }
    
    //
    void StateSystem::Init() {
        MainMenuInit();
        SoloGameMenuInit();
        InSoloGameInit();
        SoloGameResultsInit();
        
        MainMenuState();
    }
    
    //
    void StateSystem::Update() {
        
    }
    
    //
    void StateSystem::MainMenuInit() {
        // Добавление нового состояния приложения
        auto state = entityManager.AddApplicationState("MainMenuState");
        
        // Добавление фона
        state->LinkEntityToState(
            entityManager.AddBackground("../data/mainMenuBackground.png")->GetId()
        );
        
        // Добавление текстового поля
        state->LinkEntityToState(
            entityManager.AddLabel(
                UIComponent::Type::label,
                "Blind Typer",
                nullptr,
                nullptr,
                Vec3d(0.f, 0.f, 0.f),
                false,
                [](){}, 
                Vec3d(0.4f, 0.2f), 
                Vec3d(0.28f, 0.15f)
            )->GetId()
        );
        
        // Добавление кнопок
        state->LinkEntityToState(
            entityManager.AddButton(
                UIComponent::Type::button,
                "Кампания", 
                nullptr,
                nullptr,
                Vec3d(1.0f, 1.0f, 1.0f),
                false,
                [&](){SoloGameMenuState();}, 
                Vec3d(0.02f, 0.4f), 
                Vec3d(0.28f, 0.15f)
            )->GetId()
        );
        
        state->LinkEntityToState(
            entityManager.AddButton(
                UIComponent::Type::button,
                "Бесконечный", 
                nullptr,
                nullptr,
                Vec3d(1.0f, 1.0f, 1.0f),
                false,
                [&](){}, 
                Vec3d(0.36f, 0.4f), 
                Vec3d(0.28f, 0.15f)
            )->GetId()
        );
        
        state->LinkEntityToState(
            entityManager.AddButton(
                UIComponent::Type::button,
                "Сетевой", 
                nullptr,
                nullptr,
                Vec3d(1.0f, 1.0f, 1.0f),
                false,
                [&](){}, 
                Vec3d(0.7f, 0.4f), 
                Vec3d(0.28f, 0.15f)
            )->GetId()
        );
        
        state->LinkEntityToState(
            entityManager.AddButton(
                UIComponent::Type::button,
                "Профиль", 
                nullptr,
                nullptr,
                Vec3d(1.0f, 1.0f, 1.0f),
                false,
                [&](){}, 
                Vec3d(0.02f, 0.7f), 
                Vec3d(0.28f, 0.15f)
            )->GetId()
        );
        
        state->LinkEntityToState(
            entityManager.AddButton(
                UIComponent::Type::button,
                "Настройки", 
                nullptr,
                nullptr,
                Vec3d(1.0f, 1.0f, 1.0f),
                false,
                [&](){}, 
                Vec3d(0.36f, 0.7f), 
                Vec3d(0.28f, 0.15f)
            )->GetId()
        );
        
        state->LinkEntityToState(
            entityManager.AddButton(
                UIComponent::Type::button,
                "Выход", 
                nullptr,
                nullptr,
                Vec3d(1.0f, 1.0f, 1.0f),
                false,
                [](){exit(0);}, 
                Vec3d(0.7f, 0.7f), 
                Vec3d(0.28f, 0.15f)
            )->GetId()
        );
    }
    
    //
    void StateSystem::SoloGameMenuInit() {
        // Добавление нового состояния приложения
        auto state = entityManager.AddApplicationState("SoloGameMenuState");
        
        // Добавление фона
        state->LinkEntityToState(
            entityManager.AddBackground("../data/mainMenuBackground.png")->GetId()
        );
        
        // Добавление текстового поля
        state->LinkEntityToState(
            entityManager.AddLabel(
                UIComponent::Type::label,
                "Кампания", 
                nullptr,
                nullptr,
                Vec3d(0.f, 0.f, 0.f),
                false,
                [](){return;}, 
                Vec3d(0.4f, 0.2f), 
                Vec3d(0.28f, 0.15f)
            )->GetId()
        );
        
        // Добавление кнопок
        state->LinkEntityToState(
            entityManager.AddButton(
                UIComponent::Type::button,
                "Глава I\n\"Обучение\"", 
                nullptr,
                nullptr,
                Vec3d(1.0f, 1.0f, 1.0f),
                false,
                [&](){InSoloGameState();}, 
                Vec3d(0.02f, 0.4f), 
                Vec3d(0.28f, 0.15f)
            )->GetId()
        );
        
        state->LinkEntityToState(
            entityManager.AddButton(
                UIComponent::Type::button,
                "Глава II\n\"as df\"", 
                nullptr,
                nullptr,
                Vec3d(1.0f, 1.0f, 1.0f),
                false,
                [&](){}, 
                Vec3d(0.36f, 0.4f), 
                Vec3d(0.28f, 0.15f)
            )->GetId()
        );
        
        state->LinkEntityToState(
            entityManager.AddButton(
                UIComponent::Type::button,
                "Глава III", 
                nullptr,
                nullptr,
                Vec3d(1.0f, 1.0f, 1.0f),
                false,
                [&](){}, 
                Vec3d(0.7f, 0.4f), 
                Vec3d(0.28f, 0.15f)
            )->GetId()
        );
        
        state->LinkEntityToState(
            entityManager.AddButton(
                UIComponent::Type::button,
                "Глава IV", 
                nullptr,
                nullptr,
                Vec3d(1.0f, 1.0f, 1.0f),
                false,
                [&](){}, 
                Vec3d(0.02f, 0.7f), 
                Vec3d(0.28f, 0.15f)
            )->GetId()
        );
        
        state->LinkEntityToState(
            entityManager.AddButton(
                UIComponent::Type::button,
                "Глава V", 
                nullptr,
                nullptr,
                Vec3d(1.0f, 1.0f, 1.0f),
                false,
                [&](){}, 
                Vec3d(0.36f, 0.7f), 
                Vec3d(0.28f, 0.15f)
            )->GetId()
        );
        
        state->LinkEntityToState(
            entityManager.AddButton(
                UIComponent::Type::button,
                "Назад", 
                nullptr,
                nullptr,
                Vec3d(1.0f, 1.0f, 1.0f),
                false,
                [&](){MainMenuState();}, 
                Vec3d(0.7f, 0.7f), 
                Vec3d(0.28f, 0.15f)
            )->GetId()
        );
    }
    
    //
    void StateSystem::InSoloGameInit() {
        // Добавление нового состояния приложения
        auto state = entityManager.AddApplicationState("InSoloGameState");
        
        // Добавление фона
        state->LinkEntityToState(
            entityManager.AddBackground("../data/mainMenuBackground.png")->GetId()
        );
        
        // Добавление полосы здоровья
        state->LinkEntityToState(
            entityManager.AddHealthBar(
                UIComponent::Type::progressBar,
                " ", 
                nullptr,
                nullptr,
                Vec3d(1.0f, 1.0f, 1.0f),
                false,
                [&](){SoloGameMenuState();},
                Vec3d(0.15f, 0.0f), 
                Vec3d(0.7f, 0.05f)
            )->GetId()
        );
        
        // Добавление кнопок
        state->LinkEntityToState(
            entityManager.AddButton(
                UIComponent::Type::button,
                "≡", 
                nullptr,
                nullptr,
                Vec3d(1.0f, 1.0f, 1.0f),
                false,
                [&](){SoloGameMenuState();},
                Vec3d(0.0f, 0.0f), 
                Vec3d(0.10f, 0.15f)
            )->GetId()
        );
        
//        state->LinkEntityToState(
//            entityManager.AddButton(
//                UIComponent::Type::button,
//                "Добавить\nбукву", 
//                Vec3d(1.0f, 1.0f, 1.0f),
//                false,
//                [&](){
//                    std::uint64_t id = Entity::GetCounter();
//                    std::cout << entityManager.AddLetter(
//                        "../data/t_glyph.png",
//                        true,
//                        Vec3d(id * 0.01f, 0.0f),
//                        Vec3d(0.0f, 0.0f),
//                        Vec3d(1.0f, 1.0f),
//                        Vec3d(0.0f, 0.01f, 1.0f),
//                        Vec3d(1.0f, 1.0f, 1.0f)
//                    )->GetId() << std::endl;
//                    
//                },
//                Vec3d(0.8f, 0.0f), 
//                Vec3d(0.20f, 0.15f)
//            )->GetId()
//        );
        
        // Добавление игрового режима
        state->LinkEntityToState(
            entityManager.AddGameMode(
                false,
                [&](){SoloGameResultsState();},
                {0.2f, 0.8f},
                {sf::milliseconds(1000), sf::milliseconds(1000)}
            )->GetId()
        );
    }
    
    //
    void StateSystem::SoloGameResultsInit() {
        // Добавление нового состояния приложения
        auto state = entityManager.AddApplicationState("SoloGameResultsState");
        
        // Добавление фона
        state->LinkEntityToState(
            entityManager.AddBackground("../data/mainMenuBackground.png")->GetId()
        );
        
        // Добавление текстового поля
        state->LinkEntityToState(
            entityManager.AddLabel(
                UIComponent::Type::label,
                "Результаты", 
                nullptr,
                nullptr,
                Vec3d(0.f, 0.f, 0.f),
                false,
                [](){}, 
                Vec3d(0.4f, 0.2f), 
                Vec3d(0.28f, 0.15f)
            )->GetId()
        );
        
        // Добавление кнопок
        state->LinkEntityToState(
            entityManager.AddButton(
                UIComponent::Type::button,
                "Выйти в меню", 
                nullptr,
                nullptr,
                Vec3d(1.0f, 1.0f, 1.0f),
                false,
                [&](){SoloGameMenuState();},
                Vec3d(0.4f, 0.8f), 
                Vec3d(0.1f, 0.15f)
            )->GetId()
        );
    }
    
    //
    void StateSystem::MainMenuState() {
        entityManager.HideUI();
        entityManager.DeactivateGameModes();
        
        auto &state = componentManager.GetApplicationStateComponent("MainMenuState");
        entityManager.GetApplicationStates()->SetCurrentState(state);
        for (auto &[id, value] : state->GetEntitiesIds()) {
            if (componentManager.HasUIComponent(id)) {
                componentManager.GetUIComponent(id)->Show();
            } else if (componentManager.HasVisualComponent(id)) {
                componentManager.GetVisualComponent(id)->Show();
            } else if (componentManager.HasGameModeComponent(id)) {
                componentManager.GetGameModeComponent(id)->Activate();
            }
        }
    }
    
    //
    void StateSystem::SoloGameMenuState() {
        entityManager.HideUI();
        entityManager.DeactivateGameModes();
        
        auto state = componentManager.GetApplicationStateComponent("SoloGameMenuState");
        entityManager.GetApplicationStates()->SetCurrentState(state);
        for (auto &[id, value] : state->GetEntitiesIds()) {
            if (componentManager.HasUIComponent(id)) {
                componentManager.GetUIComponent(id)->Show();
            } else if (componentManager.HasVisualComponent(id)) {
                componentManager.GetVisualComponent(id)->Show();
            } else if (componentManager.HasGameModeComponent(id)) {
                componentManager.GetGameModeComponent(id)->Activate();
            }
        }
    }
    
    //
    void StateSystem::InSoloGameState() {
        entityManager.HideUI();
        entityManager.DeactivateGameModes();
        
        // Добавление пола
        auto &floor = entityManager.AddFloor(
            true,
            Vec3d(0.0f, 0.95f),
            Vec3d(0.0f, 0.0f),
            Vec3d(1.0f, 0.05f),
            100ull,
            100ull
        );
        
        auto state = componentManager.GetApplicationStateComponent("InSoloGameState");
        entityManager.GetApplicationStates()->SetCurrentState(state);
        for (auto &[id, value] : state->GetEntitiesIds()) {
            if (componentManager.HasUIComponent(id)) {
                componentManager.GetUIComponent(id)->Show();
            } else if (componentManager.HasVisualComponent(id)) {
                componentManager.GetVisualComponent(id)->Show();
            } else if (componentManager.HasGameModeComponent(id)) {
                componentManager.GetGameModeComponent(id)->Activate();
            }
            if (entityManager.HasHealthBar(id)) {
                auto &healthBar = entityManager.GetHealthBar(id);
                std::uint64_t *data1 = &floor->GetHealth()->GetCurrentHealth();
                std::uint64_t *data2 = &floor->GetHealth()->GetMaxHealth();
                healthBar->GetUI()->SetTrackedData1(data1);
                healthBar->GetUI()->SetTrackedData2(data2);
            }
        }
        
        
    }
    
    //
    void StateSystem::SoloGameResultsState() {
        entityManager.HideUI();
        entityManager.DeactivateGameModes();
        
        auto state = componentManager.GetApplicationStateComponent("SoloGameResultsState");
        entityManager.GetApplicationStates()->SetCurrentState(state);
        for (auto &[id, value] : state->GetEntitiesIds()) {
            if (componentManager.HasUIComponent(id)) {
                componentManager.GetUIComponent(id)->Show();
            } else if (componentManager.HasVisualComponent(id)) {
                componentManager.GetVisualComponent(id)->Show();
            } else if (componentManager.HasGameModeComponent(id)) {
                componentManager.GetGameModeComponent(id)->Activate();
            }
        }
    }
}