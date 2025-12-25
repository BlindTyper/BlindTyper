/*

*/

#ifndef UNIT_TESTS_TYPE_HEADER
#define UNIT_TESTS_TYPE_HEADER

#include <iostream>
#include <string>

#include "ApplicationSettingsComponent.hpp"
#include "ApplicationStateComponent.hpp"
#include "WindowComponent.hpp"
#include "VisualResourcesComponent.hpp"
#include "GameModeComponent.hpp"
#include "UIComponent.hpp"
#include "VisualComponent.hpp"
#include "TransformComponent.hpp"
#include "BodyComponent.hpp"
#include "HealthComponent.hpp"
#include "DamageComponent.hpp"
#include "MovementComponent.hpp"
#include "GlyphComponent.hpp"
#include "SoundComponent.hpp"

#include "SystemResources.hpp"
#include "ApplicationStates.hpp"
#include "Letter.hpp"
#include "Floor.hpp"
#include "Player.hpp"
#include "Background.hpp"
#include "Button.hpp"
#include "Label.hpp"
#include "HealthBar.hpp"
#include "GameMode.hpp"

#include "InputSystem.hpp"
#include "VisualSystem.hpp"
#include "DamageSystem.hpp"
#include "MovementSystem.hpp"
#include "LifetimeSystem.hpp"
#include "AudioSystem.hpp"
#include "StateSystem.hpp"

#include "ComponentManager.hpp"
#include "EntityManager.hpp"
#include "SystemManager.hpp"

namespace tppo {
    class UnitTests {
        
    protected:
        
    public:
        //
        static void B01() {
            std::cout << "Запуск теста Б01: " << std::endl;
            ApplicationSettingsComponent component(0);
            std::string title = "Test Window";
            component.SetWindowTitle(title);
            std::cout << "Установка заголовка окна: " << title << std::endl;
            std::cout << "Получение заголовка окна: " << component.GetWindowTitle() << std::endl;
            if (component.GetWindowTitle() == title) {
                std::cout << "Тест пройден успешно" << std::endl;
            }
            else {
                std::cout << "Тест не пройден" << std::endl;
            }
            std::cout << std::endl;
        }
        
        //
        static void B02() {
            std::cout << "Запуск теста Б02: " << std::endl;
            ApplicationSettingsComponent component(0);
            ImGuiWindowFlags flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
            component.SetWindowFlags(flags);
            std::cout << "Установка флагов окна: " << flags << std::endl;
            std::cout << "Получение флагов окна: " << component.GetWindowFlags() << std::endl;
            if (component.GetWindowFlags() == flags) {
                std::cout << "Тест пройден успешно" << std::endl;
            }
            else {
                std::cout << "Тест не пройден" << std::endl;
            }
            std::cout << std::endl;
        }
        
        //
        static void B03() {
            std::cout << "Запуск теста Б03: " << std::endl;
            Vec3d pos(10.0, 20.0, 0.0);
            TransformComponent component(0, pos);
            std::cout << "Установка позиции объекта: Vec3d(" << pos.x << ", " << pos.y << ", " << pos.z << ")" << std::endl;
            std::cout << "Получение позиции объекта: Vec3d(" 
                << component.GetPosition().x << ", " 
                << component.GetPosition().y << ", " 
                << component.GetPosition().z << ")" << std::endl;
            if (component.GetPosition().x == pos.x &&
                component.GetPosition().y == pos.y &&
                component.GetPosition().z == pos.z
            ) {
                std::cout << "Тест пройден успешно" << std::endl;
            }
            else {
                std::cout << "Тест не пройден" << std::endl;
            }
            std::cout << std::endl;
        }
        
        //
        static void B04() {
            std::cout << "Запуск теста Б04: " << std::endl;
            Vec3d size(2.0f, 2.0f, 1.0f);
            TransformComponent component(0, Vec3d(), size);
            std::cout << "Установка размера объекта: Vec3d(" << size.x << ", " << size.y << ", " << size.z << ")" << std::endl;
            std::cout << "Получение размера объекта: Vec3d(" 
                << component.GetSize().x << ", " 
                << component.GetSize().y << ", " 
                << component.GetSize().z << ")" << std::endl;
            if (component.GetSize().x == size.x &&
                component.GetSize().y == size.y &&
                component.GetSize().z == size.z
            ) {
                std::cout << "Тест пройден успешно" << std::endl;
            }
            else {
                std::cout << "Тест не пройден" << std::endl;
            }
            std::cout << std::endl;
        }
        
