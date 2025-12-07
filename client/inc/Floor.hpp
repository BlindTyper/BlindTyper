//
// Created by anna_ on 07.12.2025.
//

#ifndef BLINDTYPER_FLOOR_HPP
#define BLINDTYPER_FLOOR_HPP
namespace tppo{
    struct Floor{
        VisualComponent visual;
        TransformComponent transform;
        BodyComponent body;
        Health movement;
        LifetimeComponent lifetime;
        SoundComponent sound;
    };
}
#endif //BLINDTYPER_FLOOR_HPP
