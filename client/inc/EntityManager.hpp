/*

*/

#ifndef ENTITY_MANAGER_TYPE_HEADER
#define ENTITY_MANAGER_TYPE_HEADER

#include "Main.hpp"

#include <unordered_map>

#include "Manager.hpp"

#include "Letter.hpp"
#include "Floor.hpp"
#include "Player.hpp"
#include "Background.hpp"
//#include "GameMode.hpp"

namespace tppo{
    class EntityManager : Manager{
        
    protected:
        //
        std::unordered_map<size_t, Letter> Letters;
        
        //
        std::unordered_map<size_t, Floor> Floors;
        
        //
        std::unordered_map<size_t, Player> Players;
        
        //
        std::unordered_map<size_t, Background> Backgrounds;
        
        //
        //std::unordered_map<size_t, GameMode> GameModes;
        
    public:
        EntityManager() {}
        ~EntityManager() {}
        
    };
}
#endif //ENTITY_MANAGER_TYPE_HEADER