        //
        static void B05() {
            std::cout << "Запуск теста Б05: " << std::endl;
            Vec3d vel(0.0f, -5.0f, 0.0f);
            MovementComponent component(0, vel);
            std::cout << "Установка скорости движения объекта: Vec3d(" << vel.x << ", " << vel.y << ", " << vel.z << ")" << std::endl;
            std::cout << "Получение скорости движения объекта: Vec3d(" 
                << component.GetVelocity().x << ", " 
                << component.GetVelocity().y << ", " 
                << component.GetVelocity().z << ")" << std::endl;
            if (component.GetVelocity().x == vel.x &&
                component.GetVelocity().y == vel.y &&
                component.GetVelocity().z == vel.z
            ) {
                std::cout << "Тест пройден успешно" << std::endl;
            }
            else {
                std::cout << "Тест не пройден" << std::endl;
            }
            std::cout << std::endl;
        }
        
        //
        static void B06() {
            std::cout << "Запуск теста Б06: " << std::endl;
            Vec3d acc(0.0f, -9.8f, 0.0f);
            MovementComponent component(0, Vec3d(), acc);
            std::cout << "Установка ускорения движения объекта: Vec3d(" << acc.x << ", " << acc.y << ", " << acc.z << ")" << std::endl;
            std::cout << "Получение ускорения движения объекта: Vec3d(" 
                << component.GetAcceleration().x << ", " 
                << component.GetAcceleration().y << ", " 
                << component.GetAcceleration().z << ")" << std::endl;
            if (component.GetAcceleration().x == acc.x &&
                component.GetAcceleration().y == acc.y &&
                component.GetAcceleration().z == acc.z
            ) {
                std::cout << "Тест пройден успешно" << std::endl;
            }
            else {
                std::cout << "Тест не пройден" << std::endl;
            }
            std::cout << std::endl;
        }
        
        //
        static void B07() {
            std::cout << "Запуск теста Б07: " << std::endl;
            Vec3d body(0.09f, 0.0f, 0.0f);
            BodyComponent component(0, body);
            std::cout << "Установка тела столкновения объекта: Vec3d(" << body.x << ", " << body.y << ", " << body.z << ")" << std::endl;
            std::cout << "Получение тела столкновения объекта: Vec3d(" 
                << component.GetSize().x << ", " 
                << component.GetSize().y << ", " 
                << component.GetSize().z << ")" << std::endl;
            if (component.GetSize().x == body.x &&
                component.GetSize().y == body.y &&
                component.GetSize().z == body.z
            ) {
                std::cout << "Тест пройден успешно" << std::endl;
            }
            else {
                std::cout << "Тест не пройден" << std::endl;
            }
            std::cout << std::endl;
        }
        
        //
        static void B08() {
            std::cout << "Запуск теста Б08: " << std::endl;
            std::uint64_t health(100);
            HealthComponent component(0, health, health);
            std::cout << "Установка начального здоровья объекта: " << health << std::endl;
            std::cout << "Получение начального здоровья объекта: " << component.GetCurrentHealth() << std::endl;
            if (component.GetCurrentHealth() == health) {
                std::cout << "Тест пройден успешно" << std::endl;
            }
            else {
                std::cout << "Тест не пройден" << std::endl;
            }
            std::cout << std::endl;
        }
        
        //
        static void B09() {
            std::cout << "Запуск теста Б09: " << std::endl;
            std::uint64_t damage(10);
            DamageComponent component(0, damage);
            std::cout << "Установка наносимого урона объектом: " << damage << std::endl;
            std::cout << "Получение наносимого урона объектом: " << component.GetDamage() << std::endl;
            if (component.GetDamage() == damage) {
                std::cout << "Тест пройден успешно" << std::endl;
            }
            else {
                std::cout << "Тест не пройден" << std::endl;
            }
            std::cout << std::endl;
        }
        
