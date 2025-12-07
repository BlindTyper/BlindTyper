//
// Created by anna_ on 07.12.2025.
//

#ifndef BLINDTYPER_SYSTEMMANAGER_HPP
#define BLINDTYPER_SYSTEMMANAGER_HPP
namespace tppo{
    struct SystemManager{
        InputSystem inputSystem;
        VisualSystem visualSystem;
        HealthSystem healthSystem;
        MovementSystem movementSystem;
        LifetimeSystem lifetimeSystem;
        CollisionSystem collisionSystem;
        AudioSystem audioSystem;
    };
}
#endif //BLINDTYPER_SYSTEMMANAGER_HPP
