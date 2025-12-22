/*

*/

#include "InputSystem.hpp"

namespace tppo {
    //
    InputSystem::InputSystem(ComponentManager &componentManager, EntityManager &entityManager)
        : System(componentManager, entityManager) {
        
    }
    
    //
    InputSystem::~InputSystem() {
        
    }
    
    //
    void InputSystem::Init() {
        
    }
    
    //
    void InputSystem::Update() {
        auto &gameModes = componentManager.GetGameModeComponents();
        for (auto &[it, gameMode] : gameModes) {
            if (!gameMode->IsActive()) {
                continue;
            }
            char key = 0;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
                key = 'a';
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::B)) {
                key = 'b';
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::C)) {
                key = 'c';
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
                key = 'd';
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E)) {
                key = 'e';
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F)) {
                key = 'f';
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::G)) {
                key = 'g';
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::H)) {
                key = 'h';
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::I)) {
                key = 'i';
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::J)) {
                key = 'j';
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::K)) {
                key = 'k';
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::L)) {
                key = 'l';
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::M)) {
                key = 'm';
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::N)) {
                key = 'n';
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::O)) {
                key = 'o';
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P)) {
                key = 'p';
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
                key = 'q';
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R)) {
                key = 'r';
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
                key = 's';
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::T)) {
                key = 't';
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::U)) {
                key = 'u';
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::V)) {
                key = 'v';
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
                key = 'w';
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::X)) {
                key = 'x';
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Y)) {
                key = 'y';
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z)) {
                key = 'z';
            }
            if (!key) {
                return;
            }
            auto &glyphs = componentManager.GetGlyphComponents();
            for (auto &[id, glyph] : glyphs) {
                if (key == glyph->GetGlyph()) {
                    entityManager.RemoveLetter(id);
                    break;
                }
            }
            
            
            break;
        }
    }
}