        //
        static void B10() {
            std::cout << "Запуск теста Б10: " << std::endl;
            std::uint64_t health(100);
            std::uint64_t damage(30);
            HealthComponent component(0, health - damage, health);
            std::cout << "Установка начального здоровья объекта: " << health << std::endl;
            std::cout << "Получение здоровья объекта: " << component.GetCurrentHealth();
            std::cout << ", после получения урона: " << damage << std::endl;
            if (component.GetCurrentHealth() == health - damage) {
                std::cout << "Тест пройден успешно" << std::endl;
            }
            else {
                std::cout << "Тест не пройден" << std::endl;
            }
            std::cout << std::endl;
        }
        
        //
        static void B11() {
            std::cout << "Запуск теста Б11: " << std::endl;
            std::uint64_t health(100);
            HealthComponent component(0, 0, health);
            std::cout << "Установка максимального здоровья объекта: " << health << std::endl;
            std::cout << "Получение максимального здоровья объекта: " << component.GetMaxHealth() << std::endl;
            if (component.GetMaxHealth() == health) {
                std::cout << "Тест пройден успешно" << std::endl;
            }
            else {
                std::cout << "Тест не пройден" << std::endl;
            }
            std::cout << std::endl;
        }
        
        //
        static void B12() {
            std::cout << "Запуск теста Б12: " << std::endl;
            char c = 'Z'; 
            GlyphComponent component(0, c);
            std::cout << "Установка символа объекта: " << c << std::endl;
            std::cout << "Получение символа объекта: " << component.GetGlyph() << std::endl;
            if (component.GetGlyph() == c) {
                std::cout << "Тест пройден успешно" << std::endl;
            }
            else {
                std::cout << "Тест не пройден" << std::endl;
            }
            std::cout << std::endl;
        }
        
        //
        static void B13() {
            std::cout << "Запуск теста Б13: " << std::endl;
            std::pair<long double, long double> respawnSpace = {1.0f, 1.0f}; 
            std::pair<sf::Time, sf::Time> resp = {sf::seconds(2), sf::seconds(2)}; 
            GameModeComponent component(0, 0, [](){}, respawnSpace, resp);
            std::cout << "Установка периода появления букв: " << resp.second.asSeconds() << std::endl;
            std::cout << "Получение периода появления букв: " << component.GetRespawnPeriodRange().second.asSeconds() << std::endl;
            if (component.GetRespawnPeriodRange().second == resp.second) {
                std::cout << "Тест пройден успешно" << std::endl;
            }
            else {
                std::cout << "Тест не пройден" << std::endl;
            }
            std::cout << std::endl;
        }
        
        //
        static void B14() {
            std::cout << "Запуск теста Б14: " << std::endl;
            bool isActive = true;
            std::pair<long double, long double> respawnSpace = {1.0f, 1.0f}; 
            std::pair<sf::Time, sf::Time> resp = {sf::seconds(2), sf::seconds(2)}; 
            GameModeComponent component(0, isActive, [](){}, respawnSpace, resp);
            std::cout << "Установка активности компоненты игрового режима: " << isActive << std::endl;
            std::cout << "Получение активности компоненты игрового режима: " << component.IsActive() << std::endl;
            if (component.IsActive() == isActive) {
                std::cout << "Тест пройден успешно" << std::endl;
            }
            else {
                std::cout << "Тест не пройден" << std::endl;
            }
            std::cout << std::endl;
        }
        
