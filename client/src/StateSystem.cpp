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
        CampanyGameMenuInit();
        InChapter1GameInit();
        InEndlessGameInit();
        EndlessGameResultsInit();
        
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
                "Blind Typer",
                nullptr,
                80,
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
                "Кампания", 
                nullptr,
                80,
                Vec3d(1.0f, 1.0f, 1.0f),
                false,
                [&](){CampanyGameMenuState();}, 
                Vec3d(0.02f, 0.4f), 
                Vec3d(0.28f, 0.15f)
            )->GetId()
        );
        
        state->LinkEntityToState(
            entityManager.AddButton(
                "Бесконечный", 
                nullptr,
                80,
                Vec3d(1.0f, 1.0f, 1.0f),
                false,
                [&](){InEndlessGameState();}, 
                Vec3d(0.36f, 0.4f), 
                Vec3d(0.28f, 0.15f)
            )->GetId()
        );
        
        state->LinkEntityToState(
            entityManager.AddButton(
                "Сетевой", 
                nullptr,
                80,
                Vec3d(1.0f, 1.0f, 1.0f),
                false,
                [&](){}, 
                Vec3d(0.7f, 0.4f), 
                Vec3d(0.28f, 0.15f)
            )->GetId()
        );
        
        state->LinkEntityToState(
            entityManager.AddButton(
                "Профиль", 
                nullptr,
                80,
                Vec3d(1.0f, 1.0f, 1.0f),
                false,
                [&](){}, 
                Vec3d(0.02f, 0.7f), 
                Vec3d(0.28f, 0.15f)
            )->GetId()
        );
        
        state->LinkEntityToState(
            entityManager.AddButton(
                "Настройки", 
                nullptr,
                80,
                Vec3d(1.0f, 1.0f, 1.0f),
                false,
                [&](){}, 
                Vec3d(0.36f, 0.7f), 
                Vec3d(0.28f, 0.15f)
            )->GetId()
        );
        
        state->LinkEntityToState(
            entityManager.AddButton(
                "Выход", 
                nullptr,
                80,
                Vec3d(1.0f, 1.0f, 1.0f),
                false,
                [](){exit(0);}, 
                Vec3d(0.7f, 0.7f), 
                Vec3d(0.28f, 0.15f)
            )->GetId()
        );
    }
    
    //
    void StateSystem::CampanyGameMenuInit() {
        // Добавление нового состояния приложения
        auto state = entityManager.AddApplicationState("CampanyGameMenuState");
        
        // Добавление фона
        state->LinkEntityToState(
            entityManager.AddBackground("../data/mainMenuBackground.png")->GetId()
        );
        
        // Добавление текстового поля
        state->LinkEntityToState(
            entityManager.AddLabel(
                "Кампания", 
                nullptr,
                80,
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
                "Глава I\n\"Обучение\"", 
                nullptr,
                80,
                Vec3d(1.0f, 1.0f, 1.0f),
                false,
                [&](){InChapter1GameState();}, 
                Vec3d(0.02f, 0.4f), 
                Vec3d(0.28f, 0.15f)
            )->GetId()
        );
        
        state->LinkEntityToState(
            entityManager.AddButton(
                "Глава II\n\"as df\"", 
                nullptr,
                80,
                Vec3d(1.0f, 1.0f, 1.0f),
                false,
                [&](){}, 
                Vec3d(0.36f, 0.4f), 
                Vec3d(0.28f, 0.15f)
            )->GetId()
        );
        
        state->LinkEntityToState(
            entityManager.AddButton(
                "Глава III", 
                nullptr,
                80,
                Vec3d(1.0f, 1.0f, 1.0f),
                false,
                [&](){}, 
                Vec3d(0.7f, 0.4f), 
                Vec3d(0.28f, 0.15f)
            )->GetId()
        );
        
        state->LinkEntityToState(
            entityManager.AddButton(
                "Глава IV", 
                nullptr,
                80,
                Vec3d(1.0f, 1.0f, 1.0f),
                false,
                [&](){}, 
                Vec3d(0.02f, 0.7f), 
                Vec3d(0.28f, 0.15f)
            )->GetId()
        );
        
        state->LinkEntityToState(
            entityManager.AddButton(
                "Глава V", 
                nullptr,
                80,
                Vec3d(1.0f, 1.0f, 1.0f),
                false,
                [&](){}, 
                Vec3d(0.36f, 0.7f), 
                Vec3d(0.28f, 0.15f)
            )->GetId()
        );
        
        state->LinkEntityToState(
            entityManager.AddButton(
                "Назад", 
                nullptr,
                80,
                Vec3d(1.0f, 1.0f, 1.0f),
                false,
                [&](){MainMenuState();}, 
                Vec3d(0.7f, 0.7f), 
                Vec3d(0.28f, 0.15f)
            )->GetId()
        );
    }
    
    //
    void StateSystem::InChapter1GameInit() {
        // Добавление нового состояния приложения
        auto state = entityManager.AddApplicationState("InChapter1GameState");
        
        // Добавление фона
        state->LinkEntityToState(
            entityManager.AddBackground("../data/mainMenuBackground.png")->GetId()
        );
        
        // Добавление текстового поля
        state->LinkEntityToState(
            entityManager.AddButton(
                "Всего уничтожено букв: ", 
                [&](){
                    auto &player = (*entityManager.GetPlayers().begin()).second;
                    return std::to_string(player->GetPlayerStatComponent()->GetTotalLettersDestroyed());
                },
                24,
                Vec3d(1.f, 1.f, 1.f),
                false,
                [](){}, 
                Vec3d(0.0f, 0.2f), 
                Vec3d(0.15f, 0.1f)
            )->GetId()
        );
        
        state->LinkEntityToState(
            entityManager.AddButton(
                "Времени прошло: ",
                [&](){
                    auto &player = (*entityManager.GetPlayers().begin()).second;
                    return std::to_string(player->GetPlayerStatComponent()->GetTimePassed() / 1000ull);
                },
                24,
                Vec3d(1.f, 1.f, 1.f),
                false,
                [](){}, 
                Vec3d(0.0f, 0.3f), 
                Vec3d(0.15f, 0.1f)
            )->GetId()
        );
        
        state->LinkEntityToState(
            entityManager.AddButton(
                "Букв уничтожено\nв секунду: ",
                [&](){
                    auto &player = (*entityManager.GetPlayers().begin()).second;
                    return std::to_string(
                        static_cast<long double>(player->GetPlayerStatComponent()->GetTotalLettersDestroyed())
                        / static_cast<long double>(player->GetPlayerStatComponent()->GetTimePassed()) * 1000.d
                    );
                },
                24,
                Vec3d(1.f, 1.f, 1.f),
                false,
                [](){}, 
                Vec3d(0.0f, 0.4f), 
                Vec3d(0.15f, 0.1f)
            )->GetId()
        );
        
        // Добавление полосы здоровья
        state->LinkEntityToState(
            entityManager.AddHealthBar(
                " ", 
                nullptr,
                Vec3d(1.0f, 1.0f, 1.0f),
                false,
                [&](){},
                Vec3d(0.15f, 0.0f), 
                Vec3d(0.7f, 0.05f)
            )->GetId()
        );
        
        // Добавление кнопок
        state->LinkEntityToState(
            entityManager.AddButton(
                "≡", 
                nullptr,
                80,
                Vec3d(1.0f, 1.0f, 1.0f),
                false,
                [&](){CampanyGameMenuState();},
                Vec3d(0.0f, 0.0f), 
                Vec3d(0.10f, 0.15f)
            )->GetId()
        );
        
        // Добавление игрового режима
        state->LinkEntityToState(
            entityManager.AddGameMode(
                false,
                [&](){Chapter1GameResultsState();},
                {0.2f, 0.8f},
                {sf::milliseconds(2000), sf::milliseconds(2000)}
            )->GetId()
        );
    }
    
    //
    void StateSystem::Chapter1GameResultsInit() {
        // Добавление нового состояния приложения
        auto state = entityManager.AddApplicationState("Chapter1GameResultsState");
        
        // Добавление фона
        state->LinkEntityToState(
            entityManager.AddBackground("../data/mainMenuBackground.png")->GetId()
        );
        
        // Добавление текстового поля
        state->LinkEntityToState(
            entityManager.AddLabel(
                "Результаты", 
                nullptr,
                16,
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
                "Выйти в меню",
                nullptr,
                16,
                Vec3d(1.0f, 1.0f, 1.0f),
                false,
                [&](){MainMenuState();},
                Vec3d(0.4f, 0.8f), 
                Vec3d(0.1f, 0.15f)
            )->GetId()
        );
    }
    
    //
    void StateSystem::InEndlessGameInit() {
        // Добавление нового состояния приложения
        auto state = entityManager.AddApplicationState("InEndlessGameState");
        
        // Добавление фона
        state->LinkEntityToState(
            entityManager.AddBackground("../data/mainMenuBackground.png")->GetId()
        );
        
        auto &player = entityManager.AddPlayer();
        state->LinkEntityToState(
            player->GetId()
        );
        
        // Добавление текстового поля
        state->LinkEntityToState(
            entityManager.AddButton(
                "Всего уничтожено букв: ", 
                [&](){return std::to_string(player->GetPlayerStatComponent()->GetTotalLettersDestroyed());},
                24,
                Vec3d(1.f, 1.f, 1.f),
                false,
                [](){}, 
                Vec3d(0.0f, 0.2f), 
                Vec3d(0.15f, 0.1f)
            )->GetId()
        );
        
        state->LinkEntityToState(
            entityManager.AddButton(
                "Времени прошло: ",
                [&](){return std::to_string(player->GetPlayerStatComponent()->GetTimePassed() / 1000ull);},
                24,
                Vec3d(1.f, 1.f, 1.f),
                false,
                [](){}, 
                Vec3d(0.0f, 0.3f), 
                Vec3d(0.15f, 0.1f)
            )->GetId()
        );
        
        state->LinkEntityToState(
            entityManager.AddButton(
                "Букв уничтожено\nв секунду: ",
                [&](){
                    return std::to_string(
                        static_cast<long double>(player->GetPlayerStatComponent()->GetTotalLettersDestroyed())
                        / static_cast<long double>(player->GetPlayerStatComponent()->GetTimePassed()) * 1000.d
                    );
                },
                24,
                Vec3d(1.f, 1.f, 1.f),
                false,
                [](){}, 
                Vec3d(0.0f, 0.4f), 
                Vec3d(0.15f, 0.1f)
            )->GetId()
        );
        
        // Добавление полосы здоровья
        state->LinkEntityToState(
            entityManager.AddHealthBar(
                " ", 
                nullptr,
                Vec3d(1.0f, 1.0f, 1.0f),
                false,
                [&](){},
                Vec3d(0.15f, 0.0f), 
                Vec3d(0.7f, 0.05f)
            )->GetId()
        );
        
        // Добавление кнопок
        state->LinkEntityToState(
            entityManager.AddButton(
                "≡", 
                nullptr,
                80,
                Vec3d(1.0f, 1.0f, 1.0f),
                false,
                [&](){MainMenuState();},
                Vec3d(0.0f, 0.0f), 
                Vec3d(0.10f, 0.15f)
            )->GetId()
        );
        
        // Добавление игрового режима
        state->LinkEntityToState(
            entityManager.AddGameMode(
                false,
                [&](){EndlessGameResultsState();},
                {0.2f, 0.8f},
                {sf::milliseconds(1000), sf::milliseconds(1000)}
            )->GetId()
        );
    }
    
    //
    void StateSystem::EndlessGameResultsInit() {
        // Добавление нового состояния приложения
        auto state = entityManager.AddApplicationState("EndlessGameResultsState");
        
        // Добавление фона
        state->LinkEntityToState(
            entityManager.AddBackground("../data/mainMenuBackground.png")->GetId()
        );
        
        // Добавление текстового поля
        state->LinkEntityToState(
            entityManager.AddLabel(
                "Результаты", 
                nullptr,
                16,
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
                "Выйти в меню",
                nullptr,
                16,
                Vec3d(1.0f, 1.0f, 1.0f),
                false,
                [&](){MainMenuState();},
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
    void StateSystem::CampanyGameMenuState() {
        entityManager.HideUI();
        entityManager.DeactivateGameModes();
        
        auto state = componentManager.GetApplicationStateComponent("CampanyGameMenuState");
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
    void StateSystem::InChapter1GameState() {
        entityManager.HideUI();
        entityManager.DeactivateGameModes();
        
        auto &player = entityManager.AddPlayer();
        
        // Добавление пола
        auto &floor = entityManager.AddFloor(
            true,
            Vec3d(0.0f, 0.95f),
            Vec3d(0.0f, 0.0f),
            Vec3d(1.0f, 0.05f),
            100ull,
            100ull
        );
        
        auto state = componentManager.GetApplicationStateComponent("InChapter1GameState");
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
                healthBar->GetUI()->SetTrackedData([&](){
                    long double data1 = static_cast<long double>(floor->GetHealth()->GetCurrentHealth());
                    long double data2 = static_cast<long double>(floor->GetHealth()->GetMaxHealth());
                    return std::to_string(data1 / data2);
                });
            }
        }
    }
    
    //
    void StateSystem::Chapter1GameResultsState() {
        entityManager.HideUI();
        entityManager.DeactivateGameModes();
        
        auto state = componentManager.GetApplicationStateComponent("Chapter1GameResultsState");
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
    void StateSystem::InEndlessGameState() {
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
        
        auto state = componentManager.GetApplicationStateComponent("InEndlessGameState");
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
                healthBar->GetUI()->SetTrackedData([&](){
                    long double data1 = static_cast<long double>(floor->GetHealth()->GetCurrentHealth());
                    long double data2 = static_cast<long double>(floor->GetHealth()->GetMaxHealth());
                    return std::to_string(data1 / data2);
                });
            }
        }
        
        
    }
    
    //
    void StateSystem::EndlessGameResultsState() {
        entityManager.HideUI();
        entityManager.DeactivateGameModes();
        
        auto state = componentManager.GetApplicationStateComponent("EndlessGameResultsState");
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