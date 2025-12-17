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
                Vec3d(1.0f, 1.0f, 1.0f),
                false,
                [&](){SoloGameMenuState();}, 
                Vec3d(0.02f, 0.4f), 
                Vec3d(0.28f, 0.15f)
            )->GetId()
        );
        
        state->LinkEntityToState(
            entityManager.AddButton(
                "Бесконечный", 
                Vec3d(1.0f, 1.0f, 1.0f),
                false,
                [&](){}, 
                Vec3d(0.36f, 0.4f), 
                Vec3d(0.28f, 0.15f)
            )->GetId()
        );
        
        state->LinkEntityToState(
            entityManager.AddButton(
                "Сетевой", 
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
        // Добавление фона
        auto state = entityManager.AddApplicationState("SoloGameMenu");
        
        // Добавление текстового поля
        state->LinkEntityToState(
            entityManager.AddLabel(
                "Кампания", 
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
                "Глава I\n\"Обучение\"", 
                Vec3d(1.0f, 1.0f, 1.0f),
                false,
                [&](){}, 
                Vec3d(0.02f, 0.4f), 
                Vec3d(0.28f, 0.15f)
            )->GetId()
        );
        
        state->LinkEntityToState(
            entityManager.AddButton(
                "Глава II\n\"as df\"", 
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
                Vec3d(1.0f, 1.0f, 1.0f),
                false,
                [&](){MainMenuState();}, 
                Vec3d(0.7f, 0.7f), 
                Vec3d(0.28f, 0.15f)
            )->GetId()
        );
    }
    
    //
    void StateSystem::MainMenuState() {
        entityManager.HideUI();
        
        auto state = componentManager.GetApplicationStateComponent("MainMenuState");
        for (auto &it : state->GetEntitiesIds()) {
            std::uint64_t id = it.first;
            if (entityManager.HasLabel(id)) {
                entityManager.GetLabel(id)->GetUI()->IsVisible() = true;
            } else if (entityManager.HasButton(id)) {
                entityManager.GetButton(id)->GetUI()->IsVisible() = true;
            } 
        }
    }
    
    //
    void StateSystem::SoloGameMenuState() {
        entityManager.HideUI();
        
        auto state = componentManager.GetApplicationStateComponent("SoloGameMenu");
        for (auto &it : state->GetEntitiesIds()) {
            std::uint64_t id = it.first;
            if (entityManager.HasLabel(id)) {
                entityManager.GetLabel(id)->GetUI()->IsVisible() = true;
            } else if (entityManager.HasButton(id)) {
                entityManager.GetButton(id)->GetUI()->IsVisible() = true;
            } 
        }
    }
}