        //
        static void B15() {
            std::cout << "Запуск теста Б15: " << std::endl;
            std::shared_ptr<ApplicationSettingsComponent> settings(new ApplicationSettingsComponent(0));
            std::shared_ptr<WindowComponent> window(new WindowComponent(0));
            std::shared_ptr<VisualResourcesComponent> visualResources(new VisualResourcesComponent(0));
            SystemResources entity(settings, window, visualResources);
            std::cout << "Проверка создания сущности системных ресурсов: ";
            if (entity.GetId() == 0) {
                std::cout << "сущность создана" << std::endl;
                std::cout << "Проверка доступности компонент:" << std::endl;
                if (entity.GetSettings().GetId()) {
                    std::cout << "  ApplicationSettingsComponent - доступен" << std::endl;
                }
                else {
                    std::cout << "  ApplicationSettingsComponent - недоступен" << std::endl;
                    std::cout << "Тест не пройден" << std::endl;
                    return;
                }
                if (entity.GetWindow().GetId()) {
                    std::cout << "  WindowComponent - доступен" << std::endl;
                }
                else {
                    std::cout << "  WindowComponent - недоступен" << std::endl;
                    std::cout << "Тест не пройден" << std::endl;
                    return;
                }
                if (entity.GetVisualResources().GetId()) {
                    std::cout << "  VisualResourcesComponent - доступен" << std::endl;
                }
                else {
                    std::cout << "  VisualResourcesComponent - недоступен" << std::endl;
                    std::cout << "Тест не пройден" << std::endl;
                    return;
                }
                
                std::cout << "Тест пройден успешно" << std::endl;
            }
            else {
                std::cout << "сущность не создана" << std::endl;
                std::cout << "Тест не пройден" << std::endl;
            }
            std::cout << std::endl;
        }
        
        //
        static void B16() {
            std::cout << "Запуск теста Б16: " << std::endl;
            sf::Texture texture;
            std::shared_ptr<VisualComponent> visual(new VisualComponent(0, texture));
            std::shared_ptr<TransformComponent> transform(new TransformComponent(0));
            std::shared_ptr<BodyComponent> body(new BodyComponent(0, Vec3d()));
            std::shared_ptr<MovementComponent> movement(new MovementComponent(0));
            std::shared_ptr<GlyphComponent> glyph(new GlyphComponent(0, 'a'));
            std::shared_ptr<DamageComponent> damage(new DamageComponent(0, 7));
            Letter entity(visual, transform, body, movement, glyph, damage);
            std::cout << "Проверка создания создания сущности буквы: ";
            if (entity.GetId()) {
                std::cout << "сущность создана" << std::endl;
                std::cout << "Проверка доступности компонент:" << std::endl;
                if (entity.GetVisual()->GetId()) {
                    std::cout << "  VisualComponent - доступен" << std::endl;
                }
                else {
                    std::cout << "  VisualComponent - недоступен" << std::endl;
                    std::cout << "Тест не пройден" << std::endl;
                    return;
                }
                if (entity.GetTransform()->GetId()) {
                    std::cout << "  TransformComponent - доступен" << std::endl;
                }
                else {
                    std::cout << "  TransformComponent - недоступен" << std::endl;
                    std::cout << "Тест не пройден" << std::endl;
                    return;
                }
                if (entity.GetBody()->GetId()) {
                    std::cout << "  BodyComponent - доступен" << std::endl;
                }
                else {
                    std::cout << "  BodyComponent - недоступен" << std::endl;
                    std::cout << "Тест не пройден" << std::endl;
                    return;
                }
                if (entity.GetMovement()->GetId()) {
                    std::cout << "  MovementComponent - доступен" << std::endl;
                }
                else {
                    std::cout << "  MovementComponent - недоступен" << std::endl;
                    std::cout << "Тест не пройден" << std::endl;
                    return;
                }
                if (entity.GetGlyph()->GetId()) {
                    std::cout << "  GlyphComponent - доступен" << std::endl;
                }
                else {
                    std::cout << "  GlyphComponent - недоступен" << std::endl;
                    std::cout << "Тест не пройден" << std::endl;
                    return;
                }
                if (entity.GetDamage()->GetId()) {
                    std::cout << "  DamageComponent - доступен" << std::endl;
                }
                else {
                    std::cout << "  DamageComponent - недоступен" << std::endl;
                    std::cout << "Тест не пройден" << std::endl;
                    return;
                }
                
                std::cout << "Тест пройден успешно" << std::endl;
            }
            else {
                std::cout << "сущность не создана" << std::endl;
                std::cout << "Тест не пройден" << std::endl;
            }
            std::cout << std::endl;
        }
        
