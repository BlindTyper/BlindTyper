//
// Created by anna_ on 07.12.2025.
//

#ifndef BLINDTYPER_ENTITYMANAGER_HPP
#define BLINDTYPER_ENTITYMANAGER_HPP
namespace tppo{
    struct EntityManager{
        unordered_map<size_t, Letter> Letters;
        unordered_map<size_t, Floor> Floors;
        unordered_map<size_t, Player> Players;
        unordered_map<size_t, Background> Backgrounds;
        unordered_map<size_t, GameMode> GameModes;
    };
}
#endif //BLINDTYPER_ENTITYMANAGER_HPP
