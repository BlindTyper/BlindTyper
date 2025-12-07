//
// Created by anna_ on 07.12.2025.
//

#ifndef BLINDTYPER_LETTER_HPP
#define BLINDTYPER_LETTER_HPP
namespace tppo{
    struct Letter{
        VisualComponent visual;
        TransformComponent transform;
        BodyComponent body;
        MovementComponent movement;
        LifetimeComponent lifetime;
        SoundComponent sound;
    };
}
#endif //BLINDTYPER_LETTER_HPP