        //
        static void B17() {
            std::cout << "Запуск теста Б17: " << std::endl;
            sf::Texture texture;
            std::shared_ptr<VisualComponent> visual(new VisualComponent(0, texture));
            std::shared_ptr<TransformComponent> transform(new TransformComponent(0));
            std::shared_ptr<BodyComponent> body(new BodyComponent(0, Vec3d()));
            std::shared_ptr<HealthComponent> health(new HealthComponent(0, 100, 100));
            Floor entity(visual, transform, body, health);
            std::cout << "Проверка создания создания сущности пола: ";
            if (entity.GetId()) {
                std::cout << "сущность создана" << std::endl;
                std::cout << "Проверка доступности компонент:" << std::endl;
                if (entity.GetVisual()->GetId()) {
                    std::cout << "  VisualComponent - доступен" << std::endl;
                }
                else {
                    std::cout << "  VisualComponent - недоступен" << std::endl;
                    std::cout << "Тест не пройден" << std::endl;
                    return;
                }
                if (entity.GetTransform()->GetId()) {
                    std::cout << "  TransformComponent - доступен" << std::endl;
                }
                else {
                    std::cout << "  TransformComponent - недоступен" << std::endl;
                    std::cout << "Тест не пройден" << std::endl;
                    return;
                }
                if (entity.GetBody()->GetId()) {
                    std::cout << "  BodyComponent - доступен" << std::endl;
                }
                else {
                    std::cout << "  BodyComponent - недоступен" << std::endl;
                    std::cout << "Тест не пройден" << std::endl;
                    return;
                }
                if (entity.GetHealth()->GetId()) {
                    std::cout << "  HealthComponent - доступен" << std::endl;
                }
                else {
                    std::cout << "  HealthComponent - недоступен" << std::endl;
                    std::cout << "Тест не пройден" << std::endl;
                    return;
                }
                
                std::cout << "Тест пройден успешно" << std::endl;
            }
            else {
                std::cout << "сущность не создана" << std::endl;
                std::cout << "Тест не пройден" << std::endl;
            }
            std::cout << std::endl;
        }
        
        //
        static void B18() {
            std::cout << "Запуск теста Б18: " << std::endl;
            Player entity;
            std::cout << "Проверка создания создания сущности пола: ";
            if (entity.GetId()) {
                std::cout << "сущность создана" << std::endl;
                std::cout << "Тест пройден успешно" << std::endl;
            }
            else {
                std::cout << "сущность не создана" << std::endl;
                std::cout << "Тест не пройден" << std::endl;
            }
            std::cout << std::endl;
        }
        
        //
        static void B19() {
            std::cout << "Запуск теста Б19: " << std::endl;
            std::pair<long double, long double> respawnSpace = {1.0f, 1.0f}; 
            std::pair<sf::Time, sf::Time> resp = {sf::seconds(2), sf::seconds(2)}; 
            std::shared_ptr<GameModeComponent> component(new GameModeComponent(0, 0, [](){}, respawnSpace, resp));
            GameMode entity(component);
            std::cout << "Проверка создания создания сущности игрового режима: ";
            if (entity.GetId()) {
                std::cout << "сущность создана" << std::endl;
                std::cout << "Проверка доступности компонент:" << std::endl;
                if (entity.GetGameMode()->GetId()) {
                    std::cout << "  GameMode - доступен" << std::endl;
                }
                else {
                    std::cout << "  GameMode - недоступен" << std::endl;
                    std::cout << "Тест не пройден" << std::endl;
                    return;
                }
                
                std::cout << "Тест пройден успешно" << std::endl;
            }
            else {
                std::cout << "сущность не создана" << std::endl;
                std::cout << "Тест не пройден" << std::endl;
            }
            std::cout << std::endl;
        }
        
