# Core/Primary Logic
Application.hpp / Application.cpp - Главный класс игры, основной цикл

AppState.hpp / StateSystem.hpp / SystemManager.hpp -> include/core/AppState.hpp ; src/core/AppState.cpp - Управление состояниями игры (меню, игра, пауза)

WindowComponent.hpp -> include/core/WindowComponent.hpp ; src/core/WindowComponent.cpp  ; Окно SFML, размеры

Manager.hpp -> убран / функционал встроен в Application ; ECS упрощен

ComponentManager.hpp / EntityManager.hpp -> убраны / управление сущностями и компонентами теперь внутри Application или TextEntity ; ECS упрощен

***

# Systems
AudioSystem.hpp / AudioSystem.cpp -> include/systems/AudioSystem.hpp ; src/systems/AudioSystem.cpp - Обработка звуков (нажатия клавиш)

InputSystem.hpp / InputSystem.cpp -> include/systems/InputSystem.hpp ; src/systems/InputSystem.cpp - Обработка ввода

VisualSystem.hpp / VisualComponent.hpp / VisualResourcesComponent.hpp -> include/systems/VisualSystem.hpp ; src/systems/VisualSystem.cpp - Отрисовка текста и визуальных эффектов

MovementSystem.hpp / MovementComponent.hpp -> удалено / не используется

CollisionSystem.hpp / Rect.hpp -> удалено / Rect.hpp перенесен в utils 

DamageSystem.hpp / HealthComponent.hpp -> удалено / не используется

LifetimeSystem.hpp / LifetimeComponent.hpp -> удалено / не используется

StateSystem.hpp -> функционал объединён в AppState - Управление состояниями игры

***

# Сущности / Компоненты
Entity.hpp / Entity.cpp -> убраны / TextEntity заменяет сущность текст - Главная игровая сущность — текст

Component.hpp / Component.cpp -> убраны / LetterComponent и TextEntity заменяют ECS - Компоненты теперь минимальные

Letter.hpp / LetterComponent.hpp -> include/text/LetterComponent.hpp ; src/text/LetterComponent.cpp -Каждая буква с состоянием

TextEntity.hpp -> include/text/TextEntity.hpp / src/text/TextEntity.cpp - Строка текста, прогресс, статистика

Player.hpp / BodyComponent.hpp / Floor.hpp -> удалено / не используется

TransformComponent.hpp / Vec3d.hpp	-> Vec3d.hpp перенесен в utils/Vec2.hpp - Простейшие координаты

***

# Ресурсы
SystemResources.hpp / VisualResourcesComponent.hpp -> ResourceManager встроен в core/Application / AudioSystem / VisualSystem - Управление шрифтами, текстурами, звуками

SoundComponent.hpp -> интегрирован в AudioSystem - Звуки нажатий

***

# GUI / ImGui
imgui-SFML.h / cpp, imgui.h / cpp, imgui_demo.cpp, imgui_draw.cpp, imgui_widgets.cpp, imgui_tables.cpp, imconfig*.h -> удалены / не используются - Для слепой печати не нужны, только если для отладки

***

# Утилиты
Vec3d.hpp -> utils/Vec2.hpp	- Векторы, координаты

Rect.hpp -> utils/Rect.hpp - Прямоугольники

Timer.hpp -> utils/Timer.hpp - Таймеры и время

