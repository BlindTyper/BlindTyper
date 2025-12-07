//
// Created by anna_ on 07.12.2025.
//

#ifndef BLINDTYPER_LIFETIMECOMPONENT_HPP
#define BLINDTYPER_LIFETIMECOMPONENT_HPP
namespace tppo{
    struct LifetimeComponent{
        bool isAlive;
        time_t creationTime;
        time_t texpirationTime;
    };
}
#endif //BLINDTYPER_LIFETIMECOMPONENT_HPP
