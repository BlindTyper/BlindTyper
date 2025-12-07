//
// Created by anna_ on 07.12.2025.
//

#ifndef BLINDTYPER_COMPONENTMANAGER_HPP
#define BLINDTYPER_COMPONENTMANAGER_HPP
namespace tppo{
    struct ComponentManager{
        unordered_map<size_t, TranformComponent> transformComponents;
        unordered_map<size_t, VisualComponent> visualComponents;
        unordered_map<size_t, BodyComponent> bodyComponents;
        unordered_map<size_t, SoundComponent> soundComponents;
        unordered_map<size_t, LifetimeComponent> lifetimeComponents;
        unordered_map<size_t, HealthComponent> healthComponents;
        unordered_map<size_t, MovementComponent> movementComponents;
        unordered_map<size_t, LetterComponent> letterComponents;
    };
}
#endif //BLINDTYPER_COMPONENTMANAGER_HPP