        //
        static void B20() {
            std::cout << "Запуск теста Б20: " << std::endl;
            std::shared_ptr<UIComponent> ui(new UIComponent(0, UIComponent::Type::label, "Score: 0"));
            std::shared_ptr<TransformComponent> transform(new TransformComponent(0));
            Label entity(ui, transform);
            std::cout << "Проверка создания создания текстовой метки: ";
            if (entity.GetId()) {
                std::cout << "сущность создана" << std::endl;
                std::cout << "Проверка доступности компонент:" << std::endl;
                if (entity.GetUI()->GetId()) {
                    std::cout << "  UIComponent - доступен" << std::endl;
                }
                else {
                    std::cout << "  UIComponent - недоступен" << std::endl;
                    std::cout << "Тест не пройден" << std::endl;
                    return;
                }
                if (entity.GetTransform()->GetId()) {
                    std::cout << "  TransformComponent - доступен" << std::endl;
                }
                else {
                    std::cout << "  TransformComponent - недоступен" << std::endl;
                    std::cout << "Тест не пройден" << std::endl;
                    return;
                }
                
                std::cout << "Тест пройден успешно" << std::endl;
            }
            else {
                std::cout << "сущность не создана" << std::endl;
                std::cout << "Тест не пройден" << std::endl;
            }
            std::cout << std::endl;
        }
        
        //
        static void B21() {
            std::cout << "Запуск теста Б21: " << std::endl;
            std::shared_ptr<UIComponent> ui(new UIComponent(0, UIComponent::Type::button, "Start"));
            std::shared_ptr<TransformComponent> transform(new TransformComponent(0, Vec3d(0.2, 0.1, 0.0), Vec3d(0.8, 0.3, 0.0)));
            Label entity(ui, transform);
            std::cout << "Проверка создания создания кнопки: ";
            if (entity.GetId()) {
                std::cout << "сущность создана" << std::endl;
                std::cout << "Проверка доступности компонент:" << std::endl;
                if (entity.GetUI()->GetId()) {
                    std::cout << "  UIComponent - доступен" << std::endl;
                }
                else {
                    std::cout << "  UIComponent - недоступен" << std::endl;
                    std::cout << "Тест не пройден" << std::endl;
                    return;
                }
                if (entity.GetTransform()->GetId()) {
                    std::cout << "  TransformComponent - доступен" << std::endl;
                }
                else {
                    std::cout << "  TransformComponent - недоступен" << std::endl;
                    std::cout << "Тест не пройден" << std::endl;
                    return;
                }
                
                std::cout << "Тест пройден успешно" << std::endl;
            }
            else {
                std::cout << "сущность не создана" << std::endl;
                std::cout << "Тест не пройден" << std::endl;
            }
            std::cout << std::endl;
        }
        
        //
        static void B22() {
            std::cout << "Запуск теста Б22: " << std::endl;
            sf::Clock clock;
            ComponentManager componentManager;
            EntityManager entityManager(componentManager);
            VisualSystem visualSystem(componentManager, entityManager);
            MovementSystem movementSystem(componentManager, entityManager);
            visualSystem.Init();
            movementSystem.Init();
            auto &entity = entityManager.AddLetter(
                true,
                Vec3d(0.0f, 0.0f),
                Vec3d(0.0f, 0.0f),
                Vec3d(0.04f, 0.07f),
                Vec3d(0.0f, 1.0f, 0.1f),
                Vec3d(0.0f, 0.0f, 0.0f),
                'a',
                1
            );
            std::cout << "Проверка перемещения сущности: ..." << std::endl;
            clock.start();
            sf::Time elapsedTime = sf::milliseconds(0);
            while (elapsedTime.asSeconds() < 1.0f) {
                std::cout << elapsedTime.asSeconds() << std::endl;
                elapsedTime += clock.restart();
                movementSystem.Update();
            }
            std::cout << "Позиция сущности: Vec3d(" 
                << entity->GetTransform()->GetPosition().x << ", "
                << entity->GetTransform()->GetPosition().y << ", "
                << entity->GetTransform()->GetPosition().z << ")" << std::endl;
            if (entity->GetTransform()->GetPosition().y >= 0.1f) {
                std::cout << "Тест пройден успешно" << std::endl;
            }
            else {
                std::cout << "Тест не пройден" << std::endl;
            }
            std::cout << std::endl;
        }
    
        //
        static void Run() {
            B01(); B02(); B03(); B04(); B05();
            B06(); B07(); B08(); B09(); B10(); 
            B11(); B12(); B13(); B14(); B15(); 
            B16(); B17(); B18(); B19(); B20(); 
            B21(); //B22(); //B23(); B24(); B25(); 
        }
        
    };
}

#endif //UNIT_TESTS_TYPE_HEADER
